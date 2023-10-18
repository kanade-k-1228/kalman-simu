#include "../LSS/LSSmodel.hpp"
#include "LKF.hpp"
#include <bits/stdc++.h>

const int T = 100;

std::string textOut(LSS::state real, LKF::state est, LKF::state pre) {
  std::string ret = "";
  std::string pnc = ", ";
  for(int i = 0; i < real.y.size(); i++)
    ret += std::to_string(real.y(i)) + pnc;
  for(int i = 0; i < real.x.size(); i++)
    ret += std::to_string(real.x(i)) + pnc;
  for(int i = 0; i < est.x.size(); i++)
    ret += std::to_string(est.x(i)) + pnc;
  for(int i = 0; i < pre.x.size(); i++)
    ret += std::to_string(pre.x(i)) + pnc;
  ret += "\n";
  return ret;
}

int main(int argc, char* argv[]) {
  int dim_x = 2, dim_y = 1, dim_w = 1;
  Eigen::MatrixXd F = Eigen::MatrixXd::Identity(dim_x, dim_x);
  F << 1, 1, 0, 1;
  Eigen::MatrixXd G = Eigen::MatrixXd::Identity(dim_x, dim_w);
  G << 0.5, 1;
  Eigen::MatrixXd H = Eigen::MatrixXd::Identity(dim_y, dim_x);
  H << 0, 1;
  Eigen::MatrixXd Q = Eigen::MatrixXd::Identity(dim_w, dim_w);
  Q << 10;
  Eigen::MatrixXd R = Eigen::MatrixXd::Identity(dim_y, dim_y);
  R << 50;

  Eigen::VectorXd x0 = Eigen::VectorXd::Zero(dim_x);
  LKF::state est0;
  est0.x = Eigen::VectorXd::Zero(dim_x);
  est0.P = Eigen::MatrixXd::Zero(dim_x, dim_x);
  std::string filename = "data";
  if(argc > 1)
    filename = argv[1];
  std::ofstream file;
  file.open(filename);
  LSS::model realmodel(dim_x, dim_y, dim_w, F, G, H, Q, R);
  LKF::filter filtermodel(dim_x, dim_y, dim_w, F, G, H, Q, R);

  file << textOut(realmodel.initState(x0), filtermodel.initState(est0), est0);
  for(int i = 0; i < T; i++) {
    realmodel.timeDevelop();
    filtermodel.estimate(realmodel.getState().y);
    file << textOut(realmodel.getState(), filtermodel.getEst(), filtermodel.getPre());
    filtermodel.predict();
  }

  file.close();
  return 0;
}
