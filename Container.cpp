#include "Container.h"
using namespace std;

void Clear(Container* c) {
	c->Current = NULL;
	c->length = 0;
	c->Head = 0;
}

void InCont(ifstream& ifst, Container* c) {
	while (!ifst.eof()) {

		Node* newNode = new Node;
		newNode->plnt = InPlant(ifst);
		//tree_plant* ptnt = (tree_plant*)newNode->plnt->obj;
		if (c->Head == NULL)
		{
			c->Head = newNode;
			c->Head->next = newNode;
			c->Head->prev = newNode;
			c->length = 1;
		}
		else
		{
			c->Current = c->Head;
			while (c->Current->next != c->Head)
			{
				c->Current = c->Current->next;
			}
			c->Current->next = newNode;
			c->Current->next->prev = c->Current;
			c->Current = c->Current->next;
			c->Current->next = c->Head;
			c->Head->prev = c->Current;
			c->length++;
		}
	}
}
void OutPlant(ofstream& ofst, Node* Container)
{
	if (Container->plnt->key == tree)
	{
		tree_plant* pl;
		pl = (tree_plant*)(Container->plnt->obj);
		OutTree(ofst, *pl);
	}
	else
	{
		bush_plant* pn;
		pn = (bush_plant*)(Container->plnt->obj);
		OutBush(ofst, *pn);
	}
}

void OutCont(ofstream& ofst, Container* c) {
	ofst << "Container contents " << c->length << " elements." << endl;
	int i = 1;
	if (c->Head == NULL)
	{
		return;
	}
	c->Current = c->Head;
	do
	{
		ofst << i << ": ";
		OutPlant(ofst,c->Current);
		c->Current = c->Current->next;
		i++;
	} while (c->Current != c->Head);
}

void OutTrees(ofstream& ofst, Container* c) {
	ofst << "Only Trees: " << endl;
	int i = 1;
	if (c->Head == NULL)
	{
		return;
	}
	c->Current = c->Head;
	do
	{
		ofst << i << ": ";
		if (c->Current->plnt->key == tree)
		{
			OutPlant(ofst, c->Current);
		}
		else
		{
			ofst << endl;
		}
		c->Current = c->Current->next;
		i++;
	} while (c->Current != c->Head);
}