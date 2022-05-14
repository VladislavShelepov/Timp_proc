#include "Container.h"
#include <string>
using namespace std;

void clear(Container* c) 
{
	c->current = NULL;
	c->length = 0;
	c->head = 0;
}

void inCont(ifstream& ifst, Container* c) 
{
	while (!ifst.eof()) 
	{
		Node* newNode = new Node;
		newNode->plant = inPlant(ifst);
		if (c->head == NULL)
		{
			c->head = newNode;
			c->head->next = newNode;
			c->head->prev = newNode;
			c->length = 1;
		}
		else
		{
			c->current = c->head;
			while (c->current->next != c->head)
			{
				c->current = c->current->next;
			}
			c->current->next = newNode;
			c->current->next->prev = c->current;
			c->current = c->current->next;
			c->current->next = c->head;
			c->head->prev = c->current;
			c->length++;
		}
	}
}
void outPlant(ofstream& ofst, Node* Container)
{
	ofst << "Name: " << Container->plant->name << endl;
	if (Container->plant->key == tree)
	{
		TreePlant* treePl;
		treePl = (TreePlant*)(Container->plant->obj);
		outTree(ofst, *treePl);
		ofst << "count of consonants: " << countLetters(*Container->plant) << endl;
	}
	else if (Container->plant->key == bush)
	{
		BushPlant* bushPl;
		bushPl = (BushPlant*)(Container->plant->obj);
		outBush(ofst, *bushPl);
		ofst << "count of consonants: " << countLetters(*Container->plant) << endl;
	}
	else
	{
		FlowerPlant* flowerPl;
		flowerPl = (FlowerPlant*)(Container->plant->obj);
		outFlower(ofst, *flowerPl);
		ofst << "count of consonants: " << countLetters(*Container->plant) <<  endl;
	}

	switch (Container->plant->origin)
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

void outCont(ofstream& ofst, Container* c) 
{
	ofst << "Container contents " << c->length << " elements." << endl;
	int i = 1;
	if (c->head == NULL)
	{
		return;
	}
	c->current = c->head;
	do
	{
		ofst << i << ": ";
		outPlant(ofst,c->current);
		c->current = c->current->next;
		i++;
	} while (c->current != c->head);
}

void outTrees(ofstream& ofst, Container* c) 
{
	ofst << "Only Trees: " << endl;
	int i = 1;
	if (c->head == NULL)
	{
		return;
	}

	c->current = c->head;
	do
	{
		ofst << i << ": ";
		if (c->current->plant->key == tree)
		{
			outPlant(ofst, c->current);
		}
		else if (c->current->plant->key == bush)
		{
			ofst << endl;
		}
		else if (c->current->plant->key == flower)
		{
			ofst << endl;
		}
	
		c->current = c->current->next;
		i++;
	} while (c->current != c->head);
}

bool compare(Node* p1, Node* p2)
{
	return countLetters(*p1->plant) < countLetters(*p2->plant);
}

void sort(Container& c)
{
	Node* current1 = c.head;
	Node* current2 = c.head;
	do {
		current2 = current1->next;
		while (current2 != c.head) {
			if (compare(current1, current2))
			{
				swap(current1->plant, current2->plant);
			}
			current2 = current2->next;
		}
		current1 = current1->next;
	} while (current1 != c.head);
}

bool fileCheck(ifstream& ifst, ofstream& ofst)
{
	bool result = true;
	string DIGITS = "0123456789";
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
	
	while (!ifst.eof())//type check
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
			if (!(DIGITS.find(tmps[i]) < DIGITS.length()))
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

		ifst.getline(tmp, 100, '\n'); //name
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: Name of the plant is a blank string.\n";
			result = false;
			exit(1);
		}
		
		switch (type)//for different types
		{
		case 1:
		{
			ifst.getline(tmp, 100, '\n');//tree - age
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The tree's age is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(DIGITS.find(tmps[i]) < DIGITS.length()))
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
			ifst.getline(tmp, 100, '\n');//bush - blossom
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The flowering month is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(DIGITS.find(tmps[i]) < DIGITS.length()))
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
			ifst.getline(tmp, 100, '\n'); // flower - type
			tmps = (tmp);
			if (tmps == "")
			{
				cout << cnt << " Error: The flower's type is a blank string.\n";
				result = false;
				exit(1);
			}
			for (int i = 0; i < tmps.length(); i++)
			{
				if (!(DIGITS.find(tmps[i]) < DIGITS.length()))
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
		
		ifst.getline(tmp, 100, '\n'); //origin
		tmps = (tmp);
		if (tmps == "")
		{
			cout << cnt << " Error: The origin is a blank string.\n";
			result = false;
			exit(1);
		}
		for (int i = 0; i < tmps.length(); i++)
		{
			if (!(DIGITS.find(tmps[i]) < DIGITS.length()))
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
		cnt++;
	}
}