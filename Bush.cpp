#include "Bush.h"
using namespace std;

void InBush(ifstream& ifst, bush_plant& a) {
	ifst >> a.name;
	int t;
	ifst >> t;
	switch (t)
	{
	case 1:
		a.blossom = January;
		break;
	case 2:
		a.blossom = February;
		break;
	case 3:
		a.blossom = March;
		break;
	case 4:
		a.blossom = April;
		break;
	case 5:
		a.blossom = May;
		break;
	case 6:
		a.blossom = June;
		break;
	case 7:
		a.blossom = July;
		break;
	case 8:
		a.blossom = August;
		break;
	case 9:
		a.blossom = September;
		break;
	case 10:
		a.blossom = October;
		break;
	case 11:
		a.blossom = November;
		break;
	case 12:
		a.blossom = December;
		break;
	}
}

void OutBush(ofstream& ofst, bush_plant& a) {
	ofst << "Name: " << a.name << endl;
	switch (a.blossom)
	{
	case 0:
		ofst << "It is a bush. It's flowering month is January." << endl;
		break;
	case 1:
		ofst << "It is a bush. It's flowering month is February." << endl;
		break;
	case 2:
		ofst << "It is a bush. It's flowering month is March." << endl;
		break;
	case 3:
		ofst << "It is a bush. It's flowering month is April." << endl;
		break;
	case 4:
		ofst << "It is a bush. It's flowering month is May." << endl;
		break;
	case 5:
		ofst << "It is a bush. It's flowering month is June." << endl;
		break;
	case 6:
		ofst << "It is a bush. It's flowering month is July." << endl;
		break;
	case 7:
		ofst << "It is a bush. It's flowering month is August." << endl;
		break;
	case 8:
		ofst << "It is a bush. It's flowering month is September." << endl;
		break;
	case 9:
		ofst << "It is a bush. It's flowering month is October." << endl;
		break;
	case 10:
		ofst << "It is a bush. It's flowering month is November." << endl;
		break;
	case 11:
		ofst << "It is a bush. It's flowering month is December." << endl;
		break;
	}
}
int CountLettersBush(ofstream& ofst, bush_plant& a) {
	int cnt = 0;
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	for (int i = 0; i < a.name.length(); i++)
	{
		if (letters.find(a.name[i]) < letters.length())cnt++;
	}
	ofst << "count of consonants: " << cnt << endl;
	return cnt;
}
int countLetters(bush_plant& a)
{
	int cnt = 0;
	string letters = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	for (int i = 0; i < a.name.length(); i++)
	{
		if (letters.find(a.name[i]) < letters.length())cnt++;
	}
	return cnt;
}