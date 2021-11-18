#include "Queue.h"


void Queue::push(square_matrix* m, int num)
{

	Elem* e = new Elem(m);

	if (this->empty()) { // ���� ������� �����, ������� �� ������ �������
		e->next = e;
		e->prev = e;
		first = e;
		return;
	}

	Elem* p = first;

	if (num == -1) { // ������� ����� ������

		do {
			p = p->next;
		} while (p->next != first);

		e->next = first;
		p->next = e;
		first->prev = e;
		e->prev = p;

	}

	else { // ������� �� ������

		for (int i = 0; i < num - 1; i++) {
			p = p->next;
		} // ������������ ����� ������ ��������

		e->next = p;
		e->prev = p->prev;
		p->prev->next = e;
		p->prev = e;

		if (p == first) first = e;

	}


}

square_matrix* Queue::pop(int num)
{

	square_matrix* mat = first->mat;

	Elem* p = first;
	
	// ������� �� ������, �� ��������� - ������ ������� (num == 1)

	for (int i = 0; i < num - 1; i++) {
		p = p->next;
	} // ������������ �� ������ ��������

	if (p == first) {
		first = first->next;
	}

	p->prev->next = p->next;
	p->next->prev = p->prev;

	return mat;
}

bool Queue::empty()
{

	if (first == nullptr) return true;
	return false;

}

void Queue::show() {

	cout << "\n\n";
	Elem* p = first;
	do {
		printf(p->mat->to_string());
		if (p->next != first) cout << "\n     |\n\n";
		p = p->next;
	} while (p != first);
	cout << "\n\n";


}
