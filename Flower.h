#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum typeOfFlower { domestic, garden, wild };
struct FlowerPlant 
{
	typeOfFlower t;
};
void inFlower(ifstream& ifst, FlowerPlant& a);
void outFlower(ofstream& ofst, FlowerPlant& a);