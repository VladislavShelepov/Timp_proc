#include "Flower.h"
using namespace std;

void inFlower(ifstream& ifst, FlowerPlant& a) {
	int b;
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
}

void outFlower(ofstream& ofst, FlowerPlant& a) {
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
}
