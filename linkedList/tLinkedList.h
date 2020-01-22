#pragma once
#include <iostream>
template<typename T>
class tForwardList
{
	struct Node
	{
		T data;
		Node * next;
	};

	Node * next;

public:
	tForwardList();
	~tForwardList();

	void push_front(Node** head_ref, const T& val);
	void pop_front(Node** head_ref);

	T& front();
	const T& front() const;

	void remove(Node** head_ref, const T& val);

	T& tail(Node* cur);
};

template<typename T>
inline tForwardList<T>::tForwardList()
{
	Node* head = NULL;
	head = new Node();
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
	Node* current = head;
	while (current != 0) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

template<typename T>
inline void tForwardList<T>::push_front(Node** head_ref, const T & val)
{
	Node* new_Node = new Node();

	new_Node->data = val;
	new_Node->next = *head_ref;
	*head_ref = new_Node;
}

template<typename T>
inline void tForwardList<T>::pop_front(Node** head_ref)
{
	if (*head_ref != NULL)
	{
		*head_ref = *head_ref->next;
	}
}

template<typename T>
inline T & tForwardList<T>::front()
{
	
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	// TODO: insert return statement here
}

template<typename T>
inline void tForwardList<T>::remove(Node** head_ref, const T & val)
{
	Node* tmpCur = *head_ref;
	Node* tmpPrev = *head_ref;
	if (temp != nullptr && temp->data == val)
	{
		*head_ref = tmpCur->next;
	}

	while (tmpCur->next != nullptr)
	{
		if (tmpCur->data != val)
		{
			tmpPrev = tmpCur;
			tmpCur = tmpPrev->next;
		}
		else
		{
			tmpPrev->next = tmpCur->next;
		}
	}
	
}

template<typename T>
inline T & tForwardList<T>::tail(Node * cur)
{
	while (cur != nullptr && cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}
