#include "square_matrix.h"
#include "Exception.h"
#include <iostream>

// ÊÎÍÑÒÐÓÊÒÎÐÛ

square_matrix::square_matrix(int order)
{
	
	try {
		this->order = order;
		data = new int* [order];
		for (int i = 0; i < order; i++) {
			data[i] = new int[order];

		}
	} catch (exception ex) {
		cout<<ex.what()<<"\n";
	}
}

square_matrix::square_matrix(int order, int** data)
{

	try {
		this->order = order;
		this->data = new int* [order];
		for (int i = 0; i < order; i++) {
			this->data[i] = new int[order];
		}
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				this->data[i][j] = data[i][j];
			}
		}
	}
	catch (exception ex) {
		cout << ex.what() << "\n";
	}
	
}

square_matrix::square_matrix(const square_matrix& mat)
{
	try {
		order = mat.order;
		data = new int* [order];
		for (int i = 0; i < order; i++) {
			data[i] = new int[order];
		}
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				data[i][j] = mat.data[i][j];
			}
		}
	}
	catch (exception ex) {
		cout << ex.what() << "\n";
	}
}

// ÁÀÇÎÂÛÉ ÔÓÍÊÖÈÎÍÀË

square_matrix square_matrix::transpose()
{

	int** trans_data = new int* [order];
	for (int i = 0; i < order; i++) {
		trans_data[i] = new int[order];
	}

	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			trans_data[i][j] = data[j][i];
		}
	}

	return square_matrix(order, trans_data);

}

square_matrix square_matrix::add(square_matrix mat)
{
	if (mat.order != order) {
		char str[1000] = "";
		strcat_s(str, sizeof(str), "Only matrices of the same order can be added");
		throw Exception(str);
		return NULL;
	}

	int** add_data = new int* [order];
	for (int i = 0; i < order; i++) {
		add_data[i] = new int[order];
	}

	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			add_data[i][j] = data[i][j] + mat.data[i][j];
		}
	}
	return square_matrix(order, add_data);

}

square_matrix square_matrix::add(square_matrix mat1, square_matrix mat2)
{

	if (mat1.order != mat2.order) {
		char str[1000] = "";
		strcat_s(str, sizeof(str), "Only matrices of the same order can be added");
		throw Exception(str);
		return NULL;
	}

	int** add_data = new int* [mat1.order];
	for (int i = 0; i < mat1.order; i++) {
		add_data[i] = new int[mat1.order];
	}

	for (int i = 0; i < mat1.order; i++) {
		for (int j = 0; j < mat1.order; j++) {
			add_data[i][j] = mat1.data[i][j] + mat2.data[i][j];
		}
	}
	return square_matrix(mat1.order, add_data);

}

void square_matrix::fill_rand(int a, int b) {

	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			data[i][j] = rand() % (b - a) + a;
		}
	}
}

char* square_matrix::to_string()
{
	char str[1000] = "";
	char buff[12];
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			sprintf_s(buff, sizeof(buff), "%d", data[i][j]);
			strcat_s(str, sizeof(str), buff);
			strcat_s(str, sizeof(str), " ");
		}
		strcat_s(str, sizeof(str), "\n");
	}
	return str;
}

square_matrix square_matrix::multiple_num(int num)
{

	int** mult_data = new int* [order];
	for (int i = 0; i < order; i++) {
		mult_data[i] = new int[order];
	}

	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			mult_data[i][j] = data[i][j] * num;
		}
	}

	return square_matrix(order, mult_data);
}

// ÏÎÈÑÊ ÎÏÐÅÄÅËÈÒÅËß

void square_matrix::subMatrix(int** mat, int** temp, int p, int q, int n) {
	int i = 0, j = 0;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (row != p && col != q) {
				temp[i][j++] = mat[row][col];
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

int square_matrix::determinant(int** matrix, int n) {
	int det = 0;
	if (n == 1) {
		return matrix[0][0];
	}
	if (n == 2) {
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	int** temp = new int* [n];
	for (int i = 0; i < n; i++) {
		temp[i] = new int[n];
	}
	int sign = 1;
	for (int i = 0; i < n; i++) {
		subMatrix(matrix, temp, 0, i, n);
		det += sign * matrix[0][i] * determinant(temp, n - 1);
		sign = -sign;
	}
	for (int i = 0; i < n; i++)
		delete[] temp[i];
	delete[] temp;
	return det;
}

int square_matrix::determinant()
{
	return determinant(data, order);
}

// ÏÅÐÅÃÐÓÇÊÀ ÎÏÅÐÀÒÎÐÎÂ

int* square_matrix::operator[](int index)
{
	return data[index];
}

int square_matrix::operator()()
{
	return determinant(data, order);
}

square_matrix& square_matrix::operator=(square_matrix& m)
{
	order = m.order;
	data = new int* [order];
	for (int i = 0; i < order; i++) {
		data[i] = new int[order];
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			data[i][j] = m.data[i][j];
		}
	}
	return *this;
}

square_matrix operator+(square_matrix m1, square_matrix m2)
{
	return square_matrix::add(m1,m2);
}

square_matrix operator-(square_matrix m)
{
	return m.multiple_num(-1);
}

square_matrix operator-(square_matrix m1, square_matrix m2)
{
	return square_matrix::add(m1, m2.multiple_num(-1));
}



// ÄÅÑÒÐÓÊÒÎÐ

square_matrix::~square_matrix()
{
	for (int i = 0; i < order; i++)
		delete[] data[i];
	delete[] data;
}