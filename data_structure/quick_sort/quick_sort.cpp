#include "quick_sort.hpp"

static void doSortRecursive(DataBuffer& dataBuffer, const int startIndex, const int endIndex)
{
    if (startIndex >= endIndex) {
        return;
    }

    const int pivot = startIndex;
    int left = pivot + 1;
    int right = endIndex;
    int temp;

    while (true) {
        while (left <= right && dataBuffer[left] <= dataBuffer[pivot]) {
            ++left;
        }

        while (right >= left && dataBuffer[right] >= dataBuffer[pivot]) {
            --right;
        }

        if (left > right) {
            break;
        }

        temp = dataBuffer[right];
        dataBuffer.Replace(right, dataBuffer[left]);
        dataBuffer.Replace(left, temp);
    }

    temp = dataBuffer[right];
    dataBuffer.Replace(right, dataBuffer[pivot]);
    dataBuffer.Replace(pivot, temp);

    doSortRecursive(dataBuffer, startIndex, right - 1);
    doSortRecursive(dataBuffer, right + 1, endIndex);
}

void quick_sort::Sort(DataBuffer* const dataBuffer)
{
    doSortRecursive(*dataBuffer, 0, dataBuffer->Length() - 1);
}