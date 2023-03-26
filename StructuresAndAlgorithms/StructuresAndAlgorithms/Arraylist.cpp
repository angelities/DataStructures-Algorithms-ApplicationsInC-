#include<iostream>
#include"LinearList.h"
#include"ArrayList.h"
#include"changeLength1D.h"
#include<string>
using namespace std;

int main()
{
	char c[6] = { 'a','b','c','d','\0' };
	ArrayList<char> a(10);
	for (int i = 0; i < 4; i++)
	{
		a.insert(i, c[i]);
	}
	a.insert(0, 'f');
	a.insert(3, 'g');
	cout <<"size of arraylist:" << a.size() << endl;
	//a.insert(7, 'h');
	cout <<"当前f的索引" << a.indexof('f') << endl;
	cout << "当前g的索引" << a.indexof('g') << endl;
	cout << "当前h的索引" << a.indexof('h') << endl;
	cout << "当前数组a的长度" << a.size() << endl;
	a.erase(0);
	cout << "当前数组a的长度" << a.size() << endl;
	cout << "当前0索引中的元素" << a.get(0) << endl;
	a.erase(4);
	cout << "当前数组a的长度" << a.size() << endl;
	cout << "当前4索引中的元素" << a.get(4) << endl;
}
