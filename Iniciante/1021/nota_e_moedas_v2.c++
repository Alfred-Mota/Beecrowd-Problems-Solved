#include <iostream>
#include <cstdint>

/**
 * Trabalhar com valores monetarios no formato de inteiro, multiplicando por 100
 */

int main(){
    int notas[6] = {100, 50, 20, 10, 5, 2};
    float moedas[6] = {1, 0.50, 0.25, 0.10, 0.05 , 0.01};

    int money;
    int resto;

    std::cin >> money;
    money = money*100;
    
    std::cout << "NOTAS" <<"\n";
    for(int i=0; i<6;i++){
        int nota = notas[i] * 100;
        resto = money / nota;
        std::cout << resto << " nota(s) de R$ "<< nota/100 <<"\n";
        money = money - resto*nota;
    }

    std::cout << "MOEDAS" <<"\n";
    for(int i=0; i<6;i++){
        int moeda = moedas[i]*100;
        resto = (money / moeda);
        std::cout << resto << " moeda(s) de R$ "<< moeda/100 <<"\n";
        money = money - resto*moeda;
    }

    return 0;
}