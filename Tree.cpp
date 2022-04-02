#include "Tree.h"
using namespace std;

void InTree(ifstream& ifst, tree_plant& f) {
	ifst >> f.name;
	ifst >> f.age;
	int o;
	ifst >> o;
	switch (o)
	{
	case 1:
		f.origin = tundra;
		break;
	case 2:
		f.origin = desert;
		break;
	case 3:
		f.origin = steppe;
		break;
	case 4:
		f.origin = forest;
		break;
	}
}

void OutTree(ofstream& ofst, tree_plant& f) {
	ofst << "Name: " << f.name << endl;
	ofst << "It is a tree. It's age is " << f.age << " days." << endl;
	switch (f.origin)
	{
	case 0:
		ofst << "It grows in tundra." << endl;
		break;
	case 1:
		ofst << "It grows in desert." << endl;
		break;
	case 2:
		ofst << "It grows in steppe." << endl;
		break;
	case 3:
		ofst << "It grows in forest." << endl;
		break;
	}
}