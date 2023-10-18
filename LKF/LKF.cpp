#include "LKF.hpp"
#include <Eigen/Eigen>
#include <iostream>

namespace LKF {

filter::filter(int dim_x, int dim_y, int dim_w, Eigen::MatrixXd F, Eigen::MatrixXd G, Eigen::MatrixXd H, Eigen::MatrixXd Q, Eigen::MatrixXd R) : m_dim_x(dim_x), m_dim_y(dim_y), m_dim_w(dim_w), m_F(F), m_G(G), m_H(H), m_Q(Q), m_R(R) {
  pre.x = Eigen::VectorXd(m_dim_x);
  pre.P = Eigen::MatrixXd(m_dim_x, m_dim_x);
}

state filter::initState(state first) {
  est.x = first.x;
  est.P = first.P;
  return est;
}

state filter::predict() {
  pre.x = m_F * est.x;
  pre.P = m_F * est.P * m_F.transpose() + m_G * m_Q * m_G.transpose();
  return pre;
}

state filter::estimate(Eigen::VectorXd y) {
  K = pre.P * m_H.transpose() * (m_R + m_H * pre.P * m_H.transpose()).inverse();
  est.x = pre.x + K * (y - m_H * pre.x);
  est.P = (Eigen::MatrixXd::Identity(m_dim_x, m_dim_x) - K * m_H) * pre.P;
  return est;
}

state filter::getEst() {
  return est;
}
state filter::getPre() {
  return pre;
}

}  // namespace LKF
