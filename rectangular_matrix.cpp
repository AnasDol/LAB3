#include "rectangular_matrix.h"
#include <iostream>

rectangular_matrix::rectangular_matrix(int rows, int cols)
{

	try {
		this->rows = rows;
		this->cols = cols;
		data = new int* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new int[cols];

		}
	}
	catch (exception ex) {
		cout << ex.what() << "\n";
	}

}

rectangular_matrix::rectangular_matrix(int rows, int cols, int** data)
{
	try {
		this->rows = rows;
		this->cols = cols;
		this->data = new int* [rows];
		for (int i = 0; i < rows; i++) {
			this->data[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				this->data[i][j] = data[i][j];
			}
		}
	}
	catch (exception ex) {
		cout << ex.what() << "\n";
	}


}

char* rectangular_matrix::to_string()
{
	char str[1000] = "";
	char buff[12];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sprintf_s(buff, sizeof(buff), "%d", data[i][j]);
			strcat_s(str, sizeof(str), buff);
			strcat_s(str, sizeof(str), " ");
		}
		strcat_s(str, sizeof(str), "\n");
	}
	return str;
}

void rectangular_matrix::fill_rand(int a, int b)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = rand() % (b - a) + a;
		}
	}

}

rectangular_matrix rectangular_matrix::transpose()
{

	int** trans_data = new int* [cols];
	for (int i = 0; i < cols; i++) {
		trans_data[i] = new int[rows];
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			trans_data[i][j] = data[j][i];
		}
	}

	return rectangular_matrix(cols, rows, trans_data);
}

rectangular_matrix rectangular_matrix::multiple_num(int num)
{

	int** mult_data = new int* [rows];
	for (int i = 0; i < rows; i++) {
		mult_data[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mult_data[i][j] = data[i][j] * num;
		}
	}

	return rectangular_matrix(rows, cols, mult_data);
}

rectangular_matrix::~rectangular_matrix() {}
