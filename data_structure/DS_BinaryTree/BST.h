#include <iostream>

using namespace std;

#pragma once

template<typename T> class BST;

template<typename T>
class Node
{
	friend class BST<T>;
private:
	// Type T must provide with operator==(), perator<()
	T mData;
	Node<T> *left;
	Node<T> *right;

public:
	// Constructur allows implicit type conversion
	Node(T pData, Node<T> *pLeft = nullptr, Node<T> *pRight = nullptr);
	bool operator==(const Node &rhs) const;
	bool operator==(const T &rhs) const;
	bool operator<(const Node &rhs) const;
	bool operator<(const T &rhs) const;
};

template<typename T>
inline Node<T>::Node(T pData, Node<T> * pLeft, Node<T> * pRight)
	:mData(pData), left(pLeft), right(pRight)
{
}

template<typename T>
inline bool Node<T>::operator==(const Node & rhs) const
{
	return this->mData == rhs.mData;
}

template<typename T>
inline bool Node<T>::operator==(const T & rhs) const
{
	return this->mData == rhs;
}

template<typename T>
inline bool Node<T>::operator<(const Node & rhs) const
{
	return this->mData < rhs.mData;
}

template<typename T>
inline bool Node<T>::operator<(const T & rhs) const
{
	return this->mData < rhs;
}


template<typename T>
class BST
{
private:
	Node<T> *root = nullptr;
	Node<T> *searchNode(T, Node<T>*);

public:
	BST();
	~BST();
	void insertNode(T);
	void getNode(T);
	void preOrder();
	void viewPreOrder(Node<T>*);
	void postOrder();
	void viewPostOrder(Node<T>*);


};

template<typename T>
inline Node<T>* BST<T>::searchNode(T pData, Node<T> *pCurr)
{
	if (pCurr->mData == pData) return nullptr;
	else
	{
		if (pCurr->mData < pData)
		{
			// if right is nullptr
			if (pCurr->right == nullptr) return pCurr;
			else return searchNode(pData, pCurr->right);
		}
		else
		{
			// if left is nullptr
			if (pCurr->left == nullptr) return pCurr;
			else return searchNode(pData, pCurr->left);
		}
	}
}

template<typename T>
inline BST<T>::BST()
{
}

template<typename T>
inline BST<T>::~BST()
{
}

template<typename T>
inline void BST<T>::insertNode(T pData)
{
	// When the root is pointing to nullptr
	if (this->root == nullptr)
	{
		root = new Node<T>(pData);
	
	}
	// When there is root
	else
	{
		Node<T>*curr = searchNode(pData, this->root);
		// When there is same data
		if (curr == nullptr)
		{
			cout << "[ERROR] There is same node, please try with other node" << endl;
		}
		// When there is no same data
		else
		{
			if (curr->mData < pData) curr->right = new Node<T>(pData);
			else curr->left = new Node<T>(pData);
		}
		
	}
	
}

template<typename T>
inline void BST<T>::getNode(T pData)
{
	Node<T> *pNode = searchNode(pData, root);
	if (pNode == nullptr) cout << "There is " << pData << endl;
	else cout << "There is no what you finding" << endl;
}

template<typename T>
inline void BST<T>::preOrder()
{
	cout << "PreOrderd: ";
	viewPreOrder(this->root);
}

template<typename T>
inline void BST<T>::viewPreOrder(Node<T>* pCurr)
{
	if (pCurr == nullptr) return;
	cout << pCurr->mData << " ";
	viewPreOrder(pCurr->left);
	viewPreOrder(pCurr->right);
}

template<typename T>
inline void BST<T>::postOrder()
{
	cout << "PostOrderd: ";
	viewPostOrder(this->root);
}

template<typename T>
inline void BST<T>::viewPostOrder(Node<T>* pCurr)
{
	if (pCurr == nullptr) return;
	cout << pCurr->mData << " ";
	viewPostOrder(pCurr->right);
	viewPostOrder(pCurr->left);
}

