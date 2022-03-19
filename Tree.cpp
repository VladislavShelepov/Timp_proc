#include "Tree.h"
using namespace std;

void InTree(ifstream& ifst, tree_plant& f) {
	ifst >> f.name;
	ifst >> f.age;
}

void OutTree(ofstream& ofst, tree_plant& f) {
	ofst << "Name: " << f.name << endl;
	ofst << "It is a tree. It's age is " << f.age << " days." << endl;
}