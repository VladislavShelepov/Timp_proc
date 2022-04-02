#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct tree_plant {
	string name = "";
	long age = 0;
};
void InTree(ifstream& ifst, tree_plant& f);
void OutTree(ofstream& ofst, tree_plant& f);
int CountLettersTree(ofstream& ofst, tree_plant& f);