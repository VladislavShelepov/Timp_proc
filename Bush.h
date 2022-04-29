#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum month { January, February, March, April, May, June, July, August, September, October, November, December };
struct bush_plant {
	month blossom;
};
void InBush(ifstream& ifst, bush_plant& a);
void OutBush(ofstream& ofst, bush_plant& a);