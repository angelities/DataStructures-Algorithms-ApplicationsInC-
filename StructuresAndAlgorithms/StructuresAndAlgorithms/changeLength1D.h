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
		temp[i] = a[i];//��Ҫɾ����Ԫ�غ����Ԫ��ת�Ƶ���ʱ��
	}
	delete[]a;
	a = temp;
}

#endif
