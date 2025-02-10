# Leetcode1845
Code solving exercise number 1845 from Leetcode.

#Informações Gerais
**Problema:** O problema pede para criar um sistema que faça o gerenciamento de mesas em um restaurante. Para um número N de mesas, espera-se que sempre seja reservada a mesa de menor número. As mesas também podem ser desreservadas, de modo que voltem para o universo de mesas disponíveis na sua ordem original.

**Solução:** Para resolver esse problema em um tempo razoável (uma vez que o número N de mesas pode ser imenso, impossibilitando a busca linear), é necessário a utilização do sistema de busca binário min-heap.
