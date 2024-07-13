import time
import random

def heapify(arr, n, i, min_heap=False):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if min_heap:
        if left < n and arr[left] < arr[largest]:
            largest = left
        if right < n and arr[right] < arr[largest]:
            largest = right
    else:
        if left < n and arr[left] > arr[largest]:
            largest = left
        if right < n and arr[right] > arr[largest]:
            largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest, min_heap)

def heap_sort(arr, min_heap=False):
    n = len(arr)

    # Constrói o heap máximo
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i, min_heap)

    # Extrai elementos do heap um por um
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0, min_heap)

def read_numbers_from_file(filename, n):
    with open(filename, 'r') as file:
        numbers = []
        for line in file:
            numbers.extend(map(int, line.split()))
            if len(numbers) >= n:
                break
    return numbers[:n]

def save_results(filename, size, time, type):
    with open(filename, 'a') as file:
        file.write(f"Tamanho do vetor: {size}, Tempo médio gasto ({type}): {time:.6f} segundos\n")

def main():
    sizes = [10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000]
    input_file = "input.txt"
    output_file = "tempos_medios.txt"

    for size in sizes:
        numbers = read_numbers_from_file(input_file, size)

        # Teste com array aleatório do arquivo
        average_time = 0.0
        iterations = 10

        for _ in range(iterations):
            arr = numbers[:]
            start_time = time.time()
            heap_sort(arr)
            end_time = time.time()
            average_time += end_time - start_time

        average_time /= iterations
        print(f"Tamanho do vetor: {size}")
        print(f"Tempo médio gasto (aleatório): {average_time:.6f} segundos")
        save_results(output_file, size, average_time, "aleatório")

        # Teste com array em ordem crescente
        arr = sorted(numbers)
        average_time = 0.0

        for _ in range(iterations):
            arr_copy = arr[:]
            start_time = time.time()
            heap_sort(arr_copy)
            end_time = time.time()
            average_time += end_time - start_time

        average_time /= iterations
        print(f"Tempo médio gasto (crescente): {average_time:.6f} segundos")
        save_results(output_file, size, average_time, "crescente")

        # Teste com array em ordem decrescente
        arr = sorted(numbers, reverse=True)
        average_time = 0.0

        for _ in range(iterations):
            arr_copy = arr[:]
            start_time = time.time()
            heap_sort(arr_copy)
            end_time = time.time()
            average_time += end_time - start_time

        average_time /= iterations
        print(f"Tempo médio gasto (decrescente): {average_time:.6f} segundos")
        save_results(output_file, size, average_time, "decrescente")

if __name__ == "__main__":
    main()

