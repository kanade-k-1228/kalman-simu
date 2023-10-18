#include "EigenMVN.hpp"
#include <Eigen/Eigen>
#include <random>

namespace Eigen {
VectorXd MVN(int n) {
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::normal_distribution<double> gen(0, 1);
  VectorXd x(n);
  for(int i = 0; i < n; i++)
    x(i) = gen(engine);
  return x;
}
VectorXd MVN(int n, VectorXd& mean, MatrixXd& std) {
  LLT<MatrixXd> CholD(std);
  MatrixXd L = CholD.matrixL();
  return L * MVN(n) + mean;
}
}  // namespace Eigen
