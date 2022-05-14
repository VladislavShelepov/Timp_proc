#pragma once
//#include <iostream>
//#include <fstream>
#include "Plant.h"

using namespace std;

struct Node {
	Plant* plant = NULL;
    Node* next;
    Node* prev;
};

struct Container {
	int length = 0;
	Node* current = NULL;
	Node* head = NULL;
};
void clear(Container* c);
void inCont(ifstream& ifst, Container* c);
void outCont(ofstream& ofst, Container* c);
bool compare(Node* p1, Node* p2);
void sort(Container& c);
void outPlant(ofstream& ofst, Node* Container);
void outTrees(ofstream& ofst, Container* c);

bool fileCheck(ifstream& ifst, ofstream& ofst);