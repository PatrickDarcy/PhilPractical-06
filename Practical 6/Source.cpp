#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "MyMatrix3.h"
#include "MyVector3.h"
#include <iostream>
#define PI           3.14159265358979323846


/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	double number = 3;
	MyVector3 vector1 = { 2,2,2 };
	MyVector3 vector2 = { 5,6,0 };
	MyVector3 vector3 = { 2,1,1 };

	MyMatrix3 matrix1{};
	MyMatrix3 matrix2(1, 2, 3, 4, 5, 6, 7, 8, 9);
	MyMatrix3 matrix3(1, 1, 1, 1, 1, 1, 1, 1, 1);
	MyMatrix3 matrix4(2, 2, 2, 2, 2, 2, 2, 2, 2);
	MyMatrix3 matrix5(3, -1, 1, -15, 6, -5, 5, -2, 2);
	MyMatrix3 matrix6{};

	bool checkForEquality = { matrix1 == matrix1 };
	bool checkForInequality = { matrix1 == matrix2 };

	std::cout << matrix1.toString() << std::endl;
	std::cout << "[0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]" << std::endl;
	std::cout << "Null Matrix" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << std::to_string(checkForEquality) << std::endl;
	std::cout << "1" << std::endl;
	std::cout << "Matrix Equality" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << std::to_string(checkForInequality) << std::endl;
	std::cout << "0" << std::endl;
	std::cout << "Matrix Inequality" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.operator+(matrix3).toString() << std::endl;
	std::cout << "[2,3,4,5,6,7,8,9,10]" << std::endl;
	std::cout << "Addition" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.operator-(matrix3).toString() << std::endl;
	std::cout << "[0,1,2,3,4,5,6,7,8]" << std::endl;
	std::cout << "Subtracting" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.operator*(matrix4).toString() << std::endl;
	std::cout << "[2,4,6,8,10,12,14,16,18]" << std::endl;
	std::cout << "Multiplying by a Matrix" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.operator*(vector1).toString() << std::endl;
	std::cout << "[12,30,48]" << std::endl;
	std::cout << "Vector Multiplication" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.operator*(number).toString() << std::endl;
	std::cout << "[3,6,9,12,15,18,21,24,27]" << std::endl;
	std::cout << "Scalar Multiplication" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.transpose().toString() << std::endl;
	std::cout << "[1,4,7,2,5,8,3,6,9]" << std::endl;
	std::cout << "The Transpose" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix5.determinant() << std::endl;
	std::cout << "1" << std::endl;
	std::cout << "The Determinant" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix5.inverse().toString() << std::endl;
	std::cout << "[2, 0, -1, 5, 1, 0, 0, 1, 3]" << std::endl;
	std::cout << "The Inverse" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.row(0).toString() << std::endl;
	std::cout << "1, 2, 3" << std::endl;
	std::cout << "View Specific Rows" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << matrix2.column(1).toString() << std::endl;
	std::cout << "2, 5, 8" << std::endl;
	std::cout << "View Specific Columns" << std::endl;
	std::cout << "-------------------------" << std::endl;

	MyVector3 rotatedX = MyMatrix3::rotationX(PI / 2.0) * vector1;
	std::cout << rotatedX.toString() << std::endl;
	std::cout << "[2,-2,2]" << std::endl;;
	std::cout << "Rotating on the x axis" << std::endl;
	std::cout << "-------------------------" << std::endl;

	MyVector3 rotatedY = MyMatrix3::rotationY(PI / 2.0) * vector1;
	std::cout << rotatedY.toString() << std::endl;
	std::cout << "[2,2,-2]" << std::endl;;
	std::cout << "Rotating on the y axis" << std::endl;
	std::cout << "-------------------------" << std::endl;

	MyVector3 rotatedZ = MyMatrix3::rotationZ(PI / 2.0) * vector1;
	std::cout << rotatedZ.toString() << std::endl;
	std::cout << "[-2,2,2]" << std::endl;
	std::cout << "Rotating on the z axis" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrix6 = MyMatrix3::translation(vector2);
	std::cout << (matrix6 * vector3).toString() << std::endl;
	std::cout << "[7,7,1]" << std::endl;
	std::cout << "Translation" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrix2 = MyMatrix3::scale(3);
	std::cout << (matrix2 * matrix5).toString() << std::endl;
	std::cout << "[9,0,0,0,18,0,0,6]" << std::endl;
	std::cout << "Scale" << std::endl;
	std::cout << "-------------------------" << std::endl;

	system("pause");
	return 0;
}