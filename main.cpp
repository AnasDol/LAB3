#include <iostream>
#include "Test.h"
#include "square_matrix.h"
#include "Exception.h"
using namespace std;

int main() {

	try {
		Test::testTransposition1();
	}
	catch (Exception ex) {
		cout << ex.GetError() << "\n";
	}


	try {
		Test::testTransposition2();
	}
	catch (Exception ex) {
		cout << ex.GetError() << "\n";
	}


	try {
		Test::testAddition1();
	}
	catch (Exception ex) {
		cout << ex.GetError() << "\n";
	}


	try {
		Test::testAddition2();
	}
	catch (Exception ex) {
		cout << ex.GetError() << "\n";
	}

}