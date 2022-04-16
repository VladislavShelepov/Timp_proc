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
	Container c;

	string s1 = argv[1], s2 = argv[2];
	InCont(ifst, &c);
	ofst << "Filled container. " << endl;
	OutCont(ofst, &c);
	OutTrees(ofst, &c);
	Clear(&c);
	ofst << "Empty container. " << endl;
	OutCont(ofst, &c);
	cout << "Stop" << endl;
	return 0;
}