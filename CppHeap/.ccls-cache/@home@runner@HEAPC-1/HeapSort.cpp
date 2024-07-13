#include "HeapSort.hpp"
#include <algorithm>

HeapSort::HeapSort(const std::vector<int> &arr) {
    heap = arr;
}

void HeapSort::sort() {
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(heap[0], heap[i]);
        heapify(i, 0);
    }
}

void HeapSort::heapify(int n, int i) {
    int raiz = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && heap[esq] > heap[raiz])
        raiz = esq;

    if (dir < n && heap[dir] > heap[raiz])
        raiz = dir;

    if (raiz != i) {
        std::swap(heap[i], heap[raiz]);
        heapify(n, raiz);
    }
}
