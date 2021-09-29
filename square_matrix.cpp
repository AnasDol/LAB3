#include "square_matrix.h"
#include <iostream>

#include <string.h>

square_matrix::square_matrix(int order)
{
	this->order = order;
	data = new int* [order];
	for (int i = 0; i < order; i++) {
		data[i] = new int[order];
	}
}

square_matrix::square_matrix(int order, int** data)
{
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

square_matrix::square_matrix(const square_matrix& mat)
{
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
		//cout << "—кладывать можно только матрицы одного пор€дка\n\n";
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
		//cout << "—кладывать можно только матрицы одного пор€дка\n\n";
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

//catch2

square_matrix::~square_matrix()
{
	for (int i = 0; i < order; i++)
		delete[] data[i];
	delete[] data;
}