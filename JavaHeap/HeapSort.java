public class HeapSort {
    private int[] heap;

    public HeapSort(int[] arr) {
        this.heap = arr.clone(); // Clonando o array para preservar o original
    }

    public void sort() {
        int n = heap.length;

        // Constrói a heap máxima
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        // Extrai elementos da heap um por um
        for (int i = n - 1; i > 0; i--) {
            swap(0, i);
            heapify(i, 0);
        }
    }

    private void heapify(int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Se o filho da esquerda é maior que a raiz
        if (left < n && heap[left] > heap[largest])
            largest = left;

        // Se o filho da direita é maior que o maior até agora
        if (right < n && heap[right] > heap[largest])
            largest = right;

        // Se o maior não é a raiz
        if (largest != i) {
            swap(i, largest);
            heapify(n, largest);
        }
    }

    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}

