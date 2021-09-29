#include <iostream>
#include "Test.h"
#include "square_matrix.h"
using namespace std;

int main() {

	/*square_matrix m1(5);
	m1.fill_rand();
	cout << "M1:\n";
	cout << m1.to_string() << endl;

	square_matrix m2 = square_matrix();
	m2.fill_rand();
	cout << "M2:\n";
	cout << m2.to_string() << endl;

	square_matrix m3(m1.transpose());
	cout << "M3 = (M1)^(-1):\n";
	cout << m3.to_string() << endl;

	square_matrix m4(m2.add(m1));
	cout << "M4 = M1+M2:\n";
	cout << m4.to_string() << endl;

	cout << "M5 = M3+M4:\n";
	cout << (square_matrix::add(m3, m4)).to_string() << endl;*/

	if (!Test::testTransposition1()) cout << "testTransposition1 failed\n";
	else cout << "testTransposition1 passed\n";
	if (!Test::testTransposition2()) cout << "testTransposition2 failed\n";
	else cout << "testTransposition2 passed\n";
	if (!Test::testAddition1()) cout << "testAddition1 failed\n";
	else cout << "testAddition1 passed\n";
	if (!Test::testAddition2()) cout << "testAddition2 failed\n";
	else cout << "testAddition2 passed\n";

}