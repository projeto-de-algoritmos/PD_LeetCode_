#include <vector>
#include <climits> // Para usar INT_MIN

class Solution {
public:
    int ans = 0; // Variável para armazenar o número de saltos

    // Função principal que calcula o número mínimo de saltos
    int jump(std::vector<int>& nums) {
        int i = 0; // Começa no primeiro índice
        // Continua até alcançar o penúltimo índice
        while (i < nums.size() - 1) {
            i = helper(i, nums[i], nums); // Chama a função auxiliar para determinar o próximo salto
        }
        return ans; // Retorna o número total de saltos
    }

    // Função auxiliar que encontra o melhor índice para pular
    int helper(int a, int b, std::vector<int>& nums) {
        ans++; // Incrementa o contador de saltos
        // Se o salto atual pode alcançar ou ultrapassar o último índice, terminamos
        if (a + b >= nums.size() - 1) {
            return nums.size(); // Retorna o tamanho do array para indicar que alcançamos o final
        }

        int max = INT_MIN; // Variável para armazenar o valor máximo possível de alcance
        int temp = 0; // Variável para armazenar o índice do próximo salto
        // Itera sobre todos os índices possíveis de alcance do salto atual
        for (int i = a; i <= a + b; i++) {
            // Verifica se o índice atual permite alcançar uma posição mais distante
            if (nums[i] + i >= max) {
                temp = i; // Atualiza o índice do próximo salto
                max = nums[i] + i; // Atualiza o valor máximo de alcance
            }
        }
        return temp; // Retorna o índice do próximo salto
    }
};
