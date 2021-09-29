#pragma once
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

	int getOrder() { return order; }
	//int** getData() { return data; }
	int getDataIJ(int i, int j) { return data[i][j]; }

	void setOrder(int ord) { order = ord; }
	void setData(int** d) { data = d; }
	void setDataIJ(int x, int i, int j) { data[i][j] = x; }

	~square_matrix();

private:

	int order; // ������� ���������� �������
	int** data; // �� ����������

};

