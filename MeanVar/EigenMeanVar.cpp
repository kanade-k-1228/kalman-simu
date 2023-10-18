#include "EigenMeanVar.hpp"
#include <Eigen/Eigen>

namespace Eigen {
MeanVar::MeanVar(int dim) : m_dim(dim) {
  n = 0;
  mean = Eigen::VectorXd::Zero(dim);
  mean2 = Eigen::MatrixXd::Zero(dim, dim);
}
void MeanVar::update(Eigen::VectorXd data) {
  mean += data;
  mean2 += data * data.transpose();
  n++;
}
Eigen::VectorXd MeanVar::getMean() {
  return mean / n;
}
Eigen::MatrixXd MeanVar::getVar() {
  return mean2 / n - mean / n * mean.transpose() / n;
}
}  // namespace Eigen
