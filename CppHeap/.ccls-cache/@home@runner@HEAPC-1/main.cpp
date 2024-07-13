#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "HeapSort.hpp"

using namespace std;

vector<int> vetorAleatorio(int n)
{
    vector<int> vetor;
    for (int i = 0; i < n; i++){
        int aux = rand() % 100;
        vetor.push_back(aux);
    }
    return vetor;
}


int main() {
  vector<int>n = {10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000};

  for(int i=0; i<n.size(); i++){
  srand(time(NULL));
  cout<< "n = " << n[i] << endl;
  vector<int> arr = vetorAleatorio(n[i]);
  clock_t inicio, fim;
  double tempoGasto;


  inicio = clock();
  HeapSort hs(arr);
  hs.sort();
  fim = clock();
  
  tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

  cout << "Tempo gasto para ordenar um vetor de tamanho " << tempoGasto << endl;

  }
  return 0;
}