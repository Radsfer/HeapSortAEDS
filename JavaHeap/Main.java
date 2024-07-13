import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    // Função para ler dados do arquivo de entrada
    public static int[] lerEntradasDoArquivo(String filename, int quantidade) throws IOException {
        int[] vetor = new int[quantidade];
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String line = reader.readLine();
        reader.close();

        if (line != null) {
            String[] numbers = line.trim().split("\\s+");
            for (int i = 0; i < quantidade; i++) {
                vetor[i] = Integer.parseInt(numbers[i]);
            }
        }
        
        return vetor;
    }

    // Função para salvar resultados em arquivo
    public static void salvarResultados(List<String> resultados, String filename) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
        for (String resultado : resultados) {
            writer.write(resultado);
            writer.newLine();
        }
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        int[] n = {10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000};
        String inputFile = "input.txt";
        String outputFile = "tempos_medios.txt";
        List<String> resultados = new ArrayList<>();

        for (int i = 0; i < n.length; i++) {
            System.out.println("n = " + n[i]);
            int[] arrOriginal = lerEntradasDoArquivo(inputFile, n[i]);

            // Caso 1: Vetor aleatório
            int[] arr = Arrays.copyOf(arrOriginal, arrOriginal.length);
            double media = 0.0;
            for (int j = 0; j < 10; j++) {
                long inicio = System.nanoTime();
                HeapSort hs = new HeapSort(arr);
                hs.sort();
                long fim = System.nanoTime();
                double tempoGasto = (fim - inicio) / 1e9; // convertendo para segundos
                media += tempoGasto;
                arr = Arrays.copyOf(arrOriginal, arrOriginal.length); // Restaurando vetor original
            }
            media /= 10;
            resultados.add("Tempo médio para entrada " + n[i] + " caso(aleatório): " + media + " segundos");

            // Caso 2: Vetor ordenado crescentemente
            Arrays.sort(arrOriginal);
            arr = Arrays.copyOf(arrOriginal, arrOriginal.length);
            media = 0.0;
            for (int j = 0; j < 10; j++) {
                long inicio = System.nanoTime();
                HeapSort hs = new HeapSort(arr);
                hs.sort();
                long fim = System.nanoTime();
                double tempoGasto = (fim - inicio) / 1e9; // convertendo para segundos
                media += tempoGasto;
                arr = Arrays.copyOf(arrOriginal, arrOriginal.length); // Restaurando vetor original
            }
            media /= 10;
            resultados.add("Tempo médio para entrada " + n[i] + " caso(crescente): " + media + " segundos");

            // Caso 3: Vetor ordenado decrescentemente
            Arrays.sort(arrOriginal);
            arr = Arrays.copyOf(arrOriginal, arrOriginal.length);
            reverse(arr);
            media = 0.0;
            for (int j = 0; j < 10; j++) {
                long inicio = System.nanoTime();
                HeapSort hs = new HeapSort(arr);
                hs.sort();
                long fim = System.nanoTime();
                double tempoGasto = (fim - inicio) / 1e9; // convertendo para segundos
                media += tempoGasto;
                arr = Arrays.copyOf(arrOriginal, arrOriginal.length); // Restaurando vetor original
            }
            media /= 10;
            resultados.add("Tempo médio para entrada " + n[i] + " caso(decrescente): " + media + " segundos");
        }

        salvarResultados(resultados, outputFile);

        System.out.println("Resultados salvos em " + outputFile);
    }

    // Função para inverter um array
    public static void reverse(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

