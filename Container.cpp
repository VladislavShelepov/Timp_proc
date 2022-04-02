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
void OutCont(ofstream& ofst, Container* c) {
	ofst << "Container contents " << c->length << " elements." << endl;
	Sort(*c);
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
			tree_plant* pl;
			pl = (tree_plant*)(c->Current->plnt->obj);
			OutTree(ofst, *pl);
			ofst << "Count of letters = " << countLetters(*(c->Current->plnt)) << endl;
		}
		else
		{
			bush_plant* pn;
			pn = (bush_plant*)(c->Current->plnt->obj);
			OutBush(ofst, *pn);
			ofst << "Count of letters = " << countLetters(*(c->Current->plnt)) << endl;
		}
		c->Current = c->Current->next;
		i++;
	} while (c->Current != c->Head);
}

bool Compare(Node* p1, Node* p2)
{
	return countLetters(*p1->plnt) < countLetters(*p2->plnt);
}
void Sort(Container& c)
{
	Node* curr1 = c.Head;
	
	Node* curr2 = c.Head;
	do {
		curr2 = curr1->next;
		while (curr2 != NULL) {
			if (Compare(curr1, curr2))
			{
				swap(curr1->plnt, curr2->plnt);
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	} while (curr1 != c.Head);
}