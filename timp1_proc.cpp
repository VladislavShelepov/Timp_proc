// timp1_proc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include "Container.h"
using namespace std;

using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;

	fileCheck(ifst, ofst);

	ifst.close();
	ifst.open(argv[1]);

	Container c;

	string s1 = argv[1], s2 = argv[2];
	inCont(ifst, &c);
	ofst << "Filled container. " << endl;
	outCont(ofst, &c);
	ofst << endl;
	ofst << "Sorted container. " << endl;
	sort(c);
	outCont(ofst, &c);
	outTrees(ofst, &c);
	clear(&c);
	ofst << "Empty container. " << endl;
	outCont(ofst, &c);
	cout << "Stop" << endl;
	return 0;
}