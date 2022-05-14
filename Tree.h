#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct TreePlant 
{
	long age = 0;
};
void inTree(ifstream& ifst, TreePlant& f);
void outTree(ofstream& ofst, TreePlant& f);
