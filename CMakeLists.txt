# 設定cmake版本
cmake_minimum_required( VERSION 2.8 )
# 設定專案名稱
project( useEigen )

# 選擇Release模式，或可選擇Debug模式
set( CMAKE_BUILD_TYPE "Release" )
# 設定C++編譯器優化等級-O3為最高，-O0為最低
set( CMAKE_CXX_FLAGS "-O3" )

# 加入Eigen頭文件
include_directories( "/usr/include/eigen3" )
# 加入要編譯成執行檔的.cpp檔案
add_executable( Eigen_Example Eigen_Example.cpp )

