#include "identity_matrix.h"

identity_matrix::identity_matrix(int ord)
{
	try {
		this->order = order;
		data = new int* [order];
		for (int i = 0; i < order; i++) {
			data[i] = new int[order];
		}
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {

				if (i == j) data[i][j] = 1;
				else data[i][j] = 0;

			}
		}
	}
	catch (exception ex) {
		cout << ex.what() << "\n";
	}

}


identity_matrix::~identity_matrix() {}
