#include <Eigen/Eigen>

namespace LSS {
class state {
public:
  Eigen::VectorXd x;
  Eigen::VectorXd y;
  Eigen::VectorXd v;
  Eigen::VectorXd w;
};
class model {
private:
  int m_dim_x, m_dim_y, m_dim_w;
  Eigen::MatrixXd m_F;
  Eigen::MatrixXd m_G;
  Eigen::MatrixXd m_H;
  Eigen::MatrixXd m_Q;
  Eigen::MatrixXd m_R;
  state A;
public:
  explicit model(int dim_x, int dim_y, int dim_w, Eigen::MatrixXd F, Eigen::MatrixXd G, Eigen::MatrixXd H, Eigen::MatrixXd Q, Eigen::MatrixXd R);
  state initState(Eigen::VectorXd x0);
  state timeDevelop();
  state getState();
};
}  // namespace LSS
