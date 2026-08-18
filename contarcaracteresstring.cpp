#include<iostream>
#include <string>

int main () {
std::string texto;

std::cout  << "Digite uma frase: " << std::endl;

std::getline(std::cin,texto);

std::cout  << texto << std::endl;

std::cout  << "Quantidade de caracteres eh: " << texto.size () << std::endl;

std::cin.ignore();
std::cin.get();
return 0;
}

