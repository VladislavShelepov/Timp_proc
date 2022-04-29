#pragma once
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"
using namespace std;

enum type { tree, bush, flower };
enum place { tundra, desert, steppe, forest };
struct plant {
	string name = "";
	void* obj = NULL;
	type key;
	place origin;
};
plant* InPlant(ifstream& ifst);
int countLetters(plant& pt);