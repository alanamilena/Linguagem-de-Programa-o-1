#include<iostream>
int main () {
std::cout  << "Digite a opcao: " << std::endl;
std::cout  << "1. Celsius para Fahrenheit" << std::endl;
std::cout  << "2. Fahrenheit para Celsius" << std::endl;

int opcao;
std::cin >> opcao;

double temperatura;
std::cout  << "Digite a temperatura a ser transformada: " << std::endl;
std::cin >> temperatura;



if (opcao == 1)
{
    std::cout  << "Voce escolheu Celsius para Fahrenheit" << std::endl;
    temperatura = temperatura * 9.0/5 + 32;
    std::cout  << "O resultado eh: " << temperatura << std::endl;    
}
else if (opcao == 2) {
    std::cout  << "Voce escolheu Fahrenheit para Celsius" << std::endl;
    temperatura = (temperatura - 32) * 5.0/9;
    std::cout  << "O resultado eh: " << temperatura << std::endl;
}

else {
    std::cout  << "Opcao invalida" << std::endl;
}

std::cin.ignore();
std::cin.get();
return 0;
}
