#include <assert.h>
#include "selection_sort.hpp"

static int get_index_of_minimum(DataBuffer& dataBuffer, const int startIndex, const int len)
{
    int ret = startIndex;

    for (register int i = startIndex + 1; i < len; i++) {
        if (dataBuffer[i] < dataBuffer[ret]) {
            ret = i;
        }
    }

    return ret;
}

void selection_sort::SortAscending(DataBuffer* databuffer)
{
    int len = databuffer->Length();
    int end = len - 1;
    int indexMinimum;

    for (register int i = 0; i < end; i++) {
        indexMinimum = get_index_of_minimum(*databuffer, i, len);
        if (indexMinimum != i) {
            databuffer->Swap(i, indexMinimum);
        }
    }
}

static int get_index_of_maximum(DataBuffer& dataBuffer, const int startIndex, const int len)
{
    int ret = startIndex;

    for (register int i = startIndex + 1; i < len; i++) {
        if (dataBuffer[i] > dataBuffer[ret]) {
            ret = i;
        }
    }

    return ret;
}

void selection_sort::SortDescending(DataBuffer* databuffer)
{
    int len = databuffer->Length();
    int end = len - 1;
    int indexMaximum;

    for (register int i = 0; i < end; i++) {
        indexMaximum = get_index_of_maximum(*databuffer, i, len);
        if (indexMaximum != i) {
            databuffer->Swap(i, indexMaximum);
        }
    }
}