# Trabalho de comparação de tempos de algoritmo

O código serve para comparar o tempo do algoritmo HeapSort em diferentes linguagens.

## Link para o artigo
[![Overleaf](https://img.shields.io/badge/overleaf-template-brightgreen)](https://www.overleaf.com/read/wsfbfbdqffzf#471767)

## Membros do grupo 
- [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/msjujubr)Julia de Moura Souza
- [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Radsfer) Rafael Adolfo Silva Ferreira
- [![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Rutrama) Arthur Santana de Mesquita


# Como compilar em cada caso
gcc version 14.1.1 20240701 (Red Hat 14.1.1-7) (GCC) 
´´´bash
gcc -03 -o heap_sort heap_sort.cpp
./heap_sort
´´´

´´´bash
gcc -03 -o main main.cpp heap_sort.cpp
./main
´´´

julia version 1.9.2
´´´bash
julia heap_sort.jl
´´´

javac 21.0.3
´´´bash
javac HeapSort.java Main.java
java Main
´´´
Python 3.12.4
´´´bash
python3 heap_sort.py
´´´
ruby 3.3.2 (2024-05-30 revision e5a195edf6) [x86_64-linux]
´´´bash
ruby heap_sort.rb
´´´
