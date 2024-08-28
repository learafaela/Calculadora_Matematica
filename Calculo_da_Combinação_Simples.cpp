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
        // Verifica se o próximo cálculo causaria overflow
        if (resultado > std::numeric_limits<unsigned long long>::max() / (n - i)) {
            std::cerr << "Erro: Overflow detectado." << std::endl;
            return 0;
        }
        resultado *= (n - i);
       
        // Verifica se a divisão causaria overflow
        if (resultado % (i + 1) != 0) {
            std::cerr << "Erro: Overflow detectado durante a divisão." << std::endl;
            return 0;
        }
        resultado /= (i + 1);
    }
    return resultado;
}

int main() {
    int n, r;

    std::cout << "Digite o valor de n: ";
    std::cin >> n;
    if (std::cin.fail() || n < 0) {
        std::cerr << "Erro: Valor de n inválido. Deve ser um número inteiro não negativo." << std::endl;
        return 1;
    }

    std::cout << "Digite o valor de r: ";
    std::cin >> r;
    if (std::cin.fail() || r < 0) {
        std::cerr << "Erro: Valor de r inválido. Deve ser um número inteiro não negativo." << std::endl;
        return 1;
    }

    unsigned long long resultado = calcular_combinacao(n, r);
    if (resultado == 0 && (n > 0 && r > 0)) {
        std::cerr << "Erro: O cálculo das combinações resultou em overflow." << std::endl;
        return 1;
    }

    std::cout << "O número de combinações simples C(" << n << ", " << r << ") é: " << resultado << std::endl;

    return 0;
}
