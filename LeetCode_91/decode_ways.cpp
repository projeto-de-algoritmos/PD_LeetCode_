#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Função recursiva que calcula o número de formas de decodificar a string
    int fun(int i, const std::string& s, std::vector<int>& dp) {
        // Caso base: quando i < 0, uma decodificação válida foi encontrada
        if (i < 0) {
            return 1;
        }
        // Caso base: se i for 0, verifica se o caractere é '0', que não pode ser decodificado
        if (i == 0) {
            return s[i] == '0' ? 0 : 1;
        }
        // Verifica se já foi calculado o valor para o índice 'i', para evitar calcular novamente
        if (dp[i] != -1) {
            return dp[i];
        }

        int take = 0;

        // Se o caractere atual não for '0', ele pode ser decodificado individualmente
        if (s[i] != '0') {
            take = fun(i - 1, s, dp);
        }

        // Verifica se os dois últimos caracteres formam um número válido entre 10 e 26
        if (i - 1 >= 0 && s[i - 1] != '0' && std::stoi(s.substr(i - 1, 2)) <= 26) {
            take += fun(i - 2, s, dp);
        }

        return dp[i] = take;
    }

    // Função principal que inicializa o vetor dp e chama a função recursiva
    int numDecodings(const std::string& s) {
        // Verifica se a string é vazia, se for, não há como decodificar 
        if (s.empty()) {
            return 0;
        }
        std::vector<int> dp(s.length() + 1, -1);
        return fun(s.length() - 1, s, dp);
    }
};
