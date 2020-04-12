#include <iostream>
#include "TreeSolutionTest.h"
#include "BaseTree.h"


using namespace std;

TreeSolutionTest::TreeSolutionTest()
{
}


TreeSolutionTest::~TreeSolutionTest()
{
}

void TreeSolutionTest::run() {
	cout << "Hello Tree" << endl;
	BaseTree tree = { -10,-3,0,5,9 };
	tree.infixOrder(tree.getRoot());
}