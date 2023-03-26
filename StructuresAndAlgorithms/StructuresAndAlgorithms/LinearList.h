#pragma once
#ifndef LinearList_
#define LinearList_
#include <iostream>
using namespace std;

template< class T>
class linearList
{
public:
	virtual bool empty() const = 0;//���Ա�Ϊ��ʱΪ�棬����true
	virtual int size() const = 0;//�������Ա��Ԫ�ظ���
	virtual T& get(int theIndex) const = 0;//�������Ա�����ΪtheIndex��Ԫ��
	virtual int indexof(const T& theElement)const = 0;//���ص�һ������theElementԪ��ʱ������ֵ
	virtual void erase(int theIndex) = 0;//ɾ������ΪtheIndex
	virtual void insert(int  theIndex, const T& theElement) = 0;//��theElementԪ�ز��뵽����ֵΪtheIndex��
	virtual void output(ostream& out) const = 0;//�����Ա����
	virtual ~linearList() {};
};
#endif
