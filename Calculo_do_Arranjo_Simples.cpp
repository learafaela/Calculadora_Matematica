#include <iostream>
#include <limits>

// Função para calcular o número de arranjos simples diretamente
unsigned long long calcular_arranjo_simples(int n, int r) {
    if (n < r || r < 0) {
        return 0; // Não é possível escolher mais elementos do que disponíveis ou r negativo
    }

    unsigned long long resultado = 1;
    for (int i = 0; i < r; ++i) {
        // Verifica se a multiplicação não excede o limite do tipo
        if (resultado > std::numeric_limits<unsigned long long>::max() / (n - i)) {
            std::cerr << "Erro: Overflow detectado na multiplicação.\n";
            return 0;
        }
        resultado *= (n - i);
    }
   
    return resultado;
}

int main() {
    int n, r;

    std::cout << "Digite o número total de elementos (n): ";
    while (!(std::cin >> n) || n < 0) {
        std::cout << "Entrada inválida. Por favor, insira um número inteiro não negativo para n: ";
        std::cin.clear(); // Limpa o estado de erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada inválida
    }

    std::cout << "Digite o número de elementos a serem escolhidos (r): ";
    while (!(std::cin >> r) || r < 0) {
        std::cout << "Entrada inválida. Por favor, insira um número inteiro não negativo para r: ";
        std::cin.clear(); // Limpa o estado de erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora entrada inválida
    }

    unsigned long long resultado = calcular_arranjo_simples(n, r);
    if (resultado == 0 && (n < r || r < 0)) {
        std::cout << "Não é possível calcular arranjos simples com os valores fornecidos.\n";
    } else {
        std::cout << "O número de arranjos simples de " << n << " elementos escolhendo " << r << " é " << resultado << std::endl;
    }

    return 0;
}