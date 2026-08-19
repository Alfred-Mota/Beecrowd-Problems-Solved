#include<iostream>
#include<iomanip>

int main(){
    double pi = 3.14159;
    double raio;

    std::cin >> raio;

    double area = raio*raio*pi;

    std::cout << "A=" << std::setprecision(6) << area <<"\n";
    return 0;
}