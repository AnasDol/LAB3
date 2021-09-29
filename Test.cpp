#include "Test.h"
#include "square_matrix.h"
#include <iostream>

bool Test::testTransposition1()
{

	//cout << "TEST TRANSPOSITION...\n\n";
	square_matrix mat(3);
	for (int i = 0; i < mat.getOrder(); i++) {
		for (int j = 0; j < mat.getOrder(); j++) {
			mat.setDataIJ(i, i, j);
		}
	}
	//std::cout << mat.to_string() << endl;

	square_matrix tmat(mat.transpose());

	//std::cout << tmat.to_string() << endl;
	bool f = 1;
	for (int i = 0; i < tmat.getOrder(); i++) {
		for (int j = 0; j < tmat.getOrder(); j++) {
			if (tmat.getDataIJ(i, j) != j) {
				f = 0;
				break;
			}
		}
	}

	//if (f) cout << "OK\n\n";
	//else cout << "Error!\n\n";

	return f;

}

bool Test::testTransposition2()
{
	//cout << "TEST TRANSPOSITION...\n\n";

	square_matrix mat(4);
	for (int i = 0; i < mat.getOrder(); i++) {
		for (int j = 0; j < mat.getOrder(); j++) {
			mat.setDataIJ(i * 10 + j, i, j);
		}
	}
	//std::cout << mat.to_string() << endl;

	square_matrix tmat(mat.transpose());

	//std::cout << tmat.to_string() << endl;

	bool f = 1;
	for (int i = 0; i < tmat.getOrder(); i++) {
		for (int j = 0; j < tmat.getOrder(); j++) {
			if (tmat.getDataIJ(i, j) != j * 10 + i) {
				f = 0;
				break;
			}
		}
	}

	//if (f) cout << "OK\n\n";
	//else cout << "Error!\n\n";

	return f;

}

bool Test::testAddition1()
{
	//cout << "TEST ADDITION...\n\n";

	square_matrix mat1(3);
	for (int i = 0; i < mat1.getOrder(); i++) {
		for (int j = 0; j < mat1.getOrder(); j++) {
			mat1.setDataIJ(1, i, j);
		}
	}
	//std::cout << mat1.to_string() << endl;

	square_matrix mat2(3);
	for (int i = 0; i < mat2.getOrder(); i++) {
		for (int j = 0; j < mat2.getOrder(); j++) {
			mat2.setDataIJ(2, i, j);
		}
	}
	//std::cout << mat2.to_string() << endl;

	square_matrix amat(square_matrix::add(mat1, mat2));
	//std::cout << amat.to_string() << endl;

	bool f = 1;
	for (int i = 0; i < amat.getOrder(); i++) {
		for (int j = 0; j < amat.getOrder(); j++) {
			if (amat.getDataIJ(i, j) != 3) {
				f = 0;
				break;
			}
		}
	}

	//if (f) cout << "OK\n\n";
	//else cout << "Error!\n\n";

	return f;

}

bool Test::testAddition2()
{
	//cout << "TEST ADDITION...\n\n";

	square_matrix mat1(2);
	mat1.setDataIJ(3, 0, 0);
	mat1.setDataIJ(-1, 0, 1);
	mat1.setDataIJ(2, 1, 0);
	mat1.setDataIJ(5, 1, 1);

	//std::cout << mat1.to_string() << endl;

	square_matrix mat2(2);
	mat2.setDataIJ(-2, 0, 0);
	mat2.setDataIJ(-4, 0, 1);
	mat2.setDataIJ(6, 1, 0);
	mat2.setDataIJ(0, 1, 1);

	//std::cout << mat2.to_string() << endl;

	square_matrix amat(square_matrix::add(mat1, mat2));
	//std::cout << amat.to_string() << endl;

	bool f = 1;

	if (amat.getDataIJ(0, 0) != 1
		|| amat.getDataIJ(0, 1) != -5
		|| amat.getDataIJ(1, 0) != 8
		|| amat.getDataIJ(1, 1) != 5) {
		f = 0;
	}

	//if (f) cout << "OK\n\n";
	//else cout << "Error!\n\n";

	return f;

}