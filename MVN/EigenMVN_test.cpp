#include "../MeanVar/EigenMeanVar.hpp"
#include "EigenMVN.hpp"
#include <Eigen/Eigen>
#include <iostream>

int main() {
  int dim = 3;
  int n = 100000;
  Eigen::VectorXd m(dim);
  m << 1, 2, 3;
  Eigen::MatrixXd s = Eigen::MatrixXd::Zero(dim, dim);
  s << 1, 0.3, 0.1,
      0.3, 1, 0.3,
      0.1, 0.3, 1;

  Eigen::LLT<Eigen::MatrixXd> CholD(s);
  Eigen::MatrixXd L = CholD.matrixL();
  std::cout << "\ns.L\n"
            << L << "\n\ns.L*s.L.t\n"
            << L * L.transpose();

  Eigen::VectorXd x;
  Eigen::MeanVar statical(dim);

  for(int i = 0; i < n; i++) {
    x = Eigen::MVN(dim, m, s);
    statical.update(x);
  }
  std::cout << "\nmean:\n"
            << statical.getMean()
            << "\n\nvariance:\n"
            << statical.getVar()
            << std::endl;

  return 0;
}
