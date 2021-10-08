#include <iostream>
#include "Test.h"
#include "square_matrix.h"
#include "Exception.h"
using namespace std;

int main() {

	square_matrix mat(-5);
	mat.fill_rand();
	cout << mat.to_string();

	try {
		Test::testTransposition1();
	}
	catch (Exception ex) {
		cout << ex.what() << "\n";
	}


	try {
		Test::testTransposition2();
	}
	catch (Exception ex) {
		cout << ex.what() << "\n";
	}


	try {
		Test::testAddition1();
	}
	catch (Exception ex) {
		cout << ex.what() << "\n";
	}


	try {
		Test::testAddition2();
	}
	catch (Exception ex) {
		cout << ex.what() << "\n";
	}

}