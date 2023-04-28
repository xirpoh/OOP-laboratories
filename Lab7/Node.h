#pragma once

template <typename T>
class Node
{
public:
	T value;
	Node<T> *next, *prec;

	Node(T value) {
		this->value = value;
		this->next = nullptr;
		this->prec = nullptr;
	}
};
