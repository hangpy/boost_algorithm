
#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BST<int> bst;

	bst.insertNode(5);
	bst.insertNode(1);
	bst.insertNode(10);
	bst.insertNode(7);
	bst.insertNode(8);
	bst.insertNode(2);
	bst.insertNode(12);
	bst.insertNode(15);
	bst.insertNode(11);

	bst.preOrder();
	cout << endl;
	bst.postOrder();
	cout << endl;

	bst.getNode(20);
	bst.getNode(11);
	bst.getNode(1);

}
