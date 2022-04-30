#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Shele\Documents\GitHub\Timp_proc\Container.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_proc\Flower.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_proc\Plant.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_proc\Tree.cpp"
#include "C:\Users\Shele\Documents\GitHub\Timp_proc\Bush.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

			TEST_METHOD(TestCountLetters)
			{
				plant pt;
				pt.name = "bbbbab";
				int res = countLetters(pt);
				int exp = 5;
				Assert::AreEqual(exp, res);
			}
			TEST_METHOD(TestCompare)
			{
				plant pt1, pt2;
				pt1.name = "bbbb";
				pt2.name = "bb";
				Node* n1, * n2;
				n1 = new Node;
				n2 = new Node;
				n1->plnt = &pt1;
				n2->plnt = &pt2;
				bool res = Compare(n1, n2);
				bool exp = false;
				Assert::AreEqual(exp, res);
			}
			TEST_METHOD(TestIn)
			{
				ifstream ifst("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/inTest.txt");

				tree_plant* f = new tree_plant;
				bush_plant* d = new bush_plant;
				flower_plant* a = new flower_plant;

				InTree(ifst, *f);
				InBush(ifst, *d);
				InFlower(ifst, *a);

				Assert::AreEqual(long(10), f->age);
				Assert::AreEqual(int(d->blossom), int(January));
				Assert::AreEqual(int(a->t), int(domestic));
			}
			TEST_METHOD(TestInput)
			{
				ifstream ifst;
				ifst.open("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/inputTest.txt");
				Container c;

				bool res = true;
				bool exp = true;

				//Assert::AreEqual(res, exp);
				InCont(ifst, &c);

				Container c1;
				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plnt->key = new tree;
				n1->fl->country = "USA";
				n1->fl->name = "Star_Wars";
				n1->fl->key = feature;
				feature_film* f;
				f = new feature_film;
				f->director = "Lucas";
				n1->fl->obj = (void*)f;

				n2 = new Node;
				n2->fl = new film;
				n2->fl->country = "Japan";
				n2->fl->name = "Cartoon1";
				n2->fl->key = animation;
				animation_film* a;
				a = new animation_film;
				a->woc = DRAWN;
				n2->fl->obj = (void*)a;

				n3 = new Node;
				n3->fl = new film;
				n3->fl->country = "Italy";
				n3->fl->name = "Doc2";
				n3->fl->key = documentary;
				documentary_film* d;
				d = new documentary_film;
				d->year = 2005;
				n3->fl->obj = (void*)d;

				c1.head = n1;
				c1.head->next = n2;
				c1.head->next->next = n3;
				c1.size = 3;

				Assert::AreEqual(int(c1.size), int(c.size));

				c.curr = c.head;
				c1.curr = c1.head;
				while (c1.curr != NULL)
				{

					Assert::AreEqual(string(c1.curr->fl->country), string(c.curr->fl->country));
					Assert::AreEqual(int(c1.curr->fl->key), int(c.curr->fl->key));
					Assert::AreEqual(string(c1.curr->fl->name), string(c.curr->fl->name));

					if (c1.curr->fl->key == feature)
					{
						Assert::AreEqual(((feature_film*)c1.curr->fl->obj)->director, ((feature_film*)c.curr->fl->obj)->director);
					}
					if (c1.curr->fl->key == animation)
					{
						Assert::AreEqual(int(((animation_film*)c1.curr->fl->obj)->woc), int(((animation_film*)c.curr->fl->obj)->woc));
					}
					if (c1.curr->fl->key == documentary)
					{
						Assert::AreEqual(((documentary_film*)c1.curr->fl->obj)->year, ((documentary_film*)c.curr->fl->obj)->year);
					}
					c.curr = c.curr->next;
					c1.curr = c1.curr->next;
				}
			}
			//TEST_METHOD(TestOut)
			//{
			//	ofstream ofst("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/outTest.txt");
			//	bool exp = true;
			//	bool res = false;

			//	feature_film* f = new feature_film;
			//	f->director = "Director";

			//	documentary_film* d = new documentary_film;
			//	d->year = 2000;

			//	animation_film* a = new animation_film;
			//	a->woc = DOLL;

			//	Out(ofst, *f);
			//	Out(ofst, *d);
			//	Out(ofst, *a);

			//	ifstream ifst1("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/outTest.txt");
			//	ifstream ifst2("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/expOutTest.txt");
			//	char c1, c2;
			//	while (ifst1.get(c1) && ifst2.get(c2))
			//	{

			//		Assert::AreEqual(c1, c2);
			//	}
			//}
			//TEST_METHOD(TestOutput)
			//{
			//	ofstream ofst;
			//	ofst.open("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/outputTest.txt");
			//	container c;

			//	bool res = true;
			//	bool exp = true;

			//	Node* n1, * n2, * n3;

			//	n1 = new Node;
			//	n1->fl = new film;
			//	n1->fl->country = "USA";
			//	n1->fl->name = "Star_Wars";
			//	n1->fl->key = feature;
			//	feature_film* f;
			//	f = new feature_film;
			//	f->director = "Lucas";
			//	n1->fl->obj = (void*)f;

			//	n2 = new Node;
			//	n2->fl = new film;
			//	n2->fl->country = "Japan";
			//	n2->fl->name = "Cartoon1";
			//	n2->fl->key = animation;
			//	animation_film* a;
			//	a = new animation_film;
			//	a->woc = DRAWN;
			//	n2->fl->obj = (void*)a;

			//	n3 = new Node;
			//	n3->fl = new film;
			//	n3->fl->country = "Italy";
			//	n3->fl->name = "Doc2oaa";
			//	n3->fl->key = documentary;
			//	documentary_film* d;
			//	d = new documentary_film;
			//	d->year = 2005;
			//	n3->fl->obj = (void*)d;

			//	c.head = n1;
			//	c.head->next = n2;
			//	c.head->next->next = n3;
			//	c.size = 3;

			//	OutCont(ofst, &c);

			//	ifstream ifst1("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/outputTest.txt");
			//	ifstream ifst2("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/expOutputTest.txt");
			//	char c1, c2;
			//	while (ifst1.get(c1) && ifst2.get(c2))
			//	{
			//		Assert::AreEqual(c1, c2);
			//	}
			//}
			//TEST_METHOD(TestClear)
			//{
			//	container c;

			//	bool res = true;
			//	bool exp = true;

			//	Node* n1, * n2, * n3;

			//	n1 = new Node;
			//	n1->fl = new film;
			//	n1->fl->country = "USA";
			//	n1->fl->name = "Star_Wars";
			//	n1->fl->key = feature;
			//	feature_film* f;
			//	f = new feature_film;
			//	f->director = "Lucas";
			//	n1->fl->obj = (void*)f;

			//	n2 = new Node;
			//	n2->fl = new film;
			//	n2->fl->country = "Japan";
			//	n2->fl->name = "Cartoon1";
			//	n2->fl->key = animation;
			//	animation_film* a;
			//	a = new animation_film;
			//	a->woc = DRAWN;
			//	n2->fl->obj = (void*)a;

			//	n3 = new Node;
			//	n3->fl = new film;
			//	n3->fl->country = "Italy";
			//	n3->fl->name = "Doc2oaa";
			//	n3->fl->key = documentary;
			//	documentary_film* d;
			//	d = new documentary_film;
			//	d->year = 2005;
			//	n3->fl->obj = (void*)d;

			//	c.head = n1;
			//	c.head->next = n2;
			//	c.head->next->next = n3;
			//	c.size = 3;

			//	Clear(&c);
			//	Assert::AreEqual(true, c.head == NULL);
			//	Assert::AreEqual(true, c.curr == NULL);
			//	Assert::AreEqual(true, c.size == 0);
			//}
			//TEST_METHOD(TestSort)
			//{
			//	container c1;
			//	container c;

			//	ifstream ifst("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/inputTest.txt");

			//	bool res = true;
			//	bool exp = true;

			//	Node* n1, * n2, * n3;

			//	n1 = new Node;
			//	n1->fl = new film;
			//	n1->fl->country = "USA";
			//	n1->fl->name = "Star_Wars";
			//	n1->fl->key = feature;
			//	feature_film* f;
			//	f = new feature_film;
			//	f->director = "Lucas";
			//	n1->fl->obj = (void*)f;

			//	n2 = new Node;
			//	n2->fl = new film;
			//	n2->fl->country = "Japan";
			//	n2->fl->name = "Cartoon1";
			//	n2->fl->key = animation;
			//	animation_film* a;
			//	a = new animation_film;
			//	a->woc = DRAWN;
			//	n2->fl->obj = (void*)a;

			//	n3 = new Node;
			//	n3->fl = new film;
			//	n3->fl->country = "Italy";
			//	n3->fl->name = "Doc2";
			//	n3->fl->key = documentary;
			//	documentary_film* d;
			//	d = new documentary_film;
			//	d->year = 2005;
			//	n3->fl->obj = (void*)d;

			//	c1.head = n2;
			//	c1.head->next = n1;
			//	c1.head->next->next = n3;
			//	c1.size = 3;

			//	InCont(ifst, &c);
			//	Sort(c);

			//	Assert::AreEqual(int(c1.size), int(c.size));

			//	c.curr = c.head;
			//	c1.curr = c1.head;
			//	while (c1.curr != NULL)
			//	{

			//		Assert::AreEqual(string(c1.curr->fl->country), string(c.curr->fl->country));
			//		Assert::AreEqual(int(c1.curr->fl->key), int(c.curr->fl->key));
			//		Assert::AreEqual(string(c1.curr->fl->name), string(c.curr->fl->name));

			//		if (c1.curr->fl->key == feature)
			//		{
			//			Assert::AreEqual(((feature_film*)c1.curr->fl->obj)->director, ((feature_film*)c.curr->fl->obj)->director);
			//		}
			//		if (c1.curr->fl->key == animation)
			//		{
			//			Assert::AreEqual(int(((animation_film*)c1.curr->fl->obj)->woc), int(((animation_film*)c.curr->fl->obj)->woc));
			//		}
			//		if (c1.curr->fl->key == documentary)
			//		{
			//			Assert::AreEqual(((documentary_film*)c1.curr->fl->obj)->year, ((documentary_film*)c.curr->fl->obj)->year);
			//		}
			//		c.curr = c.curr->next;
			//		c1.curr = c1.curr->next;
			//	}
			//}
			//TEST_METHOD(TestOutFeature)
			//{
			//	ofstream ofst;
			//	ofst.open("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/outFeature.txt");
			//	container c;

			//	bool res = true;
			//	bool exp = true;

			//	Node* n1, * n2, * n3;

			//	n1 = new Node;
			//	n1->fl = new film;
			//	n1->fl->country = "USA";
			//	n1->fl->name = "Star_Wars";
			//	n1->fl->key = feature;
			//	feature_film* f;
			//	f = new feature_film;
			//	f->director = "Lucas";
			//	n1->fl->obj = (void*)f;

			//	n2 = new Node;
			//	n2->fl = new film;
			//	n2->fl->country = "Japan";
			//	n2->fl->name = "Cartoon1";
			//	n2->fl->key = animation;
			//	animation_film* a;
			//	a = new animation_film;
			//	a->woc = DRAWN;
			//	n2->fl->obj = (void*)a;

			//	n3 = new Node;
			//	n3->fl = new film;
			//	n3->fl->country = "Italy";
			//	n3->fl->name = "Doc2oaa";
			//	n3->fl->key = documentary;
			//	documentary_film* d;
			//	d = new documentary_film;
			//	d->year = 2005;
			//	n3->fl->obj = (void*)d;

			//	c.head = n1;
			//	c.head->next = n2;
			//	c.head->next->next = n3;
			//	c.size = 3;

			//	OutFeature(ofst, &c);

			//	ifstream ifst1("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/outFeature.txt");
			//	ifstream ifst2("C:/Users/bushd/source/repos/TMPlab1Proc/UnitTestTMPlab4_Proc/expOutFeature.txt");
			//	char c1, c2;
			//	while (ifst1.get(c1) && ifst2.get(c2))
			//	{
			//		Assert::AreEqual(c1, c2);
			//	}
			//}
	};
}
