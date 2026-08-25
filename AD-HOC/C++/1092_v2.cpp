#include <iostream>

/**
 * A ideia é pre computar quantos algarismos crescentes há em cada posição em cada linha,
 * em seguida verificar se a linha de baixo possui um numero maior ou igual na mesma posição
 */

using namespace std;
int M[600][600], auxiliar[600][600];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rows, cols;

    while(cin>>rows>>cols && (rows != 0 || cols != 0)){

        //Guardando os dados na matriz principal
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> M[i][j];
            }
        }

        //Calculando o numero maximo de numeros na ordem crescente
        for(int row = 0; row<rows; row++){
            //o ultimo elemento de cada linha não possui nada a direita
            auxiliar[row][cols - 1] = 1;
            for(int col = cols-2; col>=0; col--){
                if(M[row][col + 1] > M[row][col]){
                    //o numero de elementos em ordem crescente é igual ao da coluna da frente mais 1.
                    auxiliar[row][col] = auxiliar[row][col+1] + 1;
                }else{
                    auxiliar[row][col] = 1;
                }
            }
        }

        int maiorArea = 1;

        //Será calculado as sub-matrizes
        for(int c1 = 0; c1 < cols; c1++){
            for(int c2 = c1; c2 < cols; c2++){
                int largura = c2 - c1 + 1;
                int alturaAtual = 0;

                //Agora percorremos a matriz auxiliar procurando sequencias iguais ou maiores o largura da submatriz
                for(int row = 0; row < rows; row++){
                    
                    if(auxiliar[row][c1] >= largura){
                        if(alturaAtual == 0 || M[row][c1] > M[row - 1][c2]) alturaAtual++;
                        else alturaAtual = 1;
                        maiorArea = max(maiorArea, alturaAtual*largura);
                    }else{
                        alturaAtual = 0;
                    }
                }
            }
        }
        cout << maiorArea << "\n";
    }

    return 0;
}
