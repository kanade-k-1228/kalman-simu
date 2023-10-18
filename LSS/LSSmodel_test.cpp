#include "LSSmodel.hpp"
#include <bits/stdc++.h>

std::string textOut(LSS::state A) {
  std::string ret = "";
  std::string pnc = ", ";
  for(auto i : A.x)
    ret += std::to_string(i) + pnc;
  for(auto i : A.y)
    ret += std::to_string(i) + pnc;
  for(auto i : A.v)
    ret += std::to_string(i) + pnc;
  for(auto i : A.w)
    ret += std::to_string(i) + pnc;
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
  Q << 1;
  Eigen::MatrixXd R = Eigen::MatrixXd::Identity(dim_y, dim_y);
  R << 1;

  Eigen::VectorXd x0 = Eigen::VectorXd::Zero(dim_x);
  int T = 100;

  std::string filename = (argc >= 1 ? argv[1] : "data");
  std::ofstream file;
  file.open(filename);

  LSS::model testmodel(dim_x, dim_y, dim_w, F, G, H, Q, R);
  testmodel.initState(x0);
  file << textOut(testmodel.getState());
  for(int i = 0; i < T; i++) {
    testmodel.timeDevelop();
    file << textOut(testmodel.getState());
  }

  file.close();
  return 0;
}