
#include <iostream>
using namespace std; 
#include "Mult.h"
#include "Vector.h"
#include "Matrix.h"


int main()
{
	//Matrix<int>A;
	Matrix<int>B(3, 3);
	cout << B << endl;
	Vector<int>a1(3),a2(5);
	cout << a1 << endl;
	cout << (a1 == a2) << endl;
	//a2 = a1;
	//cout << a2 << endl;
	int type;
	cout << "(1) int    " << "(2) float   " << "(3) double " << endl << "Select type: ";
	cin >> type;
	switch (type)
	{
	case (1):
	{
		Vector<int> V1, V2, V3;
		Matrix<int> M1, M2, M3;
		int Scalar;
		int type2;
		cout << "(1) v + v" << endl << "(2) v - v" << endl << "(3)  v * v" <<
			endl << "(4)  m + m" << endl << "(5)  m - m" << endl << "(6)  m * mx" <<
			endl << "(7)  v * m" << endl << "(8)  m * v" << endl << "Select: ";
		cin >> type2;
		switch (type2)
		{
		case (1):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			V3 = V1 + V2;
			cout << V1 << " + " << V2 << " = " << V3 << endl;
			break;
		case (2):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			V3 = V1 - V2;
			cout << V1 << " - " << V2 << " = " << V3 << endl;
			break;
		case (3):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			Scalar = V1 * V2;
			cout << V1 << " * " << V2 << " = " << Scalar << endl;
			break;
		case (4):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 + M2;
			cout << M1 << endl << " + " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (5):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 - M2;
			cout << M1 << endl << " - " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (6):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 * M2;
			cout << M1 << endl << " * " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (7):
			cout << "Input vector" << endl;
			cin >> V1;
			cout << "Input matrix" << endl;
			cin >> M2;
			M3 = V1 * M2;
			cout << V1 << endl << " * " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (8):
			cout << "Input matrix" << endl;
			cin >> M1;
			cout << "Input vector" << endl;
			cin >> V2;
			V3 = M1 * V2;
			cout << M1 << endl << " * " << endl << V2 << endl << " = " << endl << V3 << endl;
			break;
		}
	}
	break;
	case(2):
	{
		Vector<float> V1, V2, V3;
		Matrix<float> M1, M2, M3;
		float Scalar;
		int type2;
		cout << "(1) v + v" << endl << "(2) v - v" << endl << "(3)  v * v" <<
			endl << "(4)  m + m" << endl << "(5)  m - m" << endl << "(6)  m * mx" <<
			endl << "(7)  v * m" << endl << "(8)  m * v" << endl << "Select: ";
		cin >> type2;
		switch (type2)
		{
		case (1):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			V3 = V1 + V2;
			cout << V1 << " + " << V2 << " = " << V3 << endl;
			break;
		case (2):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			V3 = V1 - V2;
			cout << V1 << " - " << V2 << " = " << V3 << endl;
			break;
		case (3):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			Scalar = V1 * V2;
			cout << V1 << " * " << V2 << " = " << Scalar << endl;
			break;
		case (4):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 + M2;
			cout << M1 << endl << " + " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (5):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 - M2;
			cout << M1 << endl << " - " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (6):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 * M2;
			cout << M1 << endl << " * " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (7):
			cout << "Input vector" << endl;
			cin >> V1;
			cout << "Input matrix" << endl;
			cin >> M2;
			M3 = V1 * M2;
			cout << V1 << endl << " * " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (8):
			cout << "Input matrix" << endl;
			cin >> M1;
			cout << "Input vector" << endl;
			cin >> V2;
			V3 = M1 * V2;
			cout << M1 << endl << " * " << endl << V2 << endl << " = " << endl << V3 << endl;
			break;
		}
	}
	break;






	case(3):
	{
		Vector<double> V1;
		Vector<double> V2;
		Vector<double> V3;
		Matrix<double> M1;
		Matrix<double> M2;
		Matrix<double> M3;
		double Scalar;
		int type2;
		cout << "(1) v + v" << endl << "(2) v - v" << endl << "(3)  v * v" <<
			endl << "(4)  m + m" << endl << "(5)  m - m" << endl << "(6)  m * mx" <<
			endl << "(7)  v * m" << endl << "(8)  m * v" << endl << "Select: ";
		cin >> type2;
		switch (type2)
		{
		case (1):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			V3 = V1 + V2;
			cout << V1 << " + " << V2 << " = " << V3 << endl;
			break;
		case (2):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			V3 = V1 - V2;
			cout << V1 << " - " << V2 << " = " << V3 << endl;
			break;
		case (3):
			cout << "Input 1 vector" << endl;
			cin >> V1;
			cout << "Input 2 vector" << endl;
			cin >> V2;
			Scalar = V1 * V2;
			cout << V1 << " * " << V2 << " = " << Scalar << endl;
			break;
		case (4):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 + M2;
			cout << M1 << endl << " + " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (5):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 - M2;
			cout << M1 << endl << " - " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (6):
			cout << "Input 1 matrix" << endl;
			cin >> M1;
			cout << "Input 2 matrix" << endl;
			cin >> M2;
			M3 = M1 * M2;
			cout << M1 << endl << " * " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (7):
			cout << "Input vector" << endl;
			cin >> V1;
			cout << "Input matrix" << endl;
			cin >> M2;
			M3 = V1 * M2;
			cout << V1 << endl << " * " << endl << M2 << endl << " = " << endl << M3 << endl;
			break;
		case (8):
			cout << "Input matrix" << endl;
			cin >> M1;
			cout << "Input vector" << endl;
			cin >> V2;
			V3 = M1 * V2;
			cout << M1 << endl << " * " << endl << V2 << endl << " = " << endl << V3 << endl;
			break;
		}
	}
	break;
	default:
		throw - 1;
	}

	/*
	double  t = clock();
	double seconds = clock() - t;
	cout << seconds;

	*/


	return 0;
}


