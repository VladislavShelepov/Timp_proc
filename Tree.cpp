#include "Tree.h"
using namespace std;

void InTree(ifstream& ifst, tree_plant& f) {
	ifst >> f.name;
	ifst >> f.age;
}

void OutTree(ofstream& ofst, tree_plant& f) {
	ofst << "Name: " << f.name << endl;
	ofst << "It is a tree. It's age is " << f.age << " days." << endl;
}
int CountLettersTree(ofstream& ofst, tree_plant& f) {
	int cnt = 0;
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	for (int i = 0; i < f.name.length(); i++)
	{
		if (letters.find(f.name[i]) < letters.length())cnt++;
	}
	ofst << "count of consonants: " << cnt << endl;
	return cnt;
}
int countLetters(tree_plant& f)
{
	int cnt = 0;
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	for (int i = 0; i < f.name.length(); i++)
	{
		if (letters.find(f.name[i]) < letters.length())cnt++;
	}
	return cnt;
}