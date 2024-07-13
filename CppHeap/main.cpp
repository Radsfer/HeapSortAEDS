#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "HeapSort.hpp"

// Função para ler dados do arquivo de entrada
std::vector<int> lerEntradasDoArquivo(const std::string& filename, int quantidade) {
    std::vector<int> vetor;
    std::ifstream file(filename);
    std::string line;
    
    if (file.is_open()) {
        getline(file, line);
        std::istringstream iss(line);
        int num;
        for (int i = 0; i < quantidade && iss >> num; i++) {
            vetor.push_back(num);
        }
        file.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
    }
    
    return vetor;
}

// Função para salvar resultados em arquivo
void salvarResultados(const std::vector<std::pair<std::string, double>>& resultados, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& resultado : resultados) {
            file << resultado.first << " : " << resultado.second << " segundos" << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita." << std::endl;
    }
}

int main() {
    std::vector<int> n = {10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000};
    std::string inputFile = "input.txt";
    std::string outputFile = "tempos_medios.txt";
    std::vector<std::pair<std::string, double>> resultados;

    for (int i = 0; i < n.size(); i++) {
        std::cout << "n = " << n[i] << std::endl;
        std::vector<int> arrOriginal = lerEntradasDoArquivo(inputFile, n[i]);
        if (arrOriginal.size() < n[i]) {
            std::cerr << "Erro: Não há entradas suficientes no arquivo para n = " << n[i] << std::endl;
            return 1;
        }

        // Caso 1: Vetor aleatório
        std::vector<int> arr = arrOriginal; // Clonando vetor original
        double media = 0.0;
        for (int j = 0; j < 10; j++) {
            clock_t inicio = clock();
            HeapSort hs(arr);
            hs.sort();
            clock_t fim = clock();
            double tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            media += tempoGasto;
            arr = arrOriginal; // Restaurando vetor para estado original
        }
        media /= 10;
        resultados.push_back(std::make_pair("Tempo médio para entrada " + std::to_string(n[i]) + " caso(aleatório)", media));

        // Caso 2: Vetor ordenado crescentemente
        std::sort(arrOriginal.begin(), arrOriginal.end());
        arr = arrOriginal; // Clonando vetor ordenado
        media = 0.0;
        for (int j = 0; j < 10; j++) {
            clock_t inicio = clock();
            HeapSort hs(arr);
            hs.sort();
            clock_t fim = clock();
            double tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            media += tempoGasto;
            arr = arrOriginal; // Restaurando vetor para estado original
        }
        media /= 10;
        resultados.push_back(std::make_pair("Tempo médio para entrada " + std::to_string(n[i]) + " caso(crescente)", media));

        // Caso 3: Vetor ordenado decrescentemente
        std::sort(arrOriginal.rbegin(), arrOriginal.rend());
        arr = arrOriginal; // Clonando vetor ordenado decrescente
        media = 0.0;
        for (int j = 0; j < 10; j++) {
            clock_t inicio = clock();
            HeapSort hs(arr);
            hs.sort();
            clock_t fim = clock();
            double tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            media += tempoGasto;
            arr = arrOriginal; // Restaurando vetor para estado original
        }
        media /= 10;
        resultados.push_back(std::make_pair("Tempo médio para entrada " + std::to_string(n[i]) + " caso(decrescente)", media));
    }

    salvarResultados(resultados, outputFile);

    std::cout << "Resultados salvos em " << outputFile << std::endl;

    return 0;
}

