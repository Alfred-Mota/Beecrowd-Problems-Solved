#include <iostream>
#include <iomanip>
#include <cmath>
int main(){
    double notas[6] = {100, 50, 20, 10, 5, 2};
    double moedas[6] = {1.00, 0.50, 0.25, 0.10, 0.05 , 0.01};

    double money;
    int resto;
    double acc = 0;

    std::cin >> money;
    
    std::cout << "NOTAS:" <<"\n";
    for(int i=0; i<6;i++){
        double nota = notas[i];
        resto = (int)(money / nota);
        std::cout << (int)resto << " nota(s) de R$ "<< std::fixed << std::setprecision(2) << nota <<"\n";
        acc = acc + resto*nota;
        money = money - resto*nota;
    }

    std::cout << "MOEDAS:" <<"\n";
    for(int i=0; i<6;i++){
        double moeda = moedas[i]*100;

        double valor = (money*100) / moeda;
        if(round(valor)-valor >= .999 || round(valor)-valor < .001) resto = round((money*100) / moeda) ;
        else resto = ((money*100) / moeda);

        std::cout << resto << " moeda(s) de R$ "<< std::fixed << std::setprecision(2) << moeda/100 <<"\n";
        money = money - resto*(moeda/100);
    }

    return 0;
}