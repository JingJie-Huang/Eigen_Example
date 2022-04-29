#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <cmath>

using namespace std;

/****************************
 * 本程式演示了 Eigen 基本類型的使用
 ****************************/

int main(int argc, char **argv)
{
    // Eigen 中所有向量和矩陣都是Eigen::Matrix，它是一个模板類。它的前三个參數為：数劇類型，列(row)，行(column)
    // 宣告矩陣PA為一個2*1的float矩陣
    Eigen::Matrix<float, 2, 1> PA;
    // 宣告矩陣PB為一個2*1的float矩陣
    Eigen::Matrix<float, 2, 1> PB;
    // 宣告矩陣R_AB為一個2*2的float矩陣
    Eigen::Matrix<float, 2, 2> R_AB;
    // 宣告矩陣tA為一個2*1的float矩陣
    Eigen::Matrix<float, 2, 1> tA;

    // 定義旋轉角度 (單位是度)
    float angle = 45;
    // 度轉換成徑度(radian)
    float rad2deg = M_PI / 180.0;
    // 將旋轉角度轉換成徑度
    angle = angle * rad2deg;

    // 給予R_AB矩陣初始值
    R_AB << cos(angle), -sin(angle),
        sin(angle), cos(angle);
    // 顯示R_AB矩陣
    cout << "R_AB:" << endl
         << R_AB << endl
         << endl;
    // 給予PB矩陣初始值
    PB << 2.0, 1.0;
    // 給予tA矩陣初始值
    tA << 0, -sqrt(2);
    // 求解PA: 假設R_AB, PB, tA為已知
    // 計算PA 根據公式： PA = R_AB*PB + tA
    PA = R_AB * PB + tA;
    // 顯示PA矩陣
    cout << "PA:" << endl
         << PA << endl
         << endl;

    // 求解PB: 假設R_AB, PA, tA為已知
    // 計算PB 根據公式： PB = R_AB^(-1) * (PA - tA)
    PB = R_AB.inverse() * (PA - tA);
    // 顯示PB矩陣
    cout << "PB:" << endl
         << PB << endl
         << endl;

    // 旋轉矩陣R_AB的逆矩陣等於旋轉矩陣R_AB的轉置矩陣
    // 亦即： R_AB^(-1) = R_AB^(T)
    // 顯示R_AB的逆矩陣
    cout << "inverse matrix of R_AB:" << endl
        << R_AB.inverse() << endl
        << endl;

    // 顯示R_AB的轉置矩陣
    cout << "transpose matrix of R_AB:" << endl
         << R_AB.transpose() << endl
         << endl;


    return 0;
}
