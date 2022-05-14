#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum month { January, February, March, April, May, June, July, August, September, October, November, December };
struct BushPlant {
	month blossom;
};
void inBush(ifstream& ifst, BushPlant& a);
void outBush(ofstream& ofst, BushPlant& a);