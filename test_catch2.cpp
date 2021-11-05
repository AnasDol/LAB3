#include "C:\src\vcpkg\packages\catch2_x64-windows-static\include\catch2\catch.hpp"
#include "rectangular_matrix.h"
#include "identity_matrix.h"
#include "MatrixList.h"


TEST_CASE("creation") {

	int** arr = new int* [3];
	for (int i = 0; i < 3; i++) {
		arr[i] = new int[5];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = i + j;
		}
	 }

	rectangular_matrix mat(3, 5, arr);
	printf(mat.to_string());

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

	}

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

	/*printf(m2.to_string());
	cout << "\n";


	printf((m1 + m2).to_string());
	cout << "\n";

	printf((-m2).to_string());
	cout << "\n";

	printf("%d", m2[2][2]);
	cout << "\n";*/
}


TEST_CASE("queue") {

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





}