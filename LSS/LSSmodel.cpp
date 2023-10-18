#include "LSSmodel.hpp"
#include "../MVN/EigenMVN.hpp"
#include <Eigen/Eigen>

namespace LSS {

model::model(int dim_x, int dim_y, int dim_w, Eigen::MatrixXd F, Eigen::MatrixXd G, Eigen::MatrixXd H, Eigen::MatrixXd Q, Eigen::MatrixXd R) : m_dim_x(dim_x), m_dim_y(dim_y), m_dim_w(dim_w), m_F(F), m_G(G), m_H(H), m_Q(Q), m_R(R) {}

state model::initState(Eigen::VectorXd x0) {
  A.x = x0;
  A.y = Eigen::VectorXd::Zero(m_dim_y);
  A.w = Eigen::VectorXd::Zero(m_dim_w);
  A.v = Eigen::VectorXd::Zero(m_dim_y);
  return A;
}

state model::timeDevelop() {
  Eigen::VectorXd mean_w = Eigen::VectorXd::Zero(m_dim_w);
  A.w = Eigen::MVN(m_dim_w, mean_w, m_Q);
  Eigen::VectorXd mean_y = Eigen::VectorXd::Zero(m_dim_y);
  A.v = Eigen::MVN(m_dim_y, mean_y, m_R);
  A.x = m_F * A.x + m_G * A.w;
  A.y = m_H * A.x + A.v;
  return A;
}

state model::getState() {
  return A;
}

}  // namespace LSS
