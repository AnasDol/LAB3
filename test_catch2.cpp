#include "C:\src\vcpkg\packages\catch2_x64-windows-static\include\catch2\catch.hpp"
#include "rectangular_matrix.h"
#include "identity_matrix.h"
#include "Queue.h"
#include "TQueue.h"
#include <fstream>


TEST_CASE("creation") {

	/*int** arr = new int* [3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new int[5];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = i + j;
		}
	 }

	rectangular_matrix mat(3, 5, arr);
	//printf(mat.to_string());

	REQUIRE(mat.get_rows() == 3);
	REQUIRE(mat.get_columns() == 5);

	SECTION("data") {
		

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {

				REQUIRE(mat.get_dataIJ(i, j) == i + j);

			}
		}

	}

	SECTION("operations") {

		//REQUIRE((mat.multiple_num(2)).to_string() == "0 2 4 6 8\n2 4 6 8 10\n4 6 8 10 12\n");

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {

				REQUIRE((mat.multiple_num(2)).get_dataIJ(i, j) == (i + j) * 2);

			}
		}

	}*/

}


TEST_CASE("operators") {

	
	int** arr1 = new int* [5];
	for (int i = 0; i < 5; i++) {
		arr1[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr1[i][j] = j;
		}
	}

	square_matrix m1(5, arr1);

	//printf(m1.to_string());
	//cout << "\n";

	int** arr2 = new int* [5];
	for (int i = 0; i < 5; i++) {
		arr2[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr2[i][j] = i;
		}
	}

	square_matrix m2(5, arr2);

	//printf(m2.to_string());
	//cout << "\n";

	square_matrix m3 = m1 + m2;
	bool f = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			if (m3[i][j] != arr1[i][j] + arr2[i][j]) {
				f = 1;
				break;
			}

		}
		if (f == 1) break;
	}
	REQUIRE(f == 0);

	square_matrix m4 = -m2;
	f = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			if (m4[i][j] != -1 * arr2[i][j]) {
				f = 1;
				break;
			}

		}
		if (f == 1) break;
	}
	REQUIRE(f == 0);

	square_matrix m5 = m1-m2;
	f = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			if (m5[i][j] != arr1[i][j] - arr2[i][j]) {
				f = 1;
				break;
			}

		}
		if (f == 1) break;
	}
	REQUIRE(f == 0);

	square_matrix m6 = m1;
	f = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			if (m6[i][j] != arr1[i][j]) {
				f = 1;
				break;
			}

		}
		if (f == 1) break;
	}
	REQUIRE(f == 0);

	REQUIRE(m1()==0);


	/*printf((m1 + m2).to_string());
	cout << "\n";

	printf((-m2).to_string());
	cout << "\n";

	printf("%d", m2[2][2]);
	cout << "\n\n";

	square_matrix m7(3);
	m7.fill_rand();

	printf(m7.to_string());
	cout << "\n";

	printf("%d", m7.determinant());
	cout << "\n\n";

	printf("%d", m7());
	cout << "\n\n";

	square_matrix m8 = m7;*/
	
}


TEST_CASE("threads") {

	square_matrix m1(4);
	m1.fill_rand();
	cout << m1 << endl;

	square_matrix m2;
	m2.fill_rand();
	cout << m2 << endl;

	// запишем матрицу m1 в текстовый файл FILE.TXT

	m1.twrite();

	// запишем матрицу m2 туда же

	square_matrix::twrite(&m2);

	// запишем матрицы в обратном порядке в бинарный файл FILE.DAT

	m2.bwrite();
	square_matrix::bwrite(&m1);

	// читаем матрицы из текстового файла

	square_matrix m3(square_matrix::tread(1));
	//cout << m3 << endl;
	square_matrix m4(square_matrix::tread(2));
	//cout << m4 << endl;

	// проверим на совпадение с исходными матрицами

	bool f = 0;

	for (int i = 0; i < m3.get_order(); i++) {
		for (int j = 0; j < m3.get_order(); j++) {
			if (m3[i][j] != m1[i][j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) break;
	}

	REQUIRE(f == 0); // m3==m1

	f = 0;

	for (int i = 0; i < m4.get_order(); i++) {
		for (int j = 0; j < m4.get_order(); j++) {
			if (m4[i][j] != m2[i][j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) break;
	}

	REQUIRE(f == 0); // m4==m2

	// читаем матрицы из бинарного файла файла

	square_matrix m5(square_matrix::bread(1));
	//cout << m3 << endl;
	square_matrix m6(square_matrix::bread(2));
	//cout << m4 << endl;

	// проверим на совпадение с исходными матрицами

	f = 0;

	for (int i = 0; i < m5.get_order(); i++) {
		for (int j = 0; j < m5.get_order(); j++) {
			if (m5[i][j] != m2[i][j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) break;
	}

	REQUIRE(f == 0); // m3==m1

	f = 0;

	for (int i = 0; i < m6.get_order(); i++) {
		for (int j = 0; j < m6.get_order(); j++) {
			if (m6[i][j] != m1[i][j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) break;
	}

	REQUIRE(f == 0); // m4==m2

}


TEST_CASE("queue") {
	/*
	square_matrix m1(3);
	m1.fill_rand();
	printf(m1.to_string());
	cout << "\n\n";

	square_matrix m2(5);
	m2.fill_rand();
	printf(m2.to_string());
	cout << "\n\n";

	rectangular_matrix m3(2, 4);
	m3.fill_rand();
	printf(m3.to_string());
	cout << "\n\n";

	identity_matrix m4(4);
	printf(m4.to_string());
	cout << "\n\n";


	Queue queue;




	cout << "PUSH\n\n";

	queue.push(&m1);

	cout << "QUEUE NOW:\n\n";
	queue.show();

	queue.push(&m2);

	cout << "QUEUE NOW:\n\n";
	queue.show();

	queue.push(&m3);

	cout << "QUEUE NOW:\n\n";
	queue.show();

	queue.push(&m4);

	cout << "QUEUE NOW:\n\n";
	queue.show();




	cout << "PUSH BY NUM\n\n";

	queue.push(&m3, 1);

	cout << "QUEUE NOW:\n\n";
	queue.show();

	queue.push(&m4, 3);

	cout << "QUEUE NOW:\n\n";
	queue.show();



	
	cout << "POP\n\n";

	square_matrix* m6 = queue.pop();
	printf((*m6).to_string());
	cout << "\n\n";

	cout << "QUEUE NOW:\n\n";
	queue.show();

	square_matrix* m7 = queue.pop();
	printf((*m7).to_string());
	cout << "\n\n";

	cout << "QUEUE NOW:\n\n";
	queue.show();

	square_matrix* m8 = queue.pop();
	printf((*m8).to_string());
	cout << "\n\n";

	cout << "QUEUE NOW:\n\n";
	queue.show();
	



	cout << "POP BY NUM\n\n";

	square_matrix* m9 = queue.pop(2);
	printf((*m6).to_string());
	cout << "\n\n";

	cout << "QUEUE NOW:\n\n";
	queue.show();



	*/

}


TEST_CASE("template") {

	TQueue<int> q1;

	int i1 = 5, i2 = -4, i3 = 23, i4 = 540, i5 = 0;
	q1.push(&i1);
	q1.push(&i2);
	q1.push(&i3);
	q1.push(&i4);
	q1.push(&i5);

	q1.show();

	TQueue<float> q2;

	float f1 = -45.f, f2 = 4.23, f3 = 507.2, f4 = 1.001;
	q2.push(&f1);
	q2.push(&f2);
	q2.push(&f3);
	q2.push(&f4);

	q2.show();

	TQueue<square_matrix> q3;

	square_matrix m1(3);
	//rectangular_matrix m2(4, 2);
	identity_matrix m3(5);
	square_matrix m4(6);
	m1.fill_rand();
	//m2.fill_rand();
	m4.fill_rand();
	q3.push(&m1);
	//q3.push(&m2);
	q3.push(&m3);
	q3.push(&m4);
	
	q3.show();

	// ПОЛУЧАЕТСЯ, В КЛАССЕ QUEUE ОН ПОНИМАЕТ, ЧТО ПО УКАЗАТЕЛЮ ТИПА SQUARE_MATRIX МОЖЕТ ЛЕЖАТЬ
	// ОБЪЕКТ КЛАССА-НАСЛЕДНИКА, И ИСПОЛЬЗУЕТ В СЛУЧАЕ ЧЕГО ЕГО МЕТОДЫ, А ЗДЕСЬ НЕТ, ПОТОМУ ЧТО
	// МЫ ЯВНО УКАЗАЛИ, ЧТО СОЗДАЕМ ОЧЕРЕДЬ ИЗ КВАДРАТНЫХ МАТРИЦ


}