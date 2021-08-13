#include <cassert>
#include "bubble_sort.hpp"

inline static void doSortAscending(DataBuffer& dataBuffer, const int length)
{
    int temp;
    for (register int i = 1; i < length; ++i) {
        if (dataBuffer[i - 1] > dataBuffer[i]) {
            temp = dataBuffer[i];
            dataBuffer.Replace(i, dataBuffer[i - 1]);
            dataBuffer.Replace(i - 1, temp);
        }
    }
}

void bubble_sort::SortAscending(DataBuffer* const dataBuffer)
{
    assert(dataBuffer != nullptr);
    register int length = dataBuffer->Length();

    while (length > 1) {
        doSortAscending(*dataBuffer, length);
        --length;
    }
}

inline static void doSortDescending(DataBuffer& dataBuffer, const int length)
{
    int temp;
    for (register int i = 1; i < length; ++i) {
        if (dataBuffer[i - 1] < dataBuffer[i]) {
            temp = dataBuffer[i];
            dataBuffer.Replace(i, dataBuffer[i - 1]);
            dataBuffer.Replace(i - 1, temp);
        }
    }
}

void bubble_sort::SortDescending(DataBuffer* const dataBuffer)
{
    assert(dataBuffer != nullptr);
    register int length = dataBuffer->Length();

    while (length > 1) {
        doSortDescending(*dataBuffer, length);
        --length;
    }
}