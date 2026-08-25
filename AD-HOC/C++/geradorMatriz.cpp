#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream out("entrada.txt");

    int N = 600, M = 600;

    // Caso 1: Pior caso de TLE (Todos os elementos iguais a 1) -> Resposta esperada: 1
    out << N << " " << M << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << 1 << (j == M - 1 ? "" : " ");
        }
        out << "\n";
    }

    // Caso 2: Pior caso de Submatriz Gigante (Sequencial 1 a 360000) -> Resposta esperada: 360000
    out << N << " " << M << "\n";
    int val = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << val++ << (j == M - 1 ? "" : " ");
        }
        out << "\n";
    }

    // Final da entrada
    out << "0 0\n";
    out.close();

    cout << "Arquivo entrada.txt gerado com sucesso!" << endl;
    return 0;
}