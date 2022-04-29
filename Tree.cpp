#include "Tree.h"
using namespace std;

void InTree(ifstream& ifst, tree_plant& f) {
	ifst >> f.age;
}

void OutTree(ofstream& ofst, tree_plant& f) {
	ofst << "It is a tree. It's age is " << f.age << " days." << endl;
}
