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
	cout <<"��ǰf������" << a.indexof('f') << endl;
	cout << "��ǰg������" << a.indexof('g') << endl;
	cout << "��ǰh������" << a.indexof('h') << endl;
	cout << "��ǰ����a�ĳ���" << a.size() << endl;
	a.erase(0);
	cout << "��ǰ����a�ĳ���" << a.size() << endl;
	cout << "��ǰ0�����е�Ԫ��" << a.get(0) << endl;
	a.erase(4);
	cout << "��ǰ����a�ĳ���" << a.size() << endl;
	cout << "��ǰ4�����е�Ԫ��" << a.get(4) << endl;
}
