#include<iostream>

int main() {

    int N;

    std::cout << "Digite um numero inteiro positivo" << std::endl;
    std::cin >> N;

    int i = 2;
    bool divisor = false;

    if (N <= 1) {
        std::cout << "Erro" << std::endl;
    }
    else {

        while (i < N) {

            if (N % i == 0) {
                divisor = true;
            }

            i++;
        }

        if (divisor == true) {
            std::cout << "Nao eh primo" << std::endl;
        }
        else {
            std::cout << "Eh primo" << std::endl;
        }
    }

    std::cin.ignore();
    std::cin.get();

    return 0;
}