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
				n1->plnt = new plant;
				n1->plnt->name = "derevo";
				n1->plnt->origin = desert;
				n1->plnt->key = tree;
				tree_plant* t;
				t = new tree_plant;
				t->age = 10;
				n1->plnt->obj = (void*)t;

				n2 = new Node;
				n2->plnt = new plant;
				n2->plnt->name = "bush";
				n2->plnt->origin = tundra;
				n2->plnt->key = bush;
				bush_plant* b;
				b = new bush_plant;
				b->blossom = July;
				n2->plnt->obj = (void*)b;

				n3 = new Node;
				n3->plnt = new plant;
				n3->plnt->name = "cvetocheck";
				n3->plnt->origin = steppe;
				n3->plnt->key = flower;
				flower_plant* f;
				f = new flower_plant;
				f->t = garden;
				n3->plnt->obj = (void*)f;

				c1.Head = n1;
				c1.Head->next = n2;
				c1.Head->next->next = n3;
				c1.Head->prev = c1.Head->next->next;
				c1.Head->next->prev = c1.Head;
				c1.Head->next->next->prev = c1.Head->next;
				c1.length = 3;

				Assert::AreEqual(int(c1.length), int(c.length));

				c.Current = c.Head;
				c1.Current = c1.Head;
				while (c.Current->next != c.Head)
				{

					Assert::AreEqual(string(c1.Current->plnt->name), string(c.Current->plnt->name));
					Assert::AreEqual(int(c1.Current->plnt->origin), int(c.Current->plnt->origin));

					if (c1.Current->plnt->key == tree)
					{
						Assert::AreEqual(((tree_plant*)c1.Current->plnt->obj)->age, ((tree_plant*)c.Current->plnt->obj)->age);
					}
					if (c1.Current->plnt->key == bush)
					{
						Assert::AreEqual(int(((bush_plant*)c1.Current->plnt->obj)->blossom), int(((bush_plant*)c.Current->plnt->obj)->blossom));
					}
					if (c1.Current->plnt->key == flower)
					{
						Assert::AreEqual(int(((flower_plant*)c1.Current->plnt->obj)->t), int(((flower_plant*)c.Current->plnt->obj)->t));
					}
					c.Current = c.Current->next;
					c1.Current = c1.Current->next;
				}
			}
			TEST_METHOD(TestOut)
			{
				ofstream ofst("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outTest.txt");
				bool exp = true;
				bool res = false;

				tree_plant* t = new tree_plant;
				t->age = 10;

				bush_plant* b = new bush_plant;
				b->blossom = July;

				flower_plant* f = new flower_plant;
				f->t = garden;

				OutTree(ofst, *t);
				OutBush(ofst, *b);
				OutFlower(ofst, *f);

				ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outTest.txt");
				ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/expOutTest.txt");
				char c1, c2;
				while (ifst1.get(c1) && ifst2.get(c2))
				{
					Assert::AreEqual(c1, c2);
				}
			}
			TEST_METHOD(TestOutput)
			{
				ofstream ofst;
				ofst.open("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outputTest.txt");
				Container c;

				bool res = true;
				bool exp = true;

				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plnt = new plant;
				n1->plnt->name = "derevo";
				n1->plnt->origin = desert;
				n1->plnt->key = tree;
				tree_plant* t;
				t = new tree_plant;
				t->age = 10;
				n1->plnt->obj = (void*)t;

				n2 = new Node;
				n2->plnt = new plant;
				n2->plnt->name = "bush";
				n2->plnt->origin = tundra;
				n2->plnt->key = bush;
				bush_plant* b;
				b = new bush_plant;
				b->blossom = July;
				n2->plnt->obj = (void*)b;

				n3 = new Node;
				n3->plnt = new plant;
				n3->plnt->name = "cvetocheck";
				n3->plnt->origin = steppe;
				n3->plnt->key = flower;
				flower_plant* f;
				f = new flower_plant;
				f->t = garden;
				n3->plnt->obj = (void*)f;

				c.Head = n1;
				c.Head->next = n2;
				c.Head->next->next = n3;
				c.Head->prev = c.Head->next->next;
				c.Head->next->prev = c.Head;
				c.Head->next->next->prev = c.Head->next;
				c.Head->next->next->next = c.Head;
				c.length = 3;
				c.Current = c.Head;

				OutCont(ofst, &c);

				ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outputTest.txt");
				ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/expOutputTest.txt");
				char c1, c2;
				while (ifst1.get(c1) && ifst2.get(c2))
				{
					Assert::AreEqual(c1, c2);
				}
			}
			TEST_METHOD(TestClear)
			{
				Container c;

				bool res = true;
				bool exp = true;

				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plnt = new plant;
				n1->plnt->name = "derevo";
				n1->plnt->origin = desert;
				n1->plnt->key = tree;
				tree_plant* t;
				t = new tree_plant;
				t->age = 10;
				n1->plnt->obj = (void*)t;

				n2 = new Node;
				n2->plnt = new plant;
				n2->plnt->name = "bush";
				n2->plnt->origin = tundra;
				n2->plnt->key = bush;
				bush_plant* b;
				b = new bush_plant;
				b->blossom = July;
				n2->plnt->obj = (void*)b;

				n3 = new Node;
				n3->plnt = new plant;
				n3->plnt->name = "cvetocheck";
				n3->plnt->origin = steppe;
				n3->plnt->key = flower;
				flower_plant* f;
				f = new flower_plant;
				f->t = garden;
				n3->plnt->obj = (void*)f;

				c.Head = n1;
				c.Head->next = n2;
				c.Head->next->next = n3;
				c.Head->prev = c.Head->next->next;
				c.Head->next->prev = c.Head;
				c.Head->next->next->prev = c.Head->next;
				c.Head->next->next->next = c.Head;
				c.length = 3;
				c.Current = c.Head;


				Clear(&c);
				Assert::AreEqual(true, c.Head == NULL);
				Assert::AreEqual(true, c.Current == NULL);
				Assert::AreEqual(true, c.length == 0);
			}
			TEST_METHOD(TestSort)
			{
				Container c1;
				Container c;

				ifstream ifst("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/sortTest.txt");

				bool res = true;
				bool exp = true;

				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plnt = new plant;
				n1->plnt->name = "derevo";
				n1->plnt->origin = desert;
				n1->plnt->key = tree;
				tree_plant* t;
				t = new tree_plant;
				t->age = 10;
				n1->plnt->obj = (void*)t;

				n2 = new Node;
				n2->plnt = new plant;
				n2->plnt->name = "bush";
				n2->plnt->origin = tundra;
				n2->plnt->key = bush;
				bush_plant* b;
				b = new bush_plant;
				b->blossom = July;
				n2->plnt->obj = (void*)b;

				n3 = new Node;
				n3->plnt = new plant;
				n3->plnt->name = "cvetocheck";
				n3->plnt->origin = steppe;
				n3->plnt->key = flower;
				flower_plant* f;
				f = new flower_plant;
				f->t = garden;
				n3->plnt->obj = (void*)f;

				c1.Head = n1;
				c1.Head->next = n2;
				c1.Head->next->next = n3;
				c1.Head->prev = c1.Head->next->next;
				c1.Head->next->prev = c1.Head;
				c1.Head->next->next->prev = c1.Head->next;
				c1.Head->next->next->next = c1.Head;
				c1.length = 3;
				//c.Current = c.Head;

				InCont(ifst, &c);
				Sort(c1);

				Assert::AreEqual(int(c1.length), int(c.length));

				c.Current = c.Head;
				c1.Current = c1.Head;
				while (c.Current->next != c.Head)
				{

					Assert::AreEqual(string(c1.Current->plnt->name), string(c.Current->plnt->name));
					Assert::AreEqual(int(c1.Current->plnt->origin), int(c.Current->plnt->origin));

					if (c1.Current->plnt->key == tree)
					{
						Assert::AreEqual(((tree_plant*)c1.Current->plnt->obj)->age, ((tree_plant*)c.Current->plnt->obj)->age);
					}
					if (c1.Current->plnt->key == bush)
					{
						Assert::AreEqual(int(((bush_plant*)c1.Current->plnt->obj)->blossom), int(((bush_plant*)c.Current->plnt->obj)->blossom));
					}
					if (c1.Current->plnt->key == flower)
					{
						Assert::AreEqual(int(((flower_plant*)c1.Current->plnt->obj)->t), int(((flower_plant*)c.Current->plnt->obj)->t));
					}
					c.Current = c.Current->next;
					c1.Current = c1.Current->next;
				}
			}
			TEST_METHOD(TestOutFeature)
			{
				ofstream ofst;
				ofst.open("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outTrees.txt");
				Container c;

				bool res = true;
				bool exp = true;

				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plnt = new plant;
				n1->plnt->name = "derevo";
				n1->plnt->origin = desert;
				n1->plnt->key = tree;
				tree_plant* t;
				t = new tree_plant;
				t->age = 10;
				n1->plnt->obj = (void*)t;

				n2 = new Node;
				n2->plnt = new plant;
				n2->plnt->name = "bush";
				n2->plnt->origin = tundra;
				n2->plnt->key = bush;
				bush_plant* b;
				b = new bush_plant;
				b->blossom = July;
				n2->plnt->obj = (void*)b;

				n3 = new Node;
				n3->plnt = new plant;
				n3->plnt->name = "cvetocheck";
				n3->plnt->origin = steppe;
				n3->plnt->key = flower;
				flower_plant* f;
				f = new flower_plant;
				f->t = garden;
				n3->plnt->obj = (void*)f;

				c.Head = n1;
				c.Head->next = n2;
				c.Head->next->next = n3;
				c.Head->prev = c.Head->next->next;
				c.Head->next->prev = c.Head;
				c.Head->next->next->prev = c.Head->next;
				c.Head->next->next->next = c.Head;
				c.length = 3;
				c.Current = c.Head;

				OutTrees(ofst, &c);

				ifstream ifst1("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outTrees.txt");
				ifstream ifst2("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/expOutTrees.txt");
				char c1, c2;
				while (ifst1.get(c1) && ifst2.get(c2))
				{
					Assert::AreEqual(c1, c2);
				}
			}
	};
}
