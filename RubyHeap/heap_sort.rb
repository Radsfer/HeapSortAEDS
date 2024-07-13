require 'time'

# Função para trocar dois elementos
def swap(arr, a, b)
  arr[a], arr[b] = arr[b], arr[a]
end

# Função para reorganizar a sub-árvore com a raiz no índice i
def heapify(arr, n, i, min_heap)
  extremo = i
  esq = 2 * i + 1
  dir = 2 * i + 2

  if min_heap
    extremo = esq if esq < n && arr[esq] < arr[extremo]
    extremo = dir if dir < n && arr[dir] < arr[extremo]
  else
    extremo = esq if esq < n && arr[esq] > arr[extremo]
    extremo = dir if dir < n && arr[dir] > arr[extremo]
  end

  if extremo != i
    swap(arr, i, extremo)
    heapify(arr, n, extremo, min_heap)
  end
end

# Função principal para realizar o Heap Sort
def heap_sort(arr, n, min_heap)
  (n / 2 - 1).downto(0) { |i| heapify(arr, n, i, min_heap) }
  (n - 1).downto(0) do |i|
    swap(arr, 0, i)
    heapify(arr, i, 0, min_heap)
  end
end

# Função para imprimir o array
def print_array(arr)
  puts arr.join(' ')
end

# Função para ler números do arquivo
def read_numbers_from_file(filename, n)
  arr = []
  File.open(filename, 'r') do |file|
    file.each_line do |line|
      arr += line.split.map(&:to_i)
      break if arr.size >= n
    end
  end
  arr[0...n]
end

# Função para salvar dados em arquivo
def salvar_dados_em_arquivo(filename, tamanho, tempo, tipo)
  File.open(filename, 'a') do |file|
    file.puts "Tamanho do vetor: #{tamanho}, Tempo médio gasto (#{tipo}): %.6f segundos" % tempo
  end
end

# Função para gerar um array em ordem crescente
def generate_sorted_array(n)
  (1..n).to_a
end

# Função para gerar um array em ordem decrescente
def generate_reverse_sorted_array(n)
  n.downto(1).to_a
end

# Função principal
def main
  n = [10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000]

  n.each do |size|
    # Teste com array aleatório do arquivo
    array = read_numbers_from_file('input.txt', size)
    tempo_gasto = 0.0
    iteracoes = 10

    iteracoes.times do
      copia = array.dup
      inicio = Time.now
      heap_sort(copia, size, false) # max heap para ordenação crescente
      fim = Time.now
      tempo_gasto += fim - inicio
    end

    tempo_gasto /= iteracoes

    puts "Tamanho do vetor: #{size}"
    puts "Tempo médio gasto (aleatório): %.6f segundos" % tempo_gasto
    salvar_dados_em_arquivo('TempoMedio.txt', size, tempo_gasto, 'aleatório')

    # Teste com array em ordem crescente
    array = generate_sorted_array(size)
    tempo_gasto = 0.0

    iteracoes.times do
      copia = array.dup
      inicio = Time.now
      heap_sort(copia, size, false) # max heap para ordenação crescente
      fim = Time.now
      tempo_gasto += fim - inicio
    end

    tempo_gasto /= iteracoes

    puts "Tempo médio gasto (crescente): %.6f segundos" % tempo_gasto
    salvar_dados_em_arquivo('TempoMedio.txt', size, tempo_gasto, 'crescente')

    # Teste com array em ordem decrescente
    array = generate_reverse_sorted_array(size)
    tempo_gasto = 0.0

    iteracoes.times do
      copia = array.dup
      inicio = Time.now
      heap_sort(copia, size, false) # max heap para ordenação crescente
      fim = Time.now
      tempo_gasto += fim - inicio
    end

    tempo_gasto /= iteracoes

    puts "Tempo médio gasto (decrescente): %.6f segundos" % tempo_gasto
    salvar_dados_em_arquivo('TempoMedio.txt', size, tempo_gasto, 'decrescente')
  end
end

main if __FILE__ == $0

