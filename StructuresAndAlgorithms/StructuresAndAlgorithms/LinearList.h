#pragma once
#ifndef LinearList_
#define LinearList_
#include <iostream>
using namespace std;

template< class T>
class linearList
{
public:
	virtual bool empty() const = 0;//线性表为空时为真，返回true
	virtual int size() const = 0;//返回线性表的元素个数
	virtual T& get(int theIndex) const = 0;//返回线性表索引为theIndex的元素
	virtual int indexof(const T& theElement)const = 0;//返回第一次遇上theElement元素时的索引值
	virtual void erase(int theIndex) = 0;//删除索引为theIndex
	virtual void insert(int  theIndex, const T& theElement) = 0;//将theElement元素插入到索引值为theIndex上
	virtual void output(ostream& out) const = 0;//将线性表输出
	virtual ~linearList() {};
};
#endif
