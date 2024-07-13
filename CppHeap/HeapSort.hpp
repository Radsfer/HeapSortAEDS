#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>

class HeapSort {
public:
    explicit HeapSort(const std::vector<int>& arr);

    void sort(bool minHeap = false); // true para ordenação em heap mínimo, false para máximo

private:
    std::vector<int> heap;

    void heapify(int n, int i, bool minHeap);
};

#endif // HEAPSORT_HPP

