#pragma once
#ifndef changeLength1D_
#define changeLength1D_
using namespace std;


template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		cout << "new length must be >= 0" << endl;
	T* temp = new T[newLength];
	int number;
	oldLength < newLength ? number = oldLength : number = newLength; 
	for (int i = 0; i < number; i++)
	{
		temp[i] = a[i];//将要删除的元素后面的元素转移到临时堆
	}
	delete[]a;
	a = temp;
}

#endif
