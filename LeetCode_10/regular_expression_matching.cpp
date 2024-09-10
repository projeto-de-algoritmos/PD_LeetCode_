#include <vector>
#include <string>

class Solution {
public:
    // Função principal que verifica se a string 's' corresponde ao padrão 'p'
    bool isMatch(const std::string& s, const std::string& p) {
        if (s.empty() || p.empty()) {
            return false;
        }

        // Criação da matriz dp para armazenar resultados intermediários
        std::vector<std::vector<bool>> dp(s.length() + 1, std::vector<bool>(p.length() + 1, false));
        dp[0][0] = true; // Padrão vazio corresponde a string vazia

        // Preenche a primeira linha da matriz dp, lidando com '*' no padrão
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == '*' && dp[0][i - 1]) {
                dp[0][i + 1] = true;
            }
        }

        // Preenche a matriz dp com base na correspondência entre s e p
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < p.length(); j++) {
                // Se o caractere do padrão for '.', corresponde a qualquer caractere da string
                if (p[j] == '.') {
                    dp[i + 1][j + 1] = dp[i][j];
                }

                // Se o caractere do padrão for igual ao caractere da string
                if (p[j] == s[i]) {
                    dp[i + 1][j + 1] = dp[i][j];
                }

                // Se o caractere do padrão for '*', analisa os casos possíveis
                if (p[j] == '*') {
                    // Se o caractere anterior ao '*' não corresponde ao caractere atual da string
                    if (p[j - 1] != s[i] && p[j - 1] != '.') {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1]; // Ignora o par anterior
                    } else {
                        // Considera três possíveis correspondências: ignorar '*', tomar uma ou múltiplas ocorrências
                        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                    }
                }
            }
        }

        // Retorna o valor na última célula, que indica se toda a string corresponde ao padrão
        return dp[s.length()][p.length()];
    }
};
