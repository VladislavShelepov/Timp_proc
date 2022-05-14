#include "Container.h"
#include <string>
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
	ofst << "Name: " << Container->plnt->name << endl;
	if (Container->plnt->key == tree)
	{
		tree_plant* pl;
		pl = (tree_plant*)(Container->plnt->obj);
		OutTree(ofst, *pl);
		ofst << "count of consonants: " << countLetters(*Container->plnt) << endl;
	}
	else if (Container->plnt->key == bush)
	{
		bush_plant* pn;
		pn = (bush_plant*)(Container->plnt->obj);
		OutBush(ofst, *pn);
		ofst << "count of consonants: " << countLetters(*Container->plnt) << endl;
	}
	else
	{
		flower_plant* pf;
		pf = (flower_plant*)(Container->plnt->obj);
		OutFlower(ofst, *pf);
		ofst << "count of consonants: " << countLetters(*Container->plnt) <<  endl;
	}
	switch (Container->plnt->origin)
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

void OutCont(ofstream& ofst, Container* c) {
	ofst << "Container contents " << c->length << " elements." << endl;
	int i = 1;
	if (c->Head == NULL)
	{
		return;
	}
	//Sort(*c);
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
		else if (c->Current->plnt->key == bush)
		{
			ofst << endl;
		}
		else if (c->Current->plnt->key == flower)
		{
			ofst << endl;
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
		while (curr2 != c.Head) {
			if (Compare(curr1, curr2))
			{
				swap(curr1->plnt, curr2->plnt);
			}
			curr2 = curr2->next;
		}
		curr1 = curr1->next;
	} while (curr1 != c.Head);
}

bool fileCheck(ifstream& ifst, ofstream& ofst)
{
	bool result = true;
	string digits = "0123456789";
	char tmp[100];
	string tmps;


	if (!ifst.is_open())
	{
		cout << "Input file was not found.";
		exit(1);
	}
	if (!ofst.is_open())
	{
		cout << "Output file was not found.";
		exit(1);
	}
	int cnt = 1;
	//type check
	while (!ifst.eof())
	{
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Type is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(digits.find(tmps[i]) < digits.length()))
			{
				cout << cnt << " Error: Type definition contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int type = std::stoi(tmps);
		if (type <= 0 || type > 3)
		{
			cout << cnt << " Error: Type is out of range.\n";
			result = false;
			exit(1);
		}
		//
		//name
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Name of the plant is a blank string.\n";
			result = false;
			exit(1);
		}
		//
		//for different types
		switch (type)
		{
		case 1:
		{
			//tree - age
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The tree's age is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(digits.find(tmps[i]) < digits.length()))
				{
					cout << cnt << " Error: The tree's age contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int age = std::stoi(tmps);
			if (age <= 0)
			{
				cout << cnt << " Error: The tree's age is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		case 2:
		{
			//bush - blossom
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The flowering month is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(digits.find(tmps[i]) < digits.length()))
				{
					cout << cnt << " Error: The flowering month contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int type = std::stoi(tmps);
			if (type <= 0 || type > 12)
			{
				cout << cnt << " Error: The flowering month is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		case 3:
		{
			// flower - type
			ifst.getline(tmp, 100, '\n');
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The flower's type is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(digits.find(tmps[i]) < digits.length()))
				{
					cout << cnt << " Error: The flower's type contains incorrect characters.\n";
					result = false;
					exit(1);
				}
			}
			int type = std::stoi(tmps);
			if (type <= 0 || type > 3)
			{
				cout << cnt << " Error: The flower's type is out of range.\n";
				result = false;
				exit(1);
			}
			break;
		}
		}
		//
		//origin
		ifst.getline(tmp, 100, '\n');
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: The origin is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(digits.find(tmps[i]) < digits.length()))
			{
				cout << cnt << " Error: The origin contains incorrect characters.\n";
				result = false;
				exit(1);
			}
		}
		int origin = std::stoi(tmps);
		if (origin <= 0 || origin > 4)
		{
			cout << cnt << " Error: The origin is out of range.\n";
			result = false;
			exit(1);
		}
		//
		cnt++;
	}
}