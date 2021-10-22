#include "Test.h"
#include "square_matrix.h"
#include "Exception.h"
#include <iostream>

bool Test::testTransposition1()
{

	square_matrix mat(3);
	for (int i = 0; i < mat.get_order(); i++) {
		for (int j = 0; j < mat.get_order(); j++) {
			mat.set_dataIJ(i, i, j);
		}
	}

	square_matrix tmat(mat.transpose());

	bool f = 1;
	for (int i = 0; i < tmat.get_order(); i++) {
		for (int j = 0; j < tmat.get_order(); j++) {
			if (tmat.get_dataIJ(i, j) != j) {
				f = 0;
				break;
			}
		}
	}

	char str[1000] = "";
	strcat_s(str, sizeof(str), "TestTransposition1 failed");

	if (!f) throw Exception(str);

	return f;

}

bool Test::testTransposition2()
{
	square_matrix mat(4);
	for (int i = 0; i < mat.get_order(); i++) {
		for (int j = 0; j < mat.get_order(); j++) {
			mat.set_dataIJ(i * 10 + j, i, j);
		}
	}

	square_matrix tmat(mat.transpose());

	bool f = 1;
	for (int i = 0; i < tmat.get_order(); i++) {
		for (int j = 0; j < tmat.get_order(); j++) {
			if (tmat.get_dataIJ(i, j) != j * 10 + i) {
				f = 0;
				break;
			}
		}
	}

	char str[1000] = "";
	strcat_s(str, sizeof(str), "TestTransposition2 failed");

	if (!f) throw Exception(str);

	return f;

}

bool Test::testAddition1()
{
	square_matrix mat1(3);
	for (int i = 0; i < mat1.get_order(); i++) {
		for (int j = 0; j < mat1.get_order(); j++) {
			mat1.set_dataIJ(1, i, j);
		}
	}

	square_matrix mat2(3);
	for (int i = 0; i < mat2.get_order(); i++) {
		for (int j = 0; j < mat2.get_order(); j++) {
			mat2.set_dataIJ(2, i, j);
		}
	}

	square_matrix amat(square_matrix::add(mat1, mat2));

	bool f = 1;
	for (int i = 0; i < amat.get_order(); i++) {
		for (int j = 0; j < amat.get_order(); j++) {
			if (amat.get_dataIJ(i, j) != 3) {
				f = 0;
				break;
			}
		}
	}

	char str[1000] = "";
	strcat_s(str, sizeof(str), "TestAddition1 failed");

	if (!f) throw Exception(str);

	return f;

}

bool Test::testAddition2()
{

	square_matrix mat1(2);
	mat1.set_dataIJ(3, 0, 0);
	mat1.set_dataIJ(-1, 0, 1);
	mat1.set_dataIJ(2, 1, 0);
	mat1.set_dataIJ(5, 1, 1);

	square_matrix mat2(2);
	mat2.set_dataIJ(-2, 0, 0);
	mat2.set_dataIJ(-4, 0, 1);
	mat2.set_dataIJ(6, 1, 0);
	mat2.set_dataIJ(0, 1, 1);

	square_matrix amat(mat1.add(mat2));

	bool f = 1;

	if (amat.get_dataIJ(0, 0) != 1
		|| amat.get_dataIJ(0, 1) != -5
		|| amat.get_dataIJ(1, 0) != 8
		|| amat.get_dataIJ(1, 1) != 5) {
		f = 0;
	}

	char str[1000] = "";
	strcat_s(str, sizeof(str), "TestAddition2 failed");

	if (!f) throw Exception(str);

	return f;

}