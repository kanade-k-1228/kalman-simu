#include <Eigen/Eigen>

namespace LKF {
struct state {
  Eigen::VectorXd x;
  Eigen::MatrixXd P;
};
class filter {
private:
  int m_dim_x, m_dim_y, m_dim_w;
  Eigen::MatrixXd m_F;
  Eigen::MatrixXd m_G;
  Eigen::MatrixXd m_H;
  Eigen::MatrixXd m_Q;
  Eigen::MatrixXd m_R;
  state pre;
  state est;
  Eigen::MatrixXd K;
public:
  explicit filter(int dim_x, int dim_y, int dim_w, Eigen::MatrixXd F, Eigen::MatrixXd G, Eigen::MatrixXd H, Eigen::MatrixXd Q, Eigen::MatrixXd R);
  state initState(state first);
  state predict();
  state estimate(Eigen::VectorXd y);
  state getEst();
  state getPre();
};
}  // namespace LKF
