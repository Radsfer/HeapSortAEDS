function swap!(arr, a, b)
    arr[a], arr[b] = arr[b], arr[a]
end

function heapify!(arr, n, i, min_heap)
    extremo = i
    esq = 2 * i + 1
    dir = 2 * i + 2

    if min_heap
        if esq < n && arr[esq] < arr[extremo]
            extremo = esq
        end
        if dir < n && arr[dir] < arr[extremo]
            extremo = dir
        end
    else
        if esq < n && arr[esq] > arr[extremo]
            extremo = esq
        end
        if dir < n && arr[dir] > arr[extremo]
            extremo = dir
        end
    end

    if extremo != i
        swap!(arr, i, extremo)
        heapify!(arr, n, extremo, min_heap)
    end
end

function heap_sort!(arr, min_heap)
    n = length(arr)
    for i in div(n, 2):-1:1
        heapify!(arr, n, i, min_heap)
    end
    for i in n:-1:2
        swap!(arr, 1, i)
        heapify!(arr, i - 1, 1, min_heap)
    end
end

function read_numbers_from_file(filename, n)
    arr = Int[]
    open(filename, "r") do file
        for line in eachline(file)
            append!(arr, parse.(Int, split(line)))
            if length(arr) >= n
                break
            end
        end
    end
    return arr[1:min(n, length(arr))]
end

function salvar_dados_em_arquivo(filename, tamanho, tempo, tipo)
    open(filename, "a") do file
        println(file, "Tamanho do vetor: $tamanho, Tempo médio gasto ($tipo): $tempo segundos")
    end
end

function generate_sorted_array(n)
    return collect(1:n)
end

function generate_reverse_sorted_array(n)
    return collect(n:-1:1)
end

function main()
    n = [10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000]

    for size in n
        if size > 10^6
            println("Size too large to handle")
            continue
        end

        # Teste com array aleatório do arquivo
        array = read_numbers_from_file("input.txt", size)
        if length(array) < size
            println("Not enough numbers in input.txt for size $size")
            continue
        end

        tempo_gasto = 0.0
        iteracoes = 10

        for _ in 1:iteracoes
            copia = copy(array)
            inicio = time()
            heap_sort!(copia, false) # max heap para ordenação crescente
            fim = time()
            tempo_gasto += fim - inicio
        end

        tempo_gasto /= iteracoes

        println("Tamanho do vetor: ", size)
        println("Tempo médio gasto (aleatório): ", round(tempo_gasto, digits=6), " segundos")
        salvar_dados_em_arquivo("TempoMedio.txt", size, round(tempo_gasto, digits=6), "aleatório")

        # Teste com array em ordem crescente
        array = generate_sorted_array(size)
        tempo_gasto = 0.0

        for _ in 1:iteracoes
            copia = copy(array)
            inicio = time()
            heap_sort!(copia, false) # max heap para ordenação crescente
            fim = time()
            tempo_gasto += fim - inicio
        end

        tempo_gasto /= iteracoes

        println("Tempo médio gasto (crescente): ", round(tempo_gasto, digits=6), " segundos")
        salvar_dados_em_arquivo("TempoMedio.txt", size, round(tempo_gasto, digits=6), "crescente")

        # Teste com array em ordem decrescente
        array = generate_reverse_sorted_array(size)
        tempo_gasto = 0.0

        for _ in 1:iteracoes
            copia = copy(array)
            inicio = time()
            heap_sort!(copia, false) # max heap para ordenação crescente
            fim = time()
            tempo_gasto += fim - inicio
        end

        tempo_gasto /= iteracoes

        println("Tempo médio gasto (decrescente): ", round(tempo_gasto, digits=6), " segundos")
        salvar_dados_em_arquivo("TempoMedio.txt", size, round(tempo_gasto, digits=6), "decrescente")
    end
end

main()

