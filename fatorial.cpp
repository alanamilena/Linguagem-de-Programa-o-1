#include<iostream>

int main () {

int N;


std::cout <<  "Digite um numero inteiro positivo" <<std::endl;
std::cin >> N;

int fatorial = 1;

if (N < 0) {
    std::cout  << "Nao eh possivel calcular" <<std::endl; }
else {
while (N >= 1) {
fatorial = fatorial * N;
N--;
}
}

 std::cout  << fatorial << std::endl;

std::cin.ignore();
std::cin.get();
return 0;
}
