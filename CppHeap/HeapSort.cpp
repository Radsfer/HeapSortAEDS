#include "HeapSort.hpp"
#include <algorithm>

HeapSort::HeapSort(const std::vector<int>& arr) : heap(arr) {}

void HeapSort::sort(bool minHeap) {
    int n = heap.size();

    // Constrói o heap máximo ou mínimo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i, minHeap);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        std::swap(heap[0], heap[i]);
        heapify(i, 0, minHeap);
    }
}

void HeapSort::heapify(int n, int i, bool minHeap) {
    int largest = i;    // Inicializa o maior como raiz
    int left = 2 * i + 1;  // Esquerda = 2*i + 1
    int right = 2 * i + 2; // Direita = 2*i + 2

    if (minHeap) {
        if (left < n && heap[left] < heap[largest])
            largest = left;
        if (right < n && heap[right] < heap[largest])
            largest = right;
    } else {
        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;
    }

    // Se o maior/não for a raiz
    if (largest != i) {
        std::swap(heap[i], heap[largest]);

        // Recursivamente heapify a subárvore afetada
        heapify(n, largest, minHeap);
    }
}

