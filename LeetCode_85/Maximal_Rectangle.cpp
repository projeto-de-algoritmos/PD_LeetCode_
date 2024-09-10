#include <vector>
#include <algorithm> // Para usar a função std::max e std::min
#include <cstring>   // Para a função memset

class Solution {
public:
    // Função principal que encontra o maior retângulo de 1's em uma matriz binária
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        // Verifica se a matriz está vazia
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = matrix.size();      // Número de linhas
        int n = matrix[0].size();   // Número de colunas

        // Arrays para armazenar as alturas, limites esquerdos e direitos
        std::vector<int> heights(n, 0);
        std::vector<int> leftBoundaries(n, 0);
        std::vector<int> rightBoundaries(n, n);
        
        int maxRectangle = 0;  // Variável para armazenar a área máxima do retângulo

        // Percorre todas as linhas da matriz
        for (int i = 0; i < m; i++) {
            int left = 0;     // Inicializa a posição mais à esquerda
            int right = n;    // Inicializa a posição mais à direita

            // Atualiza as alturas e os limites esquerdos
            updateHeightsAndLeftBoundaries(matrix[i], heights, leftBoundaries, left);

            // Atualiza os limites direitos
            updateRightBoundaries(matrix[i], rightBoundaries, right);

            // Calcula a área máxima do retângulo
            maxRectangle = calculateMaxRectangle(heights, leftBoundaries, rightBoundaries, maxRectangle);
        }

        return maxRectangle;
    }

private:
    // Função para atualizar as alturas e os limites esquerdos
    void updateHeightsAndLeftBoundaries(std::vector<char>& row, std::vector<int>& heights, std::vector<int>& leftBoundaries, int& left) {
        for (int j = 0; j < heights.size(); j++) {
            if (row[j] == '1') {
                heights[j]++;  // Aumenta a altura se for '1'
                leftBoundaries[j] = std::max(leftBoundaries[j], left);  // Atualiza o limite esquerdo
            } else {
                heights[j] = 0;    // Zera a altura se for '0'
                leftBoundaries[j] = 0;  // Define o limite esquerdo como 0
                left = j + 1;  // Move o limite esquerdo para a próxima coluna
            }
        }
    }

    // Função para atualizar os limites direitos
    void updateRightBoundaries(std::vector<char>& row, std::vector<int>& rightBoundaries, int& right) {
        for (int j = rightBoundaries.size() - 1; j >= 0; j--) {
            if (row[j] == '1') {
                rightBoundaries[j] = std::min(rightBoundaries[j], right);  // Atualiza o limite direito
            } else {
                rightBoundaries[j] = right;  // Define o limite direito como a posição atual
                right = j;  // Move o limite direito para a esquerda
            }
        }
    }

    // Função para calcular a área máxima do retângulo
    int calculateMaxRectangle(std::vector<int>& heights, std::vector<int>& leftBoundaries, std::vector<int>& rightBoundaries, int maxRectangle) {
        for (int j = 0; j < heights.size(); j++) {
            int width = rightBoundaries[j] - leftBoundaries[j];  // Calcula a largura do retângulo
            int area = heights[j] * width;  // Calcula a área do retângulo
            maxRectangle = std::max(maxRectangle, area);  // Atualiza a área máxima
        }
        return maxRectangle;
    }
};
