#include <Eigen/Eigen>

namespace Eigen {
// Mean=0 std=I
VectorXd MVN(int n);
// mean=m std=s
VectorXd MVN(int n, VectorXd& m, MatrixXd& s);
}  // namespace Eigen
