#include "quick_sort.hpp"
#include "../data_buffer.hpp"

int main()
{
    DataBuffer dataBuffer;

    dataBuffer.PushBack(5);
    dataBuffer.PushBack(8);
    dataBuffer.PushBack(1);
    dataBuffer.PushBack(4);
    dataBuffer.PushBack(9);
    dataBuffer.PushBack(3);
    dataBuffer.PushBack(6);
    dataBuffer.PushBack(8);
    dataBuffer.PushBack(2);
    dataBuffer.PushBack(7);
    dataBuffer.Print();

    quick_sort::Sort(&dataBuffer);
    dataBuffer.Print();

    return 0;
}