#include<iostream>
#include"LinearList.h"
#include"chainList.h"
#include"ExtentLinear.h"
#include"ExtentChain.h"
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime> // Header file needed to use time
using namespace std;

int main()
{
	// test constructor*******************************************************
	//linearList<double>* x = new chain<double>;
	//chain<int> y, z,x;
	//ArrayList<int> a;
	//cout << "Initial size of x, y, and z = "
	//	//<< x->size() << ", "
	//	<< y.size() << ", "
	//	<< z.size() << endl;
	// test empty**********************************************************
	/*if (x->empty()) cout << "x is empty" << endl;
	else cout << "x is not empty" << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;*/
	// test insert***********************************************************
	/*y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;*/
	/*if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;
	y.output(cout);
	cout << endl << "Testing overloaded <<" << endl;
	cout << y << endl;*/ 
	// test indexOf***********************************************************
	/*int index = y.indexof(4);
	if (index < 0) cout << "4 not found" << endl;
	else cout << "The index of 4 is " << index << endl;
	index = y.indexof(7);
	if (index < 0) cout << "7 not found" << endl;
	else cout << "The index of 7 is " << index << endl;*/
	// test get*********************************************************
	/*cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;*/
	// test erase**************************************************************
	/*y.erase(1);
	cout << "Element 1 erased" << endl;
	cout << "The list is " << y << endl;
	y.erase(2);
	cout << "Element 2 erased" << endl;
	cout << "The list is " << y << endl;
	y.erase(0);
	cout << "Element 0 erased" << endl;
	cout << "The list is " << y << endl;

	cout << "Size of y = " << y.size() << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;*/
	//test construct**************************************
	/*chain<int> w(y);
	w.set(2, 8);
	w.set(1, 3);
	w.set(5, 9);
	y.erase(0);
	y.erase(0);
	cout << w.size() << endl;
	cout << y.size() << endl;*/
	//y.erase(0);
	//cout << "w should be old y, new y has first 2 elements removed" << endl;
	/*cout << "w is " << w << endl;
	cout << "y is " << y << endl;*/
	//test setSize******************************************************
	//y.setSize(4);
	//y.output(cout);
	//test set
	//y.set(2,5);
	//y.output(cout);
	/*y.removeRange(1,3 );
	y.output(cout);
	cout<<y.size();*/
	/*y.insert(2, 3);
	y.output(cout);
	cout<<y.lastIndexOf(3);*/
	//cout<<y.operator==(w);
	/*y.swap(w);
	cout << "after swap w is " << w << endl;
	cout << "after swap y is " << y << endl;*/
	/*a.insert(0, 2);
	a.insert(0, 3);
	a.insert(1, 2);
	a.output(cout);
	x.fromList(a);
	x.output(cout);*/
	/*y.toList(a);
	a.output(cout);*/
	/*y.leftShift(2);
	y.output(cout);*/
	//y.reverse();
	//y.output(cout);
	//test extendedChain meld*************************************************
	/*extendedChain<int>a, b,c;
	a.insert(0, 2);
	a.insert(1, 6);
	a.insert(0, 1);
	a.insert(2, 4);
	a.insert(3, 5);
	a.insert(2, 3);
	b.insert(0, 8);
	b.insert(1, 20);
	b.insert(0, 10);
	meld(a, b,c);
	c.output(cout);*/
	/*chain<int>a, b, c;
	a.insert(0, 2);
	a.insert(1, 6);
	a.insert(0, 1);
	a.insert(2, 4);
	a.insert(3, 5);
	a.insert(2, 3);
	a.insert(0, 8);
	a.insert(1, 20);
	a.insert(0, 10);
	b.insert(0, 11);
	cout << "befor split" << endl;
	a.output(cout);
	cout << endl;
	b.output(cout);
	cout << endl;
	c.insert(0, 12);
	c.insert(0, 13);
	c.output(cout);
	cout << endl;
	a.split(b, c);
	cout << "after split" << endl;
	b.output(cout);
	cout << b.size() << endl;
	cout << endl;
	c.output(cout);*/
//text for radixSort-------------------------------------------------------
	//chain<int>a;															
	//unsigned seed;  // Random generator seed
	//// Use the time function to get a "seed” value for srand
	//seed = time(0);
	//srand(seed);
	//for (int i = 0; i <50;i++)
	//{
	//	a.insert(0,rand() % 1000000 );//生成10000个0到999999的随机数
	//}
	//a.radix_sort(10,6);
	//a.output(cout);
//------------------------------------------------------------------------

}