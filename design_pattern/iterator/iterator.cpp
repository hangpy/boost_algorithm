#include <cstdio>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
	template<typename T> friend class myList;
private:
	Node *pNext = nullptr;
	T number;
public:
	Node(T _data) : number(_data) {};
	T get_number() const
	{
		return number;
	}
	Node *getNext()
	{
		return pNext;
	}
};


//template<typename T>
//class List
//{
//public:
//	virtual void add(T);
//	virtual void next();
//	virtual Node<T>& get_current();
//};


template<typename T>
class myList
{
private:
	Node<T> *_head;
	Node<T> *_current;
public:
	myList();
	void add(T data);
	void next();
	Node<T>& get_current();
};



template<typename T> myList<T>::myList():_head(nullptr), _current(_head)
{
};

template<typename T> void myList<T>::add(T data)
{
	cout << "SAD" << endl;
	Node<T> *tmp = new Node<T>(data);
	tmp->pNext = _head->pNext;
	_head = tmp;
}

template<typename T> void myList<T>::next()
{
	_current = _current->pNext;
}

template<typename T> Node<T>& myList<T>::get_current()
{
	return *_current;
}



int main()
{
	
	myList<int> li;

	li.add(1);
	li.add(2);
	li.add(3);
	li.add(4);
	li.add(5);

	while (true)
	{
		cout << "asdf" << endl;
		if (li.get_current().getNext() == nullptr) break;
		cout << li.get_current().get_number() << endl;
		li.next();
	}



	return 0;
}

