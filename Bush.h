#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum placeBush { tundraB, desertB, steppeB, forestB };
enum month { January, February, March, April, May, June, July, August, September, October, November, December };
struct bush_plant {
	string name = "";
	month blossom;
	placeBush origin;
};
void InBush(ifstream& ifst, bush_plant& a);
void OutBush(ofstream& ofst, bush_plant& a);