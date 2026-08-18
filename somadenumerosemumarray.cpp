#include<iostream>

int main () {

int numeros [5];

std::cout  << "Digite 5 numeros inteiros" << std::endl;

std::cin >> numeros[0];
std::cin >> numeros[1];
std::cin >> numeros[2];
std::cin >> numeros[3];
std::cin >> numeros[4];

int soma = 0;
int i = 0;

while (i < 5) {
    soma = soma + numeros[i];
    i++;
}


 

 std::cout  << "Resultado: " << soma << std::endl;

std::cin.ignore();
std::cin.get();
return 0;
}