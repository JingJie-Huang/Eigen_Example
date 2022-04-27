#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

using namespace std;

/****************************
 * 本程式演示了 Eigen 基本類型的使用
 ****************************/

int main(int argc, char **argv)
{
     // Eigen 中所有向量和矩陣都是Eigen::Matrix，它是一个模板類。它的前三个參數為：数劇類型，列(row)，行(column)
     // 宣告一個2*3的float矩陣
     Eigen::Matrix<float, 2, 3> matrix_23;

     // 例如 Vector3d 實值上是 Eigen::Matrix<double, 3, 1>，即三维向量
     Eigen::Vector3d vector_3d;
     // 宣告float型式的向量
     Eigen::Matrix<float, 3, 1> vector_3f;

     // Matrix3d 實質上是 Eigen::Matrix<double, 3, 3>
     Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); //初始化為零
     // 如果不確定矩陣大小，可以使用動態大小的矩陣
     Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;

     // 下面是對Eigen矩陣的操作
     // 輸入數據（初始化）
     matrix_23 << 1, 2, 3,
         4, 5, 6;
     // 輸出
     cout << "matrix_23:" << endl
          << matrix_23 << endl << endl;

     // 用()訪問矩陣中的元素
     cout << "matrix_23:" << endl;
     for (int i = 0; i < 2; i++)
     {
          for (int j = 0; j < 3; j++)
               cout << matrix_23(i, j) << "\t";
          cout << endl;
     }
     cout << endl;

     // 矩陣和向量相乘（實際上是矩陣和矩陣運算）
     vector_3d << 3, 2, 1;
     vector_3f << 4, 5, 6;
     // 但是在Eigen里不能混合兩種不同類型的矩陣，像以下是錯誤的示範
     // Eigen::Matrix<double, 2, 1> result_wrong_type = matrix_23 * vector_3f;
     // 要進行顯式轉換
     Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * vector_3d;
     cout << "result:" << endl
          << result << endl
          << endl;

     Eigen::Matrix<float, 2, 1> result2 = matrix_23 * vector_3f;
     cout << "result2" << endl
          << result2 << endl
          << endl;

     // 矩陣運算需要注意的維度
     // 試著取消下面的注解，看看Eigen會輸出什么錯誤
     // Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * vector_3d;

     // 重新給與matrix_33初始值
     matrix_33 << 2, -1, 3,
         4, 2, -5,
         1, 2, 8;
     cout << "matrix_33:" << endl
          << matrix_33 << endl
          << endl;

     cout << "matrix_33.transpose():" << endl
          << matrix_33.transpose() << endl
          << endl; // 轉置
     cout << "10 * matrix_33:" << endl
          << 10 * matrix_33 << endl
          << endl; // 乘上數值
     cout << "matrix_33.inverse():" << endl
          << matrix_33.inverse() << endl
          << endl; // 逆矩陣
     cout << "matrix_33.determinant():" << endl
          << matrix_33.determinant() << endl
          << endl; // 行列式

     return 0;
}
