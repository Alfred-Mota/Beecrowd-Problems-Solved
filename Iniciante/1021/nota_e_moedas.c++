#include <iostream>

int main(){
    uint8_t notas[6] = {100, 50, 20, 10, 5, 2};
    float moedas[6] = {1, 0.50, 0.25, 0.10, 0.05 , 0.01};

    float money;
    uint8_t resto;
    float acc = 0;

    std::cin >> money;
    
    std::cout << "NOTAS" <<"\n";
    for(int i=0; i<6;i++){
        int nota = notas[i];
        resto = (int)(money / nota);
        std::cout << resto << " nota(s) de R$ "<< nota <<"\n";
        acc = acc + resto*nota;
        money = money - resto*nota;
    }

    std::cout << "MOEDAS" <<"\n";
    for(int i=0; i<6;i++){
        float moeda = moedas[i];
        resto = (int)(money / moeda);
        std::cout << resto << " moeda(s) de R$ "<< moeda <<"\n";
        money = money - resto*moeda;
    }

    return 0;
}