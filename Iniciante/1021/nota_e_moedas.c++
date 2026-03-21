#include <iostream>
#include <cstdint>

/**
 * Para printar um unit8_t deve-se converter para (int), se nao pode ser interpretado como char.
 * Na prática, uint8_t costuma ser um apelido de unsigned char, então:
 * uint8_t x = 65;
 * cout << x << endl; --> 'A'
 */

int main(){
    uint8_t notas[6] = {100, 50, 20, 10, 5, 2};
    float moedas[6] = {1, 0.50, 0.25, 0.10, 0.05 , 0.01};

    float money;
    uint8_t resto;
    float acc = 0;

    std::cin >> money;
    
    std::cout << "NOTAS" <<"\n";
    for(int i=0; i<6;i++){
        uint8_t nota = notas[i];
        resto = (uint8_t)(money / nota);
        std::cout << (int)resto << " nota(s) de R$ "<< (int)nota <<"\n";
        acc = acc + resto*nota;
        money = money - resto*nota;
    }

    std::cout << "MOEDAS" <<"\n";
    for(int i=0; i<6;i++){
        float moeda = moedas[i];
        resto = (uint8_t)(money / moeda);
        std::cout << (int)resto << " moeda(s) de R$ "<< moeda <<"\n";
        money = money - resto*moeda;
    }

    return 0;
}