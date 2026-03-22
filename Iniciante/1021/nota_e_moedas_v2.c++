#include <iostream>
#include <iomanip>

/**
 * Trabalhar com valores monetarios no formato de inteiro, multiplicando por 100
 */

int main(){
    double notas[6] = {100, 50, 20, 10, 5, 2};
    float moedas[6] = {1, 0.50, 0.25, 0.10, 0.05 , 0.01};

    double money;
    int resto;

    std::cin >> money;
    money = money*100;
    
    std::cout << "NOTAS:" <<"\n";
    for(int i=0; i<6;i++){
        double nota = notas[i] * 100;
        resto = (int)money / nota;
        std::cout << resto << " nota(s) de R$ "<< std::fixed << std::setprecision(2) << nota/100 <<"\n";
        money = money - resto*nota;
    }

    std::cout << "MOEDAS:" <<"\n";
    for(int i=0; i<6;i++){
        double moeda = moedas[i]*100;
        resto = int(money / moeda);
        std::cout << resto << " moeda(s) de R$ "<< std::fixed << std::setprecision(2)<< moeda/100 <<"\n";
        money = money - resto*moeda;
    }

    return 0;
}