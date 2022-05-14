#include "Plant.h"
using namespace std;

Plant* inPlant(ifstream& ifst) 
{
	Plant* ptant = new Plant;
	TreePlant* f;
	BushPlant* a;
	FlowerPlant* flow;
	int typeOfFlower = 0;
	ifst >> typeOfFlower;
	ifst >> ptant->name;
	int o;
	switch (typeOfFlower) {
	case 1:
		ptant->key = tree;
		f = new TreePlant;
		inTree(ifst, *f);
		ptant->obj = (void*)f;
		break;
	case 2:
		ptant->key = bush;
		a = new BushPlant;
		inBush(ifst, *a);
		ptant->obj = (void*)a;
		break;
	case 3:
		ptant->key = flower;
		flow = new FlowerPlant;
		inFlower(ifst, *flow);
		ptant->obj = (void*)flow;
		break;
	default:
		return 0;
	}
	ifst >> o;
	switch (o)
	{
	case 1:
		ptant->origin = tundra;
		break;
	case 2:
		ptant->origin = desert;
		break;
	case 3:
		ptant->origin = steppe;
		break;
	case 4:
		ptant->origin = forest;
		break;
	}
	return ptant;
}

int countLetters(Plant& pt)
{
		int cnt = 0;
		string LETTERS = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
		for (int i = 0; i < pt.name.length(); i++)
		{
			if (LETTERS.find(pt.name[i]) < LETTERS.length())cnt++;
		}
		return cnt;
}