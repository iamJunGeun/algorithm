#ifndef __DATA_BUFFER_HPP__
#define __DATA_BUFFER_HPP__

class DataBuffer {
public:
    void Swap(const int i, const int j);
    void PushBack(const int num);
    int operator[](const int index);
    void Replace(const int index, const int num);
    void Remove(const int index);
    void Print();
    int Length();

public:
    DataBuffer(const int capacity);
    DataBuffer();
    ~DataBuffer();

private:
    inline bool isFull();
    inline void expandCapacity();

private:
    int* mDatas;
    int mCapacity;
    int mLength;
};

#endif /* __DATA_BUFFER_HPP__ */