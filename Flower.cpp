#include "Flower.h"
using namespace std;

void InFlower(ifstream& ifst, flower_plant& a) {
	ifst >> a.name;
	int b,o;
	ifst >> b;
	switch (b)
	{
	case 1:
		a.t = domestic;
		break;
	case 2:
		a.t = garden;
		break;
	case 3:
		a.t = wild;
		break;
	}
	ifst >> o;
	switch (o)
	{
	case 1:
		a.origin = tundraF;
		break;
	case 2:
		a.origin = desertF;
		break;
	case 3:
		a.origin = steppeF;
		break;
	case 4:
		a.origin = forestF;
		break;
	}
}

void OutFlower(ofstream& ofst, flower_plant& a) {
	ofst << "Name: " << a.name << endl;
	switch (a.t)
	{
	case 0:
		ofst << "It is a flower. It's domestic." << endl;
		break;
	case 1:
		ofst << "It is a flower. It's garden." << endl;
		break;
	case 2:
		ofst << "It is a flower. It's wild." << endl;
		break;
	}
	switch (a.origin)
	{
	case 0:
		ofst << "It grows in tundra." << endl;
		break;
	case 1:
		ofst << "It grows in desert." << endl;
		break;
	case 2:
		ofst << "It grows in steppe." << endl;
		break;
	case 3:
		ofst << "It grows in forest." << endl;
		break;
	}
}
int CountLettersFlower(ofstream& ofst, flower_plant& f) {
	int cnt = 0;
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	for (int i = 0; i < f.name.length(); i++)
	{
		if (letters.find(f.name[i]) < letters.length())cnt++;
	}
	ofst << "count of consonants: " << cnt << endl;
	return cnt;
}
int countLetters(flower_plant& f)
{
	int cnt = 0;
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	for (int i = 0; i < f.name.length(); i++)
	{
		if (letters.find(f.name[i]) < letters.length())cnt++;
	}
	return cnt;
}