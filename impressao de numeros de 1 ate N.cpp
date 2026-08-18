#include<iostream>

int main () {

int N;
int atual = 1;

std::cout <<  "Digite um numero inteiro positivo" <<std::endl;
std::cin >> N;

while (atual <= N) {
std::cout  << atual << std::endl;
atual++;

 }

std::cin.ignore();
std::cin.get();
return 0;
}
