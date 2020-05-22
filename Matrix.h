#pragma once
#include <iostream>
using namespace std;
#include "Vector.h"

template<class T>
class Matrix
{
protected:
	T** matr;
  int w;
  int l;
public:
  // онструторы
  Matrix();
  Matrix(int _w, int _l);
  Matrix(const Matrix& M);
	~Matrix();

	//
  T GetM(int i, int j);
	T SetM(int i, int j, T val);

	//перегрузки
	Matrix<T> operator=(const Matrix<T>& M);
	bool operator==(const Matrix<T>& M);
	T*& operator[](const int _n);
	Matrix<T> operator+(const Matrix<T>& M);
	Matrix<T> operator-(const Matrix<T>& M);
	Matrix<T> operator*(const Matrix<T>& M);

	template<class T>
	friend ostream& operator<<(ostream& os, const Matrix<T>& mat);
	template<class T>
	friend istream& operator>>(istream& in, Matrix<T>& mat);

};


template<class T>
Matrix<T>::Matrix()
{
	w = 0;
	l = 0;
}
template<class T>
Matrix<T>::Matrix(int _w, int _l)
{
	w = _w;
	l = _l;
	matr = new T * [w];
	for (int i = 0; i < w; i++)
		matr[i] = new T[l];
	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			matr[i][j] = 0;
}
template<class T>
Matrix<T>::Matrix(const Matrix<T>& M)
{
	w = M.w;
	l = M.l;
	matr = (T**) new T * [w];
	for (int i = 0; i < l; i++)
		matr[i] = (T*) new T[l];
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			matr[i][j] = M.matr[i][j];
}
template <class T>
Matrix<T>::~Matrix()
{
	if (l > 0)
	{
		// освободить выделенную пам€ть дл€ каждой строки
		for (int i = 0; i < w; i++)
			delete[] matr[i];
	}

	if (w > 0)
		delete[] matr;
}
////////////////////////////////////////////////////////////////////////
template<class T>
T Matrix<T>::GetM(int i, int j)
{
if ((w >= i) && (l >= j) && (i >= 0) && (j >= 0))
		return matr[i][j];
	else
		return 0;
}
template<class T>
T Matrix<T>::SetM(int i, int j, T val)
{
	if ((w >= i) && (l >= j)&&(i>=0)&&(j>=0))
		matr[i][j] = val;
}
template<class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& M)
{
	if (*this == M)
		return *this;
	for (int i = 0; i < w; i++)
		delete[] matr[i];
	delete[] matr;
	this->w = M.w;
	this->l = M.l;
	matr = new T * [w];
	for (int i = 0; i < w; i++)
		matr[i] = new T[l];
	for (int i = 0; i < w; i++)
		for (int j = 0; j < l; j++)
			matr[i][j] = M.matr[i][j];
	return *this;
}
template <class T>
bool Matrix<T>::operator==(const Matrix<T>& M)
{
	if (w == M.w && l == M.l)
	{

		for (int i = 0; i < w; i++)
			for (int j = 0; j < l; j++)
				if (matr[i][j] != M.matr[i][j])
					return false;
		return true;
	}
	else
		return false;
}
template <class T>
T*& Matrix<T>::operator[](const int _n)
{
	return matr[_n];
}
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& M)
{
	if (w == M.w && l == M.l)
	{
		Matrix<T> Ex(w, l, M.matr);
		for (int i = 0; i < w; i++)
			for (int j = 0; j < l; j++)
				Ex.matr[i][j] = M.matr[i][j] + matr[i][j];
		return Ex;
	}
	else
		throw - 1;
}
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& M)
{
	if (w == M.w && l == M.l)
	{
		Matrix<T> Ex(w, l, M.matr);
		for (int i = 0; i < w; i++)
			for (int j = 0; j < l; j++)
				Ex.matr[i][j] = M.matr[i][j] - matr[i][j];
		return Ex;
	}
	else
		throw - 1;
}
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& M)
{
	if (this->l == M.w)
	{
		Matrix<T> Ex;
		Ex.w = this->w;
		Ex.l = M.l;
		Ex.matr = new T * [Ex.w];
		for (int i = 0; i < Ex.w; i++)
			Ex.matr[i] = new T[Ex.l];

		for (int i = 0; i < Ex.w; i++)
			for (int j = 0; j < Ex.l; j++)
			{
				Ex.matr[i][j] = 0;
				for (int k = 0; k < this->l; k++)
				{
					Ex.matr[i][j] = Ex.matr[i][j] + (matr[i][k] * M.matr[k][j]);
				}
			}
		return Ex;
	}
	else
		throw - 1;
}

template<class T>
ostream& operator<<(ostream& os, const Matrix<T>& mat)
{
	for (int i = 0; i < mat.w; i++)
	{
		if (i > 0) os << endl;
		os << "|";
		for (int j = 0; j < mat.l; j++)
			os << mat.matr[i][j] << " ";
		os << "|";
	}
	return os;
}

template<class T>
istream& operator>>(istream& in, Matrix<T>& mat)
{

	for (int i = 0; i < mat.w; i++)
		delete[] mat.matr[i];
	delete[] mat.matr;

	cout << "Enter size" << endl << "weight = ";
	in >> mat.w;
	cout << "long = ";
	in >> mat.l;
	T** temp;
	temp = new T * [mat.w];
	for (int i = 0; i < mat.w; i++)
		temp[i] = new T[mat.l];


	for (int i = 0; i < mat.w; i++)
	{
		cout << "Enter " << i + 1 << " line" << endl;
		for (int j = 0; j < mat.l; j++)
			in >> temp[i][j];
	}

	mat.matr = new T * [mat.w];
	for (int i = 0; i < mat.w; i++)
		mat.matr[i] = new T[mat.l];

	for (int i = 0; i < mat.w; i++)
		for (int j = 0; j < mat.l; j++)
			mat.SetM(i, j, temp[i][j]);

	for (int i = 0; i < mat.w; i++)
		delete[] temp[i];
	delete[] temp;
	return in;
}
