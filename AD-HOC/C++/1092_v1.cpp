#include <iostream>
#include <string>
using namespace std;
// Teste automatico de tempo: Measure-Command { Get-Content entrada.txt | .\1092.exe }
// Teste automatico de multiplasEntradas : Get-Content entrada.txt | .\1092.exe

int values[2];
int M[600][600];
int totalColumn, totalLine, totalSub, maior = 0;

void fillMatrix(int values[2], int M[600][600]) {
    for (int i = 0; i < values[0]; i++) {
        for (int j = 0; j < values[1]; j++) {
            cin >> M[i][j]; // Usando cin em vez de scanf
        }
    }
}

int verifyLine(int values[2], int M[600][600]) {
    int total = 0;

    for (size_t i = 0; i < (size_t)values[0]; i++) {
        for (size_t j = 0; j < (size_t)values[1]; j++) {
            int head = M[i][j];
            int localTotal = 1;

            for (size_t jj = j + 1; jj < (size_t)values[1]; jj++) {
                int next = M[i][jj];
                if (next > head) {
                    head = next;
                    localTotal++;
                } else {
                    break;
                }
            }

            if (localTotal > total) {
                total = localTotal;
            }
        }
    }

    return total;
}

int verifyCollumn(int values[2], int M[600][600]) {
    int rows = values[0];
    int cols = values[1];
    int total = 0;

    for (size_t j = 0; j < (size_t)cols; j++) {
        for (size_t i = 0; i < (size_t)rows; i++) {
            int head = M[i][j];
            int localTotal = 1;

            for (size_t ii = i + 1; ii < (size_t)rows; ii++) {
                int next = M[ii][j];
                if (next > head) {
                    head = next;
                    localTotal++;
                } else {
                    break;
                }
            }

            if (localTotal > total) {
                total = localTotal;
            }
        }
    }

    return total;
}

// int checkSubMatrix(int values[2], int M[600][600]){

//     int columnRef=0, lineRef=0;
//     int column=1, line=0;
//     int total = 1;
//     int totalLocal = 1;
//     int current, next;
//     int step = 2;
//     int currentStep = 1;

//     current = M[lineRef][columnRef];

//     while (true)

//     {
//         if(column < values[1]){
//             next = M[line][column];

//             // cout << "Current "<< current << "\n";
//             // cout << "Next "<< next <<"\n";
//             // cout << "Line x Column "<< line << " x " << column <<"\n\n";

//             if(next > current){
//                 current = next;
//                 currentStep++;
//                 totalLocal++;
//                 if(currentStep >= step){
//                     line++;
//                     currentStep = 0;
//                     column = columnRef;
//                     if(totalLocal > total) total = totalLocal;
//                     // cout << "TotalLocal "<< totalLocal<<"\n\n";
//                 }else{
//                     column++;
//                 }
//             }else{
//                 if(line != lineRef){
//                     columnRef = columnRef+step-1;
//                 }else{

//                     columnRef++;
//                 }
//                 column = columnRef;
//                 line = lineRef;
//                 totalLocal = 1;
//                 current = M[line][column];
//                 column++;
//                 currentStep = 0;
//             }
//         }else{
//             lineRef++;
//             if(lineRef < values[0]){
//                 columnRef = 0;
//                 column = columnRef;
//                 line = lineRef;
//                 current = M[line][column];
//                 column++;
//             }else{
//                 columnRef++;
//             }
//         }
//         if(line >= values[0]){

//             // cout << "Last line: " << line <<"\n";
//             // cout << "values[0]: " << values[0] <<"\n";
//             // cout << "values[1]: " << values[1] <<"\n";
//             // cout << "columnRef: " << columnRef <<"\n";
//             // cout << "lineRef: " << lineRef <<"\n\n";

//             currentStep = 0;
//             column = columnRef;
//             line = lineRef;
//             step++;
//             if(totalLocal > total) total = totalLocal;
//         }

//         if(columnRef >= values[1] && lineRef >= values[0]) break;
//     }

//     return total;
// } 

int checkSubMatrix(int values[2], int M[600][600]) {
    int columnRef = 0, lineRef = 0;
    int column = 1, line = 0;
    int total = 1;
    int totalLocal = 1;
    int current, next;
    int step = 2;
    int currentStep = 1;

    current = M[lineRef][columnRef];

    while (true) {
        // 1. Condição de parada definitiva
        if (lineRef >= values[0]) break;

        // 2. Se a largura 'step' não cabe mais na matriz a partir de columnRef
        if (columnRef + step > values[1]) {
            columnRef++;
            if (columnRef >= values[1]) {
                columnRef = 0;
                lineRef++;
                if (lineRef >= values[0]) break;
            }
            step = 2;
            line = lineRef;
            column = columnRef;
            current = M[line][column];
            column++;
            currentStep = 1;
            totalLocal = 1;
            continue;
        }

        // 3. Processamento dentro dos limites da matriz
        if (column < values[1]) {
            next = M[line][column];

            if (next > current) {
                current = next;
                currentStep++;
                totalLocal++;

                if (currentStep >= step) {
                    if (totalLocal > total) total = totalLocal;

                    line++;
                    
                    // Se passou do limite de linhas da matriz
                    if (line >= values[0]) {
                        step++;
                        line = lineRef;
                        column = columnRef;
                        current = M[line][column];
                        column++;
                        currentStep = 1;
                        totalLocal = 1;
                    } else {
                        column = columnRef;
                        currentStep = 0; // CORRIGIDO: 0 para ler todos os elementos da nova linha
                    }
                } else {
                    column++;
                }
            } else {
                // Sequência quebrou: testa o próximo step para a mesma referência
                step++;
                line = lineRef;
                column = columnRef;
                current = M[line][column];
                column++;
                currentStep = 1;
                totalLocal = 1;
            }
        }
    }

    return total;
}

int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> values[0] >> values[1]) {
        if (values[0] == 0 && values[1] == 0) {
            break;
        }

        fillMatrix(values, M);

        totalColumn = verifyCollumn(values, M);
        totalLine = verifyLine(values, M);
        totalSub = checkSubMatrix(values, M);

        maior = 0;
        if (totalColumn > maior) maior = totalColumn;
        if (totalLine > maior) maior = totalLine;
        if (totalSub > maior) maior = totalSub;

        cout << maior << "\n"; // Usar "\n" em vez de endl (endl força flush)
    }

    return 0;
}