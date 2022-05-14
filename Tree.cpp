#include "Tree.h"
using namespace std;

void inTree(ifstream& ifst, TreePlant& f) {
	ifst >> f.age;
}

void outTree(ofstream& ofst, TreePlant& f) {
	ofst << "It is a tree. It's age is " << f.age << " days." << endl;
}
