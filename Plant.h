#pragma once
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Bush.h"
#include "Flower.h"
using namespace std;

enum type { tree, bush, flower };
struct plant {
	void* obj = NULL;
	type key;

};
plant* InPlant(ifstream& ifst);