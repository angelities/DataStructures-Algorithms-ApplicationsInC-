#pragma once
#ifndef changeLength2D_
#define changeLength2D_
using namespace std;

template<class T>
void changeLength2D(T**& a, int oldRow, int newRow,int oldColumn, int newColumn)
{
	if (newRow < 0 || newColumn <0 )
		throw ("new dimensions are too small");
	T** temp = new T * [newRow];              // array for rows
	// create row arrays for temp
	for (int i = 0; i < newRow; i++)
		temp[i] = new T[newColumn];
	int copyRow;
	int copyColumn;
	oldRow < newRow ? copyRow = oldRow : copyRow = newRow;
	oldColumn < newColumn ? copyColumn = oldColumn : copyCloumn = newColumn;
	for (int i = 0; i < copyRow; i++)
	{
		for (int i = 0; i < copyColumn; i++)
		{
			temp[i] = a[i];//��Ҫɾ����Ԫ�غ����Ԫ��ת�Ƶ���ʱ��
		}
	}
	for (int i = 0; i < oldRow; i++)
		delete[] a[i];
	delete[] a;
	a = temp;
}
#endif