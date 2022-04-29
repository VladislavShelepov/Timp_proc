#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum Type { domestic, garden, wild };
struct flower_plant {
	Type t;
};
void InFlower(ifstream& ifst, flower_plant& a);
void OutFlower(ofstream& ofst, flower_plant& a);