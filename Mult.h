#pragma once
#include "Vector.h"
#include "Matrix.h"
template <class T>
Matrix<T> operator *(Vector<T>& vector, Matrix<T>& matrix)
{
	if ((matrix.GetL() == vector.GetW()))
	{
		T** arr = new T * [matrix.GetL()];
		for (int i = 0; i < vector.GetW(); i++)
			arr[i] = new T[vector.GetW()];
		Matrix<T> result(matrix.GetL(), vector.GetW(), arr);

		for (int i = 0; i < result.GetW(); i++)

			for (int j = 0; j < result.GetL(); j++)
			{
				result.SetI(i, j, matrix[0][j] * vector[i]);
			}

		for (int i = 0; i < vector.GetW(); i++)
			delete[] arr[i];
		delete[] arr;
		return result;
	}
};
template <class T>
Vector<T> operator *(Matrix<T>& matrix, Vector<T>& vector)
{
	if (matrix.GetW() == vector.GetW())
	{
		T* arr = new T[matrix.GetL()];
		Vector<T> result(matrix.GetL(), arr);


		for (int i = 0; i < result.GetW(); i++)
		{
			result.SetI(i, 0);
			for (int j = 0; j < vector.GetW(); j++)
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