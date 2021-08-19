#include <iostream>
#include <cstring>
#include <cassert>
#include "data_buffer.hpp"

using namespace std;

void DataBuffer::Swap(const int i, const int j)
{
    assert(0 <= i && i < mLength);
    assert(0 <= j && j < mLength);
    
    if (i != j) {
        int temp;

        temp = mDatas[i];
        mDatas[i] = mDatas[j];
        mDatas[j] = temp;
    }
}

bool DataBuffer::isFull()
{
    return (mLength == mCapacity);
}

void DataBuffer::expandCapacity()
{
    int newCapacity = mCapacity * 2;
    int* newDatas = new int[newCapacity];

    memcpy(newDatas, mDatas, sizeof(int) * mLength);
    delete[] mDatas;
    mDatas = newDatas;
    mCapacity = newCapacity;
}

void DataBuffer::PushBack(const int num)
{
    if (isFull()) {
        expandCapacity();
    }

    mDatas[mLength++] = num;
}

int DataBuffer::operator[](const int index)
{
    assert(0 <= index && index < mLength);
    return mDatas[index];
}

void DataBuffer::Replace(const int index, const int num)
{
    assert(0 <= index && index < mLength);
    mDatas[index] = num;
}

void DataBuffer::Remove(const int index)
{
    assert(0 <= index && index < mLength);
    int nextDatasLength = mLength - index - 1;
    memcpy(&(mDatas[index]), &(mDatas[index + 1]), sizeof(int) * nextDatasLength);
    mLength--;
}

void DataBuffer::Print()
{
    for (register int i = 0; i < mLength; ++i) {
        cout << mDatas[i] << " ";
    }
    cout << endl;
}

int DataBuffer::Length()
{
    return mLength;
}

DataBuffer::DataBuffer(const int capacity)
: mDatas(new int[capacity])
, mCapacity(capacity)
, mLength(0) {}

DataBuffer::DataBuffer()
: mDatas(new int[2])
, mCapacity(2)
, mLength(0) {}

DataBuffer::~DataBuffer()
{
    if (mDatas) {
        delete[] mDatas;
    }
}
