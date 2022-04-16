#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum Type { domestic, garden, wild };
enum placeFlower { tundraF, desertF, steppeF, forestF };
struct flower_plant {
	string name = "";
	Type t;
	placeFlower origin;
};
void InFlower(ifstream& ifst, flower_plant& a);
void OutFlower(ofstream& ofst, flower_plant& a);
int CountLettersFlower(ofstream& ofst, flower_plant& f);
int countLetters(flower_plant& f);