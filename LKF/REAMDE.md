# 線形カルマンフィルタ
* x = Fx + Gw (w~N(0,Q))
* y = Hx + v (v~N(0,R))


# include
* EigenMVN (多変数正規分布)
* https://gist.github.com/kanade-k-1228/d3f6959259cf96b26cb79dab7e0e79a2
* LSS (線形状態空間モデル)
* https://gist.github.com/kanade-k-1228/0121d930b180673b0d42d6115c6c6d1b

# Test
* ./LKF_test.sh [datafile]
* 直線上を移動する物体
* 参考 : https://ja.wikipedia.org/wiki/%E3%82%AB%E3%83%AB%E3%83%9E%E3%83%B3%E3%83%95%E3%82%A3%E3%83%AB%E3%82%BF%E3%83%BC#%E8%A8%AD%E5%AE%9A%E4%BE%8B