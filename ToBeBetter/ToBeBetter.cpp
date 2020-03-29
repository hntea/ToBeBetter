#include <iostream>
#include "LinkList/LinkList.h"
#include "Base/BaseSolution.h"
#include "LinkList/LinkSolutionTest.h"
using namespace std;


void exec_solution(BaseSolution* solution) {
	if(solution!=nullptr)
		solution->run();
}

int main(int args, char** arv)
{
	cout << "Hello word!" << endl;
	BaseSolution* test = new LinkSolutionTest();
	exec_solution(test);
	system("pause");
}