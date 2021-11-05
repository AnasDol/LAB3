#include "square_matrix.h"
#pragma once

struct Elem {

	Elem(square_matrix* m) {
		mat = m;
		prev = nullptr;
		next = nullptr;
	}

	square_matrix * mat;
	Elem* prev;
	Elem* next;
};

class Queue
{

public:

	Queue() {
		first = nullptr;
	}

	void push(square_matrix* m, int num = -1); // вставка в конец | по номеру num
	square_matrix* pop(int num = 1); // получение из начала | с позиции num
	bool empty();
	void show();


private:

	Elem* first;

};

