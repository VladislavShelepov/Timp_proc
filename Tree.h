#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum placeTree { tundra, desert, steppe, forest };
struct tree_plant {
	string name = "";
	long age = 0;
	placeTree origin;
};
void InTree(ifstream& ifst, tree_plant& f);
void OutTree(ofstream& ofst, tree_plant& f);