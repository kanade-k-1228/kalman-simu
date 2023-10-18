#include <Eigen/Eigen>

namespace Eigen {
class MeanVar {
private:
  int m_dim;
  int n;
  Eigen::VectorXd mean;
  Eigen::MatrixXd mean2;
public:
  explicit MeanVar(int dim);
  void update(Eigen::VectorXd data);
  Eigen::VectorXd getMean();
  Eigen::MatrixXd getVar();
};
}  // namespace Eigen
