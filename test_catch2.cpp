#include "C:\src\vcpkg\packages\catch2_x64-windows-static\include\catch2\catch.hpp"
#include "rectangular_matrix.h"


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
