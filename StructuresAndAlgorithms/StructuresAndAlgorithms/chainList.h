#pragma once
#ifndef chainList_
#define chainList_
#include<iostream>
#include<sstream>
#include"LinearList.h"
#include"ArrayList.h"
using namespace std;
template<class T>
struct chainNode
{
	//数据成员
	T element;
	chainNode<T>* next;
	//方法
	chainNode() {};
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};
template<class T>
class chain :public linearList<T>
{
public:
	//构造函数，拷贝构造，析构函数
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();
	//抽象数据类型ADT的方法
	bool empty()const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexof(const T& theElement)const;
	void erase(int theIndex);
	void insert(int  theIndex, const T& theElement);
	void output(ostream& out) const;
	void setSize(int theSize);
	void set(int theIndex, const T& thElement);
	void removeRange(int fromIndex, int toIndex);//删除指定范围的的所有元素
	int lastIndexOf(const T& theElement)const;//返回指定元素最后出现时的索引，若不存在则返回-1
	T& operator[](int theIndex);
	bool operator==(const chain<T>& otherChain)const;
	bool operator!=(const chain<T>& otherChain)const;
	void swap(chain<T>& otherChain);
	void fromList(const ArrayList<T>& theList);
	void toList( ArrayList<T>& theList);
	void leftShift(int count);
	void reverse();
	void meld(chain<T>& sourceNode1, chain<T>& sourceNode2);
	void split(chain<T>& target1, chain<T>& target2);
	void radix_sort(int r, int range);
protected:
	void checkIndex(int theIndex)const;//如果索引无效，抛出异常
	chainNode<T>* firstNode;//指向链表第一个节点的指针
	int listSize;//线性表的元素个数
};
template<class T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "初始容量=" << initialCapacity << "必须大于0" << endl;
	}
	firstNode = NULL;
	listSize = 0;
}
template<class T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{//链表为空
		firstNode = NULL;
		return;
	}
	chainNode<T>* sourceNode = theList.firstNode;//复制链表的头节点
	firstNode = new chainNode<T>(sourceNode->element);//将被复制的头节点元素复制给头节点
	sourceNode = sourceNode->next;//下一位
	chainNode<T>* targetNode = firstNode;//链表中的最后一个节点
	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}
template<class T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
template<class T>
void chain<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw s.str();
	}

}
template<class T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->element;
}
template<class T>
int chain<T>::indexof(const T& theElement)const
{
	int index = 0;
	chainNode<T>* currentNode = firstNode;
	while ( currentNode != NULL&&currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == NULL)
	{
		return -1;
	}
	else
		return index;
}
template<class T>
void chain<T>::erase(int theIndex)
{
	chainNode<T>* currentNode;
	chainNode<T>* deleteNode;
	checkIndex(theIndex);
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		currentNode = firstNode;
		for (int i = 0; i < theIndex-1; i++)
		{
			currentNode = currentNode->next;
		}
		deleteNode = currentNode->next;
		currentNode->next = currentNode->next->next;
	}
	delete deleteNode;
	listSize--;
}
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index=" << theIndex << " size=" << listSize;
		throw "illegal index";
	}
	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
	else
	{
		chainNode<T>* currentNode = firstNode;
		for (int i = 0; i<theIndex-1; i++)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = new chainNode<T>(theElement, currentNode->next);
	}
	listSize++;
}
template<class T>
void chain<T>::output(ostream& out) const
{// Put the list into the stream out.
	for (chainNode<T>* currentNode = firstNode;
		currentNode != NULL;
		currentNode = currentNode->next)
		out << currentNode->element << "  ";
}
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
	x.output(out); return out;
}
template <class T>
void chain<T>::setSize(int theSize)
{
	chainNode<T>* currentNode = firstNode;
	if (theSize <= 0)
		throw theSize;
	if (theSize >= listSize)
	{
		cout << "所设定的列表大小大于链表初始大小，列表容量还是为原定容量" << endl;
		exit(0);
	}
	if (theSize < listSize)
	{
		listSize = theSize;
		for (int i = 0; i < listSize-1 ; i++)
		{
			currentNode = currentNode->next;
		}
		chainNode<T>* deleteNode = currentNode->next;
		while (deleteNode != NULL)
		{
			chainNode<T>* tempNode = deleteNode->next;
			delete deleteNode;
			deleteNode = tempNode;
		}
		currentNode->next = NULL;
	}
}
template <class T>
void chain<T>::set(int theIndex, const T& theElemnet)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index=" << theIndex << " size=" << listSize;
		throw "illegal index";
	}
	if (theIndex == 0)
	{
		firstNode->element = theElemnet;
	}
	else
	{
		chainNode<T>* currentNode = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
		{
			currentNode = currentNode->next;
		}
		currentNode->element = theElemnet;
	}
}
template <class T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
	checkIndex(fromIndex);
	checkIndex(toIndex);
	if (fromIndex > toIndex)
	{
		throw "toIndex must >fromIndex";
	}
	else if (fromIndex == toIndex)
	{
		erase(fromIndex);
	}
	else
	{
		chainNode<T>* currentNode = firstNode;
		if (fromIndex == 0)
		{
			chainNode<T>* tempNode;
			for (int i = fromIndex; i < toIndex+1; i++)
			{
				tempNode = currentNode->next;
				delete currentNode;
				currentNode = tempNode;
			}
			firstNode = currentNode;
			listSize = listSize - (toIndex - fromIndex + 1);
		}
		else
		{
			for (int i = 0; i < fromIndex-1 ; i++)
			{
				currentNode = currentNode->next;
			}
			chainNode<T>* tempNode = currentNode;
			currentNode = currentNode->next;
			for (int i = fromIndex ; i < toIndex+1; i++)
			{
				chainNode<T>* temp1Node = currentNode->next;
				delete currentNode;
				currentNode = temp1Node;
			}
			tempNode->next = currentNode;
			listSize = listSize - (toIndex - fromIndex + 1);
		}
	}
}
template <class T>
int chain<T>::lastIndexOf(const T& theElement)const
{
	int index;
	int i = 0;
	chainNode<T>* currentNode = firstNode;
	while (currentNode != NULL)
	{
		if (currentNode->element == theElement)
		{
			index = i;
		}
		currentNode = currentNode->next;
		i++;
	}
	if (index > 0)
	{
		return index;
	}
	else
		return -1;
}
template<class T>
T& chain<T>::operator[](int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex - 1; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->next->element;
}
template <class T>
bool chain<T>::operator==(const chain<T>&otherChain)const
{
	if (listSize == otherChain.size())
	{
		chainNode<T>* currentNode = firstNode;
		chainNode<T>* currentNode1 = otherChain.firstNode;
		while (currentNode->element != currentNode1->element&&currentNode != NULL)
		{
			currentNode = currentNode->next;
			currentNode1 = currentNode1->next;
		}
		if (currentNode == NULL)
			return true;
		else
			return false;
	}
	else
		return false;
}
template <class T>
bool chain<T>::operator!=(const chain<T>& otherChain)const
{
	if (listSize == otherChain.size())
	{
		chainNode<T>* currentNode = firstNode;
		chainNode<T>* currentNode1 = otherChain.firstNode;
		while (currentNode->element != currentNode1->element && currentNode != NULL)
		{
			currentNode = currentNode->next;
			currentNode1 = currentNode1->next;
		}
		if (currentNode == NULL)
			return false;
		else
			return true;
	}
	else
		return true;
}
template <class T>
void chain<T>::swap(chain<T>& otherChain)
{
	chainNode<T>* currentNode = firstNode;
	chainNode<T>* currentNode1 = otherChain.firstNode;
	chainNode<T>* tempNode;
	chainNode<T>* flagNode=currentNode;
	chainNode<T>* flagNode1=currentNode1;
	while (currentNode != NULL&&currentNode1!=NULL)
	{
		flagNode = currentNode;
		flagNode1 = currentNode1;
		T temp = currentNode->element;
		currentNode->element = currentNode1->element;
		currentNode1->element = temp;
		currentNode = currentNode->next;
		currentNode1 = currentNode1->next;
	}
	if (listSize>=otherChain.listSize)
	{
		currentNode1 = flagNode1;
		while (currentNode != NULL)
		{
			tempNode = currentNode->next;
			currentNode1->next = new chainNode<T>(currentNode->element, currentNode1->next);
			//cout << currentNode->element << endl;
			//cout << currentNode1->next->element << endl;
			delete currentNode;
			currentNode = tempNode;
			currentNode1 = currentNode1->next;
		}
		flagNode->next = NULL;
	}
	if (listSize < otherChain.listSize)
	{
		currentNode = flagNode;
		while (currentNode1 != NULL)
		{
			tempNode = currentNode1->next;
			currentNode->next = new chainNode<T>(currentNode1->element, currentNode->next);
			//cout << currentNode->element << endl;
			//cout << currentNode1->next->element << endl;
			delete currentNode1;
			currentNode1 = tempNode;
			currentNode = currentNode->next;
		}
		flagNode1->next = NULL;
	}
	int temp = listSize;
	listSize = otherChain.listSize;
	otherChain.listSize = temp;
}
template <class T>
void chain<T>::fromList(const ArrayList<T>& theList)
{
	firstNode = new chainNode<T>;
	chainNode<T>* currentNode = firstNode;
	chainNode<T>* flagNode = currentNode;
	for (int i = 0; i < theList.size(); i++)
	{
		flagNode = currentNode;
		currentNode->element = theList.get(i);
		currentNode->next = new chainNode<T>;
		currentNode = currentNode->next;
	}
	flagNode->next=NULL ;
	listSize = theList.size();
}
template <class T>
void chain<T>::toList(ArrayList<T>& theList)
{
	int i = 0;
	chainNode<T>* currentNode = firstNode;
	while (currentNode != NULL)
	{
		theList.insert(i, currentNode->element);
		currentNode = currentNode->next;
		i++;
	}
}
template <class T>
void chain<T>::leftShift(int count)
{
	checkIndex(count);
	chainNode<T>* currentNode = firstNode;
	chainNode<T>* tempNode = NULL;
	for (int i = 0; i < count; i++)
	{
		firstNode = firstNode->next;
	}
	for (int i = 0; i < count; i++)
	{
		tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
}
template <class T>
void chain<T>::reverse()
{
	chainNode<T>* currentNode = firstNode;
	chainNode<T>* refirstNode = NULL;
	chainNode<T>* recurrentNode = NULL;
	while (currentNode->next != NULL)
	{
		currentNode= currentNode->next;
	}//找到倒数第一个节点
	refirstNode = currentNode;
	recurrentNode = refirstNode;//将倒数第一个节点作为头节点
	while (recurrentNode != firstNode)
	{
		currentNode = firstNode;
		while (currentNode->next != recurrentNode)
		{
			currentNode = currentNode->next;
		}
		recurrentNode->next = currentNode;
		recurrentNode = recurrentNode->next;
	}
	recurrentNode->next = NULL;
	firstNode = refirstNode;
}
template <class T>
void chain<T>::meld(chain<T>& source1, chain<T>& source2)
{
	if (source1.listSize >= source2.listSize)
	{
		chainNode<T>* tempNode = NULL;
		chainNode<T>* sourceNode = source2.firstNode;
		chainNode<T>* targetNode = source1.firstNode;
		while (sourceNode != NULL)
		{
			tempNode = targetNode->next;//记录目标节点的next*
			targetNode->next = sourceNode;//
			sourceNode = sourceNode->next;//
			targetNode = targetNode->next;//插入一个节点
			targetNode->next = tempNode;
			targetNode = targetNode->next;
		}
		firstNode = source1.firstNode;
		listSize = source1.listSize + source2.listSize;
		source1.firstNode = NULL;
		source2.firstNode = NULL;
	}
	else
	{
		chainNode<T>* tempNode = NULL;
		chainNode<T>* sourceNode = source1.firstNode;
		chainNode<T>* targetNode = source2.firstNode;
		while (sourceNode != NULL)
		{
			tempNode = targetNode->next;//记录目标节点的next*
			targetNode->next = sourceNode;//
			sourceNode = sourceNode->next;//
			targetNode = targetNode->next;//插入一个节点
			targetNode->next = tempNode;
			targetNode = targetNode->next;
		}
		firstNode = source2.firstNode;
		listSize = source1.listSize + source2.listSize;
		source1.firstNode = NULL;
		source2.firstNode = NULL;
	}
}
template <class T>
void chain<T>::split(chain<T>& target1, chain<T>& target2)
{
	int i = 0;
	if (target1.firstNode != NULL)
	{
		chainNode<T>* target1nextNode = target1.firstNode->next;
		delete target1.firstNode;
		target1.firstNode = target1nextNode;
	}//清空目标1的所有节点
	target1.listSize = 0;
	target1.firstNode = NULL;
	if (target2.firstNode != NULL)
	{
		chainNode<T>* target2nextNode = target2.firstNode->next;
		delete target2.firstNode;
		target2.firstNode = target2nextNode;
	}//清空目标2的所有节点
	target2.listSize = 0;
	target2.firstNode = NULL;

	chainNode<T>* sourceNode = this->firstNode;
	target1.firstNode = new chainNode<T>(sourceNode->element);
	target1.listSize++;
	chainNode<T>* target1Node = target1.firstNode;
	
	sourceNode = sourceNode->next;
	if (sourceNode != NULL)
	{
		target2.firstNode = new chainNode<T>(sourceNode->element);
		target2.listSize++;
	}
	chainNode<T>* target2Node = target2.firstNode;
	sourceNode = sourceNode->next;
	while (sourceNode != NULL)
	{
		if (i % 2 == 0)
		{
			target1Node->next = new chainNode<T>(sourceNode->element);
			target1Node = target1Node->next;
			sourceNode = sourceNode->next;
			target1.listSize++;
		}
		
		else
		{
			target2Node->next = new chainNode<T>(sourceNode->element);
			target2Node = target2Node->next;
			sourceNode = sourceNode->next;
			target2.listSize++;
		}
		i++;
	}
	target1Node->next = NULL;
	target2Node->next = NULL;
}
// 基数排序
//radix表示的分解，digit将一个数分解为多少个数字
template<class T>
void chain<T>::radix_sort(int radix, int digit)
{
	for (int i = 0; i < digit; i++)
	{
		int r = 1;
		for (int j = i; j > 0; j--)
		{
			r = r * radix;
		}
		// 初始化顶箱和底箱
		chainNode<T>** top, ** bottom;
		bottom = new chainNode<T>*[radix];//头节点
		top = new chainNode<T>*[listSize];
		for (int b = 0; b < radix; b++)
		{
			bottom[b] = NULL;
		}

		// 分配顶层与底层箱子
		for (; firstNode != NULL; firstNode = firstNode->next)
		{
			int the_bin = ((firstNode->element) % (r*radix)) / r;
			if (bottom[the_bin] == NULL)
			{
				bottom[the_bin] = top[the_bin] = firstNode;
			}
			else
			{
				top[the_bin]->next = firstNode;
				top[the_bin] = firstNode;
			}
		}

		//把箱子分配到有序列表中
		chainNode<T>* y = NULL;
		for (int the_bin = 0; the_bin < radix; the_bin++)
		{
			if (bottom[the_bin] == NULL)
			{
				continue;
			}
			if (y == NULL)
			{
				firstNode = bottom[the_bin];
			}
			else
			{
				y->next = bottom[the_bin];
			}
			y = top[the_bin];
		}
		if (y != NULL)
		{
			y->next = NULL;
		}
		delete[] bottom;
		delete[] top;
	}
}
#endif
