#pragma once
#ifndef ArrayList_
#define ArrayList_
#include<iostream>
#include<sstream>
#include"LinearList.h"
#include"changeLength1D.h"
using namespace std;
template<class T>
class ArrayList : public linearList<T>
{
public:
	ArrayList(int initialCapacity = 10);//�вι���
	ArrayList(const ArrayList<T>&);//��������
	bool empty()const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexof(const T& theElement)const;
	void erase(int theIndex) ;
	void insert(int  theIndex, const T& theElement) ;
	void output(ostream& out) const ;
	int capacity() const { return arrayLength; }
	void trimToSize() const;//ʹ���鳤�ȵ���max��listsize,1��
	T& operator [](int index)const;
	bool operator ==(const ArrayList<T>& a)const;
	bool operator !=(const ArrayList<T>& a)const;
	~ArrayList() { delete[] element; }
protected:
	void checkIndex(int theIndex)const;
	T* element;//һά����
	int arrayLength;//��������
	int listSize;//Ԫ�ظ���
};
template<class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		cout << "Initial capacity = " << initialCapacity << " Must be > 0/n";
		cout << "the value of initial capacity equal 5" << endl;
		initialCapacity = 5;
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	for (int i = 0; i < listSize; i++)
	{
		element[i] = theList[i];
	}
}
//template<class T>
//ArrayList<T>::ArrayList(const ArrayList<T>& theList)
//{
//
//}
template<class T>
void ArrayList<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		cout << "Ӧ����һ��������С����������������" << endl;
	}
}
template<class T>
int ArrayList<T>::indexof(const T& theElement) const
{
	for (int i = 0; i < listSize; i++)
	{
		if (this->element[i] == theElement)
		{
			return i;
		}
	}
	return -1;
}
template<class T>
T& ArrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);//�쳣����δд
	return this->element[theIndex];
}
template<class T>
void ArrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);//�쳣����δд
	T* temp = new T[listSize - theIndex-1];//����һ����ʱT*��
	for (int i = 0; i < listSize-theIndex-1; i++)
	{
		temp[i] = element[i+theIndex+1];//��Ҫɾ����Ԫ�غ����Ԫ��ת�Ƶ���ʱ��
	}
	for (int i = 0; i < listSize - theIndex - 1; i++)
	{
		element[i + theIndex ] = temp[i];
	}
	listSize--;
	delete[]temp;
	for (int i = 0; i < listSize; i++)
	{
		cout << element[i];
	}
	cout << endl;
}
template<class T>
void ArrayList<T>::insert(int  theIndex, const T& theElement) 
{
	if (theIndex < 0 || theIndex > listSize)
	{// invalid index
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		cout << "�������ڷ�Χ��" << endl;
	}//�쳣����δд,���쳣Ϊ���ж���������Ƿ�������������
	if (listSize == arrayLength)
	{
		cout << "��ǰ�������޶���ռ�" << endl;
		changeLength1D(element, arrayLength, arrayLength * 2);
		arrayLength = 2*arrayLength;
	}
	T* temp = new T[listSize - theIndex ];

	//cout << "temp�д洢��Ԫ��";
	for (int i = 0 ; i < listSize - theIndex ; i++)
	{
		temp[i] = element[i + theIndex ];//��Ҫ�����Ԫ�غ����Ԫ��ת�Ƶ���ʱ��
		/*cout<<element[i];*/
	}
	/*cout << endl;*/
	element[theIndex] = theElement;
	/*cout << "����֮�����Ԫ��";*/
	for (int i = 0; i < listSize - theIndex ; i++)
	{
		element[i + theIndex + 1] = temp[i];//��
		/*cout << element[i];*/
	}
	/*cout << endl;*/
	listSize++;
	/*cout << "����֮��a����ĸ���" << listSize << endl;
	cout << "����֮��Ԫ��" << endl;*/
	//for (int i = 0; i < listSize; i++)
	//{
	//	cout << element[i] ;
	//}
	//cout << endl;
}
template<class T>
void ArrayList<T>::output(ostream& out) const
{
	copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}
template <class T>
ostream& operator<<(ostream& out, const ArrayList<T>& x)
{
	x.output(out); return out;
}
template <class T>
void ArrayList<T>::trimToSize()const
{
	listSize > 1 ? listSize = listSize : listSize = 1;
}
template <class T>
T& ArrayList<T>::operator[](int index)const
{
	checkIndex(index);
	return element[index];
}
template<class T>
bool ArrayList<T>::operator==(const ArrayList<T>& a)const
{
	if (listSize == a.listSize)
	{
		for (int i = 0; i < listSize; i++)
		{
			if (element[i] != a.element[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;
}
template<class T>
bool ArrayList<T>::operator!=(const ArrayList<T>& a)const
{
	if (listSize == a.listSize)
	{
		for (int i = 0; i < listSize; i++)
		{
			if (element[i] != a.element[i])
			{
				return true;
			}
		}
		return false;
	}
	else
		return true;
}
 #endif
