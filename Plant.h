#pragma once
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"
using namespace std;

enum type { tree, bush, flower };
enum place { tundra, desert, steppe, forest };
struct Plant 
{
	string name = "";
	void* obj = NULL;
	type key;
	place origin;
};
Plant* inPlant(ifstream& ifst);
int countLetters(Plant& pt);