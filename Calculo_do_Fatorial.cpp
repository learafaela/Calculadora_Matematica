#include <iostream>
#include <limits>

// Função para calcular o número de combinações simples C(n, r) diretamente
unsigned long long calcular_combinacao(int n, int r) {
    if (r > n) {
        return 0; // Não é possível escolher mais elementos do que existem
    }
    if (r == 0 || r == n) {
        return 1; // Caso especial
    }
   
    // Utiliza a propriedade C(n, r) = C(n, n-r) para reduzir o número de iterações
    if (r > n - r) {
        r = n - r;
    }

    unsigned long long resultado = 1;
    for (int i = 0; i < r; ++i) {
        if (resultado > std::numeric_limits<unsigned long long>::max() / (n - i)) {
            std::cerr << "Erro: Overflow durante o cálculo." << std::endl;
            return 0;
        }
        resultado *= (n - i);
        resultado /= (i + 1);
    }
    return resultado;
}

int main() {
    int n, r;

    std::cout << "Digite o valor de n: ";
    std::cin >> n;
    if (std::cin.fail()) {
        std::cerr << "Entrada inválida. Por favor, insira um número inteiro." << std::endl;
        return 1;
    }

    std::cout << "Digite o valor de r: ";
    std::cin >> r;
    if (std::cin.fail()) {
        std::cerr << "Entrada inválida. Por favor, insira um número inteiro." << std::endl;
        return 1;
    }

    if (n < 0 || r < 0) {
        std::cerr << "Os valores de n e r devem ser não negativos." << std::endl;
        return 1;
    }

    if (r > n) {
        std::cerr << "O valor de r não pode ser maior que n." << std::endl;
        return 1;
    }

    unsigned long long resultado = calcular_combinacao(n, r);
    if (resultado == 0) {
        std::cerr << "Não foi possível calcular o resultado." << std::endl;
        return 1;
    }
    std::cout << "O número de combinações simples C(" << n << ", " << r << ") é: " << resultado << std::endl;

    return 0;
}