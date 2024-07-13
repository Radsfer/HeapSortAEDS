#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>

class HeapSort {
private:
    std::vector<int> heap;

    void heapify(int n, int i);

public:
    HeapSort(const std::vector<int> &arr);

    void sort();
};

#endif // HEAPSORT_HPP



