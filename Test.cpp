#include "Test.h"
#include "square_matrix.h"
#include "Exception.h"
#include <iostream>

bool Test::testTransposition1()
{

	square_matrix mat(3);
	for (int i = 0; i < mat.getOrder(); i++) {
		for (int j = 0; j < mat.getOrder(); j++) {
			mat.setDataIJ(i, i, j);
		}
	}

	square_matrix tmat(mat.transpose());

	bool f = 1;
	for (int i = 0; i < tmat.getOrder(); i++) {
		for (int j = 0; j < tmat.getOrder(); j++) {
			if (tmat.getDataIJ(i, j) != j) {
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
	for (int i = 0; i < mat.getOrder(); i++) {
		for (int j = 0; j < mat.getOrder(); j++) {
			mat.setDataIJ(i * 10 + j, i, j);
		}
	}

	square_matrix tmat(mat.transpose());

	bool f = 1;
	for (int i = 0; i < tmat.getOrder(); i++) {
		for (int j = 0; j < tmat.getOrder(); j++) {
			if (tmat.getDataIJ(i, j) != j * 10 + i) {
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
	for (int i = 0; i < mat1.getOrder(); i++) {
		for (int j = 0; j < mat1.getOrder(); j++) {
			mat1.setDataIJ(1, i, j);
		}
	}

	square_matrix mat2(3);
	for (int i = 0; i < mat2.getOrder(); i++) {
		for (int j = 0; j < mat2.getOrder(); j++) {
			mat2.setDataIJ(2, i, j);
		}
	}

	square_matrix amat(square_matrix::add(mat1, mat2));

	bool f = 1;
	for (int i = 0; i < amat.getOrder(); i++) {
		for (int j = 0; j < amat.getOrder(); j++) {
			if (amat.getDataIJ(i, j) != 3) {
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
	mat1.setDataIJ(3, 0, 0);
	mat1.setDataIJ(-1, 0, 1);
	mat1.setDataIJ(2, 1, 0);
	mat1.setDataIJ(5, 1, 1);

	square_matrix mat2(2);
	mat2.setDataIJ(-2, 0, 0);
	mat2.setDataIJ(-4, 0, 1);
	mat2.setDataIJ(6, 1, 0);
	mat2.setDataIJ(0, 1, 1);

	square_matrix amat(mat1.add(mat2));

	bool f = 1;

	if (amat.getDataIJ(0, 0) != 1
		|| amat.getDataIJ(0, 1) != -5
		|| amat.getDataIJ(1, 0) != 8
		|| amat.getDataIJ(1, 1) != 5) {
		f = 0;
	}

	char str[1000] = "";
	strcat_s(str, sizeof(str), "TestAddition2 failed");

	if (!f) throw Exception(str);

	return f;

}