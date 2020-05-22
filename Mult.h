#pragma once
#include "Vector.h"
#include "Matrix.h"
template <class T>
Matrix<T> operator *(Vector<T>& vector, Matrix<T>& matrix)
{
	if (matrix.GetM() == vector.GetN() && matrix.GetN() == 1)
	{
		T** arr = new T * [matrix.GetM()];
		for (int i = 0; i < vector.GetN(); i++)
			arr[i] = new T[vector.GetN()];
		Matrix<T> result(matrix.GetM(), vector.GetN(), arr);

		for (int i = 0; i < result.GetN(); i++)

			for (int j = 0; j < result.GetM(); j++)
			{
				result.SetI(i, j, matrix[0][j] * vector[i]);
			}

		for (int i = 0; i < vector.GetN(); i++)
			delete[] arr[i];
		delete[] arr;
		return result;
	}
	else
		throw - 1;
};
template <class T>
Vector<T> operator *(Matrix<T>& matrix, Vector<T>& vector)
{
	if (matrix.GetN() == vector.GetN())
	{
		T* arr = new T[matrix.GetM()];
		Vector<T> result(matrix.GetM(), arr);


		for (int i = 0; i < result.GetN(); i++)
		{
			result.SetI(i, 0);
			for (int j = 0; j < vector.GetN(); j++)
			{
				result.SetI(i, result[i] + (matrix[i][j] * vector[j]));

			}
		}
		delete[] arr;
		return result;
	}
	else
		throw - 1;
};