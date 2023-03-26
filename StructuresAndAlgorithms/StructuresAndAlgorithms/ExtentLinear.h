#pragma once
#ifndef ExtentLinear_
#define extentdLinear_
#include <iostream>
#include "linearList.h"

using namespace std;

template<class T>
class extendedLinearList :public linearList<T>
{
public:
    virtual ~extendedLinearList() {}
    virtual void clear() = 0;
    // empty the list
    virtual void push_back(const T& theElement) = 0;
    // insert theElement at end of list
};
#endif