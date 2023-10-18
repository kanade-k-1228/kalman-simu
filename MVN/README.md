# Generate MVN

- 多変数正規分布 (MVN : MultiVariariate Normal distribution) に従うベクトルを生成
- 参考 : https://qiita.com/takahiro_hasegawa/items/c17c27909f74fee0eeb5

| name                                                 | func                                      |
| ---------------------------------------------------- | ----------------------------------------- |
| Eigen::VectorXd MVN(int n)                           | N_n(0, I)                                 |
| Eigen::VectorXd MVN(int n, VectorXd& m, MatrixXd& s) | N_n(n dim vector, (n,n)covariance matrix) |
