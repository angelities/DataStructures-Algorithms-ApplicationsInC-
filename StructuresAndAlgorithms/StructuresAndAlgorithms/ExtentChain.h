#pragma once
#ifndef ExtentChain_
#define ExtentChain_

#include <iostream>
#include <sstream>
#include <string>
#include "ExtentLinear.h"
#include"chainList.h"

using namespace std;

template<class T>
class extendedChain;

template<class T>
void meld(extendedChain<T>& a, extendedChain<T>& b, extendedChain<T>& c)
{
    if (c.firstNode != NULL)
    {
        while (c.firstNode != NULL)
        {
            chainNode<T>* nextNode = c.firstNode->next;
            delete  c.firstNode;
            c.firstNode = nextNode;
        }
        c.firstNode = NULL;
        c.lastNode = NULL;
        c.listSize = 0;
    }
    if (a.listSize >= b.listSize)
    {
        c.listSize = a.listSize;
     
        chainNode<T>* sourceNode = a.firstNode;//复制链表的头节点
        c.firstNode = new chainNode<T>(sourceNode->element);//将被复制的头节点元素复制给头节点
        sourceNode = sourceNode->next;//下一位
        chainNode<T>* targetNode = c.firstNode;//链表中的最后一个节点
        while (sourceNode != NULL)
        {
            targetNode->next = new chainNode<T>(sourceNode->element);
            targetNode = targetNode->next;
            sourceNode = sourceNode->next;
        }
        targetNode->next = NULL;
        //----------------------------------------------
        chainNode<T>* tempNode = NULL;
        chainNode<T>* sourceNodeb = b.firstNode;
        chainNode<T>* targetNode1 = c.firstNode;
        while (sourceNodeb != NULL)
        {
            tempNode = targetNode1->next;//记录目标节点的next*
            targetNode1->next = new chainNode<T>(sourceNodeb->element);//
            sourceNodeb = sourceNodeb->next;//
            targetNode1 = targetNode1->next;//插入一个节点
            targetNode1->next = tempNode;
            targetNode1 = targetNode1->next;
        }
        c.listSize = c.listSize + b.listSize;
    }
    else
    {
        c.listSize = b.listSize;
    
        chainNode<T>* sourceNode = b.firstNode;//复制链表的头节点
        c.firstNode = new chainNode<T>(sourceNode->element);//将被复制的头节点元素复制给头节点
        sourceNode = sourceNode->next;//下一位
        chainNode<T>* targetNode = c.firstNode;//链表中的最后一个节点
        while (sourceNode != NULL)
        {
            targetNode->next = new chainNode<T>(sourceNode->element);
            targetNode = targetNode->next;
            sourceNode = sourceNode->next;
        }
        targetNode->next = NULL;
        //----------------------------------------------
        chainNode<T>* tempNode = NULL;
        chainNode<T>* sourceNodea = a.firstNode;
        chainNode<T>* targetNode1 = c.firstNode;
        while (sourceNodea != NULL)
        {
            tempNode = targetNode1->next;//记录目标节点的next*
            targetNode1->next = new chainNode<T>(sourceNodea->element);//
            sourceNodea = sourceNodea->next;//
            targetNode1 = targetNode1->next;//插入一个节点
            targetNode1->next = tempNode;
            targetNode1 = targetNode1->next;
        }
        c.listSize = c.listSize + a.listSize;
    }
}

template<class T>
class extendedChain :public chain<T>, public extendedLinearList<T>
{
    friend void meld<T>(extendedChain<T>& a, extendedChain<T>& b, extendedChain<T>& c);
public:
    // constructor and copy constructor
    extendedChain(int initialCapacity = 10) :
        chain<T>(initialCapacity) {}
    extendedChain(const extendedChain<T>& c) :
        chain<T>(c) {}

    // ADT methods
    bool empty() const { return this->listSize == 0; }
    int size() const { return this->listSize; }
    T& get(int theIndex) const
    {
        return chain<T>::get(theIndex);
    }
    int indexof(const T& theElement) const
    {
        return chain<T>::indexof(theElement);
    }
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void clear()
    {// Delete all nodes in chain.
        while (this->firstNode != NULL)
        {// delete firstNode
            chainNode<T>* nextNode = this->firstNode->next;
            delete this->firstNode;
            this->firstNode = nextNode;
        }
        this->listSize = 0;
    }
    void push_back(const T& theElement);
    void output(ostream& out) const
    {
        chain<T>::output(out);
    }

    // additional method
    void zero()
    {
        this->firstNode = NULL; this->listSize = 0;
    }
    void circualrShift(int i);

protected:
    chainNode<T>* lastNode;  // pointer to last node in chain
};


template<class T>
void extendedChain<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
    this->checkIndex(theIndex);

    // valid index, locate node with element to delete
    chainNode<T>* deleteNode;
    if (theIndex == 0)
    {// remove first node from chain
        deleteNode = this->firstNode;
        this->firstNode = this->firstNode->next;
    }
    else
    {  // use p to get to predecessor of desired node
        chainNode<T>* p = this->firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next; // remove deleteNode from chain
        if (deleteNode == lastNode)
            lastNode = p;
    }
    this->listSize--;
    delete deleteNode;
}

template<class T>
void extendedChain<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
    if (theIndex < 0 || theIndex > this->listSize)
    {// invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << this->listSize;
        /*throw illegalIndex(s.str());*/
    }

    if (theIndex == 0)
    {// insert at front
        this->firstNode = new chainNode<T>(theElement, this->firstNode);
        if (this->listSize == 0)
            lastNode = this->firstNode;
    }
    else
    {  // find predecessor of new element
        chainNode<T>* p = this->firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        // insert after p
        p->next = new chainNode<T>(theElement, p->next);
        if (this->listSize == theIndex)
            lastNode = p->next;
    }
    this->listSize++;
}

template<class T>
void extendedChain<T>::push_back(const T& theElement)
{// Insert theElement at the end of the chain.
    chainNode<T>* newNode = new chainNode<T>(theElement, NULL);
    if (this->firstNode == NULL)
        // chain is empty
        this->firstNode = lastNode = newNode;
    else
    {  // attach next to lastNode
        lastNode->next = newNode;
        lastNode = newNode;
    }
    this->listSize++;
}

template<class T>
void extendedChain<T>::circualrShift(int times)
{
    //可以再加一个当左移次数大于链表节点数目时times%listsize的判断功能
    if (empty())
        return;
    chainNode<T>* currentNode = this->firstNode;
    chainNode<T>* recurrentNode = lastNode;
    chainNode<T>* flagNode = NULL;
    for (int i = 0; i < times; i++)
    {
        recurrentNode->next = currentNode;
        currentNode = currentNode->next;
        flagNode = recurrentNode;
        recurrentNode = recurrentNode->next;
    }
    this->firstNode = currentNode;
    lastNode = recurrentNode;
    lastNode->next = NULL;

}
#endif
