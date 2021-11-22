#include <iostream>

#pragma once
template <class T> class TQueue
{
	struct Elem {

		Elem(T* v) {
			value = v;
			prev = nullptr;
			next = nullptr;
		}

		~Elem() {
			delete[] value, prev, next;
		}

		T* value;
		Elem* prev;
		Elem* next;
	};



public:

	TQueue() {
		first = nullptr;
	}

	void push(T* v, int num = -1); // вставка в конец | по номеру num
	T* pop(int num = 1); // получение из начала | с позиции num
	bool empty();
	void show();


private:

	Elem* first;


};


template<class T>
inline void TQueue<T>::push(T* v, int num)
{
	Elem* e = new Elem(v);

	if (this->empty()) { // если очередь пуста, создаем ее первый элемент
		e->next = e;
		e->prev = e;
		first = e;
		return;
	}

	Elem* p = first;

	if (num == -1) { // вставка перед первым

		do {
			p = p->next;
		} while (p->next != first);

		e->next = first;
		p->next = e;
		first->prev = e;
		e->prev = p;

	}

	else { // вставка по номеру

		for (int i = 0; i < num - 1; i++) {
			p = p->next;
		} // остановились перед нужной позицией

		e->next = p;
		e->prev = p->prev;
		p->prev->next = e;
		p->prev = e;

		if (p == first) first = e;

	}
}

template<class T>
inline T* TQueue<T>::pop(int num)
{
	T* v = first->v;

	Elem* p = first;

	// забрать по номеру, по умолчанию - первый элемент (num == 1)

	for (int i = 0; i < num - 1; i++) {
		p = p->next;
	} // остановились на нужной позициии

	if (p == first) {
		first = first->next;
	}

	p->prev->next = p->next;
	p->next->prev = p->prev;

	return v;
}


template<class T>
inline bool TQueue<T>::empty()
{
	if (first == nullptr) return true;
	return false;

}

template<class T>
inline void TQueue<T>::show()
{

	Elem* p = first;
	cout << endl;
	do {
		std::cout << *(p->value) << endl;
		p = p->next;
	} while (p != first);
	cout << endl;

}