#include "../data_buffer.hpp"
#include "bubble_sort.hpp"

int main()
{
    DataBuffer databuffer;

    databuffer.PushBack(5);
    databuffer.PushBack(3);
    databuffer.PushBack(7);
    databuffer.PushBack(9);
    databuffer.PushBack(1);
    databuffer.Print();

    bubble_sort::SortAscending(&databuffer);
    databuffer.Print();

    bubble_sort::SortDescending(&databuffer);
    databuffer.Print();

    return 0;
}