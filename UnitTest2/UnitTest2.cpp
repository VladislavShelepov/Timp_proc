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
				Plant pt;
				pt.name = "bbbbab";
				int res = countLetters(pt);
				int exp = 5;
				Assert::AreEqual(exp, res);
			}
			TEST_METHOD(TestCompare)
			{
				Plant pt1, pt2;
				pt1.name = "bbbb";
				pt2.name = "bb";
				Node* n1, * n2;
				n1 = new Node;
				n2 = new Node;
				n1->plant = &pt1;
				n2->plant = &pt2;
				bool res = compare(n1, n2);
				bool exp = false;
				Assert::AreEqual(exp, res);
			}
			TEST_METHOD(TestIn)
			{
				ifstream ifst("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/inTest.txt");

				TreePlant* f = new TreePlant;
				BushPlant* d = new BushPlant;
				FlowerPlant* a = new FlowerPlant;

				inTree(ifst, *f);
				inBush(ifst, *d);
				inFlower(ifst, *a);

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
				inCont(ifst, &c);

				Container c1;
				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plant = new Plant;
				n1->plant->name = "derevo";
				n1->plant->origin = desert;
				n1->plant->key = tree;
				TreePlant* t;
				t = new TreePlant;
				t->age = 10;
				n1->plant->obj = (void*)t;

				n2 = new Node;
				n2->plant = new Plant;
				n2->plant->name = "bush";
				n2->plant->origin = tundra;
				n2->plant->key = bush;
				BushPlant* b;
				b = new BushPlant;
				b->blossom = July;
				n2->plant->obj = (void*)b;

				n3 = new Node;
				n3->plant = new Plant;
				n3->plant->name = "cvetocheck";
				n3->plant->origin = steppe;
				n3->plant->key = flower;
				FlowerPlant* f;
				f = new FlowerPlant;
				f->t = garden;
				n3->plant->obj = (void*)f;

				c1.head = n1;
				c1.head->next = n2;
				c1.head->next->next = n3;
				c1.head->prev = c1.head->next->next;
				c1.head->next->prev = c1.head;
				c1.head->next->next->prev = c1.head->next;
				c1.length = 3;

				Assert::AreEqual(int(c1.length), int(c.length));

				c.current = c.head;
				c1.current = c1.head;
				while (c.current->next != c.head)
				{

					Assert::AreEqual(string(c1.current->plant->name), string(c.current->plant->name));
					Assert::AreEqual(int(c1.current->plant->origin), int(c.current->plant->origin));

					if (c1.current->plant->key == tree)
					{
						Assert::AreEqual(((TreePlant*)c1.current->plant->obj)->age, ((TreePlant*)c.current->plant->obj)->age);
					}
					if (c1.current->plant->key == bush)
					{
						Assert::AreEqual(int(((BushPlant*)c1.current->plant->obj)->blossom), int(((BushPlant*)c.current->plant->obj)->blossom));
					}
					if (c1.current->plant->key == flower)
					{
						Assert::AreEqual(int(((FlowerPlant*)c1.current->plant->obj)->t), int(((FlowerPlant*)c.current->plant->obj)->t));
					}
					c.current = c.current->next;
					c1.current = c1.current->next;
				}
			}
			TEST_METHOD(TestOut)
			{
				ofstream ofst("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outTest.txt");
				bool exp = true;
				bool res = false;

				TreePlant* t = new TreePlant;
				t->age = 10;

				BushPlant* b = new BushPlant;
				b->blossom = July;

				FlowerPlant* f = new FlowerPlant;
				f->t = garden;

				outTree(ofst, *t);
				outBush(ofst, *b);
				outFlower(ofst, *f);

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
				n1->plant = new Plant;
				n1->plant->name = "derevo";
				n1->plant->origin = desert;
				n1->plant->key = tree;
				TreePlant* t;
				t = new TreePlant;
				t->age = 10;
				n1->plant->obj = (void*)t;

				n2 = new Node;
				n2->plant = new Plant;
				n2->plant->name = "bush";
				n2->plant->origin = tundra;
				n2->plant->key = bush;
				BushPlant* b;
				b = new BushPlant;
				b->blossom = July;
				n2->plant->obj = (void*)b;

				n3 = new Node;
				n3->plant = new Plant;
				n3->plant->name = "cvetocheck";
				n3->plant->origin = steppe;
				n3->plant->key = flower;
				FlowerPlant* f;
				f = new FlowerPlant;
				f->t = garden;
				n3->plant->obj = (void*)f;

				c.head = n1;
				c.head->next = n2;
				c.head->next->next = n3;
				c.head->prev = c.head->next->next;
				c.head->next->prev = c.head;
				c.head->next->next->prev = c.head->next;
				c.head->next->next->next = c.head;
				c.length = 3;
				c.current = c.head;

				outCont(ofst, &c);

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
				n1->plant = new Plant;
				n1->plant->name = "derevo";
				n1->plant->origin = desert;
				n1->plant->key = tree;
				TreePlant* t;
				t = new TreePlant;
				t->age = 10;
				n1->plant->obj = (void*)t;

				n2 = new Node;
				n2->plant = new Plant;
				n2->plant->name = "bush";
				n2->plant->origin = tundra;
				n2->plant->key = bush;
				BushPlant* b;
				b = new BushPlant;
				b->blossom = July;
				n2->plant->obj = (void*)b;

				n3 = new Node;
				n3->plant = new Plant;
				n3->plant->name = "cvetocheck";
				n3->plant->origin = steppe;
				n3->plant->key = flower;
				FlowerPlant* f;
				f = new FlowerPlant;
				f->t = garden;
				n3->plant->obj = (void*)f;

				c.head = n1;
				c.head->next = n2;
				c.head->next->next = n3;
				c.head->prev = c.head->next->next;
				c.head->next->prev = c.head;
				c.head->next->next->prev = c.head->next;
				c.head->next->next->next = c.head;
				c.length = 3;
				c.current = c.head;


				clear(&c);
				Assert::AreEqual(true, c.head == NULL);
				Assert::AreEqual(true, c.current == NULL);
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
				n1->plant = new Plant;
				n1->plant->name = "derevo";
				n1->plant->origin = desert;
				n1->plant->key = tree;
				TreePlant* t;
				t = new TreePlant;
				t->age = 10;
				n1->plant->obj = (void*)t;

				n2 = new Node;
				n2->plant = new Plant;
				n2->plant->name = "bush";
				n2->plant->origin = tundra;
				n2->plant->key = bush;
				BushPlant* b;
				b = new BushPlant;
				b->blossom = July;
				n2->plant->obj = (void*)b;

				n3 = new Node;
				n3->plant = new Plant;
				n3->plant->name = "cvetocheck";
				n3->plant->origin = steppe;
				n3->plant->key = flower;
				FlowerPlant* f;
				f = new FlowerPlant;
				f->t = garden;
				n3->plant->obj = (void*)f;

				c1.head = n1;
				c1.head->next = n2;
				c1.head->next->next = n3;
				c1.head->prev = c1.head->next->next;
				c1.head->next->prev = c1.head;
				c1.head->next->next->prev = c1.head->next;
				c1.head->next->next->next = c1.head;
				c1.length = 3;
				//c.Current = c.Head;

				inCont(ifst, &c);
				sort(c1);

				Assert::AreEqual(int(c1.length), int(c.length));

				c.current = c.head;
				c1.current = c1.head;
				while (c.current->next != c.head)
				{

					Assert::AreEqual(string(c1.current->plant->name), string(c.current->plant->name));
					Assert::AreEqual(int(c1.current->plant->origin), int(c.current->plant->origin));

					if (c1.current->plant->key == tree)
					{
						Assert::AreEqual(((TreePlant*)c1.current->plant->obj)->age, ((TreePlant*)c.current->plant->obj)->age);
					}
					if (c1.current->plant->key == bush)
					{
						Assert::AreEqual(int(((BushPlant*)c1.current->plant->obj)->blossom), int(((BushPlant*)c.current->plant->obj)->blossom));
					}
					if (c1.current->plant->key == flower)
					{
						Assert::AreEqual(int(((FlowerPlant*)c1.current->plant->obj)->t), int(((FlowerPlant*)c.current->plant->obj)->t));
					}
					c.current = c.current->next;
					c1.current = c1.current->next;
				}
			}
			TEST_METHOD(TestOutTrees)
			{
				ofstream ofst;
				ofst.open("C:/Users/Shele/Documents/GitHub/Timp_proc/UnitTest2/outTrees.txt");
				Container c;

				bool res = true;
				bool exp = true;

				Node* n1, * n2, * n3;

				n1 = new Node;
				n1->plant = new Plant;
				n1->plant->name = "derevo";
				n1->plant->origin = desert;
				n1->plant->key = tree;
				TreePlant* t;
				t = new TreePlant;
				t->age = 10;
				n1->plant->obj = (void*)t;

				n2 = new Node;
				n2->plant = new Plant;
				n2->plant->name = "bush";
				n2->plant->origin = tundra;
				n2->plant->key = bush;
				BushPlant* b;
				b = new BushPlant;
				b->blossom = July;
				n2->plant->obj = (void*)b;

				n3 = new Node;
				n3->plant = new Plant;
				n3->plant->name = "cvetocheck";
				n3->plant->origin = steppe;
				n3->plant->key = flower;
				FlowerPlant* f;
				f = new FlowerPlant;
				f->t = garden;
				n3->plant->obj = (void*)f;

				c.head = n1;
				c.head->next = n2;
				c.head->next->next = n3;
				c.head->prev = c.head->next->next;
				c.head->next->prev = c.head;
				c.head->next->next->prev = c.head->next;
				c.head->next->next->next = c.head;
				c.length = 3;
				c.current = c.head;

				outTrees(ofst, &c);

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
