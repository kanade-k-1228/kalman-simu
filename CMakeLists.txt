cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -g -static")

project(kalman-simu CXX)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# add_executable(MVN 
#     MVN/EigenMVN_test.cpp
#     MVN/EigenMVN.cpp
#     MeanVar/EigenMeanVar.cpp
# )
# target_link_libraries(MVN Eigen3::Eigen)

# add_executable(LSS 
#     LSS/LSSmodel_test.cpp
#     LSS/LSSmodel.cpp
#     MVN/EigenMVN.cpp
#     MeanVar/EigenMeanVar.cpp
# )
# target_link_libraries(LSS Eigen3::Eigen)

add_executable(LKF 
    LKF/LKF_test.cpp
    LKF/LKF.cpp
    LSS/LSSmodel.cpp
    MVN/EigenMVN.cpp
    MeanVar/EigenMeanVar.cpp
)
target_link_libraries(LKF Eigen3::Eigen)
