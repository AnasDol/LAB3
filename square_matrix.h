#pragma once
#include "Exception.h"
#include <iostream>
using namespace std;

class square_matrix
{

public:

	square_matrix(int order = 5);
	square_matrix(int order, int** data);
	square_matrix(const square_matrix& mat);

	void fill_rand(int a = -100, int b = 100); // ��������� ���������� ����������
	char* to_string();

	square_matrix transpose(); // �������������
	square_matrix add(square_matrix mat); // ���������� ������� ������� � ���������� � ���������
	static square_matrix add(square_matrix mat1, square_matrix mat2); // ���������� ��� �������

	int get_order() { return order; }
	int get_dataIJ(int i, int j) { return data[i][j]; }

	void set_order(int ord) { 
		if (ord <= 0) {
			char str[1000] = "";
			strcat_s(str, sizeof(str), "Invalid order of matrix");
			throw Exception(str);
		}
		order = ord;
	}
	void set_data(int** d) {
		if (data == nullptr) {
			char str[1000] = "";
			strcat_s(str, sizeof(str), "Invalid data");
			throw Exception(str);
		}
	}
	void set_dataIJ(int x, int i, int j) { 
		try {
			data[i][j] = x;
		}
		catch (exception ex) {
			cout << ex.what() << "\n";
		}
 	}

	~square_matrix();


protected:

	int order; // ������� ���������� �������
	int** data; // �� ����������

};

