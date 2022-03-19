#include "Plant.h"
using namespace std;

plant* InPlant(ifstream& ifst) {
	plant* pt = new plant;
	tree_plant* f;
	bush_plant* a;
	int k = 0;
	ifst >> k;
	switch (k) {
	case 1:
		pt->key = tree;
		f = new tree_plant;
		InTree(ifst, *f);
		pt->obj = (void*)f;
		break;
	case 2:
		pt->key = bush;
		a = new bush_plant;
		InBush(ifst, *a);
		pt->obj = (void*)a;
		break;
	default:
		return 0;
	}
	tree_plant px;

	if (pt->key == tree) {
		px = *(tree_plant*)pt->obj;

	}
	return pt;
}