#pragma once
#include "Exception.h"
#include <iostream>
using namespace std;

#define filename_t "File.txt"
#define filename_b "File.dat"

class square_matrix
{

public:

	square_matrix(int order = 5);
	square_matrix(int order, int** data);
	square_matrix(const square_matrix& mat);

	void fill_rand(int a = -100, int b = 100); // ��������� ���������� ����������
	virtual char* to_string();

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

	square_matrix multiple_num(int num);

	int determinant();
	static int determinant(int** matrix, int n);
	static void submatrix(int** mat, int** temp, int p, int q, int n);

	friend square_matrix operator+ (square_matrix m1, square_matrix m2);
	friend square_matrix operator- (square_matrix m1, square_matrix m2);
	friend square_matrix operator- (square_matrix m);
	int* operator[] (int i);

	int operator()();
	square_matrix& operator=(square_matrix& m);
	/*virtual*/ friend ostream& operator<< (ostream& os, square_matrix& m);
	friend istream& operator>> (istream& is, square_matrix& m);

	void twrite(ofstream& ftout); // ���������� ������� � ��������� ����
	static void twrite(ofstream& ftout, square_matrix* m);
	static square_matrix tread(ifstream& ftin/*int index = 1*/); // ������ ������� �� ��������� �����

	void bwrite(ofstream&); // ���������� ������� � �������� ����
	static void bwrite(ofstream& out, square_matrix* m);
	void bread(ifstream&); // ������ ������� �� ��������� �����

	~square_matrix();


protected:

	int order; // ������� ���������� �������
	int** data; // �� ����������


};

