#pragma once
#include "Matrix.h"
#include <time.h>
#include <iostream>
using namespace std;

template<class T>
class Vector : public Matrix<T>
{
protected:
	int N;
	T* arr;
public:
	//Констр
	Vector() :Matrix<T>() {}
	Vector(int l);
	Vector(const Vector& V);
	Vector(int size, const T* arr_);
	~Vector();
	//sorts
	void Bubble_sort();
	void Insertion_sort();
	void Quick_sort(int first, int last);
	//перегр
	Vector<T> operator = (const Vector<T>& other); 
	bool operator ==(const Vector<T>& other);
	T operator [](const int i);
	Vector<T> operator+(const Vector<T>& other);//
	Vector<T> operator-(const Vector<T>& other);
	T operator*(const Vector<T>& other);
	template <class T>
	friend ostream& operator<<(ostream& os, const Vector<T>& vec);
	template <class T>
	friend istream& operator>>(istream& in, Vector<T>& vec);


};
template<class T>
Vector<T>::Vector(int _N)
{
	N = _N;
	arr = new int[N];
	for (int i = 0; i < N; i++)
		arr[i] = 0;
}
template<class T>
Vector<T>::Vector(int size, const T* arr_)
{
	N = size;
	arr = new T[N];
	for (int i = 0; i < N; i++)
		arr[i] = arr_[i];
}

template<class T>
Vector<T>::Vector(const Vector<T>& V)
{
	N = V.N;
	arr = new T[N];
	for (int i = 0; i < N; i++)
		arr[i] = V.arr[i];
}
template<class T>
Vector<T>::~Vector()
{
	if (arr != 0)
	{
		delete[] arr;
		arr = 0;
		N = 0;
	}
}
template<class T>
void Vector<T>::Bubble_sort()
{
	T temp = 0;

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
}

template<class T>
void Vector<T>::Insertion_sort()
{
	T temp;

	for (int i = 1; i < N; i++)
	{
		int j = i;
		while ((j > 0) && (arr[j - 1] < arr[j]))
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}

}

template<class T>
void Vector<T>::Quick_sort(int first, int last)
{
	T mid, count;
	int f = first, l = last;

	mid = arr[(f + l) / 2]; 
	do
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l) 
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) Quick_sort(first, l);
	if (f < last) Quick_sort(f, last);
}

template<class T>
Vector<T> Vector<T>::operator=(const Vector<T>& other)
{
	if (*this == other)
		return *this;
	delete[] arr;
	this->N = other.N;
	arr = new T[N];
	for (int i = 0; i < N; i++)
		arr[i] = other.arr[i];
	return *this;
}

template<class T>
bool Vector<T>::operator==(const Vector<T>& other)
{
	if (N == other.N)
	{
		for (int i = 0; i < N; i++)
			if (arr[i] != other.arr[i])
				return false;
		return true;
	}
	else
		return false;
}

template<class T>
T Vector<T>::operator[](const int i)
{
	return arr[i];
}


template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	if (N == other.N)
	{
		Vector<T> vector(N, other.arr);
		for (int i = 0; i < N; i++)
			vector.arr[i] = other.arr[i] + arr[i];
		return vector;
	}
	else
		throw - 1;
}

template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& other)
{
	if (N == other.N)
	{
		Vector<T> vector(N, other.arr);
		for (int i = 0; i < N; i++)
			vector.arr[i] = arr[i] - other.arr[i];
		return vector;
	}
	else
		throw - 1;
}

template<class T>
T Vector<T>::operator *(const Vector<T>& other)
{
	T result = 0;
	if (N == other.N)
	{
		for (int i = 0; i < N; i++)
			result = result + (arr[i] * other.arr[i]);
		return result;
	}
	else
		throw - 1;
}

template<class T>
ostream& operator<<(ostream& os, const Vector<T>& V)
{
	os << "(";
	for (int i = 0; i < V.N; i++)
	{
		os << V.arr[i];
		if (i < V.N - 1)
			os << " ";
	}
	os << ")^T";
	return os;
}
template<class T>
istream& operator>>(istream& in, Vector<T>& V)
{
	cout << "Enter size" << endl << "N = ";
	in >> V.N;
	T* temp;
	temp = new T [V.N];
	for (int i = 0; i < V.N; i++)
		in >> temp[i];
	Vector<T> V(V.N, temp);
	V = V;
	delete[] temp;
	return in;
}
#pragma once
#include "Vector.h"
#include "Matrix.h"

