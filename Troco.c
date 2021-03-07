#include <stdio.h>
 
// Encontra a maior potência de base 2 mais próxima de n tal que n seja maior ou
// igual a potência
int maiorPot(int n, int i)
{
    // Deslocando bit para direita até que o resultado seja 1 garantimos que
    // o valor da quantidade de bits deslocados é o expoente da potência de
    // base 2 que mais se aproxima da entrada, uma vez que ao deslocarmos o
    // bit para direita, a quantidade de bits deslocado será o expoente da
    // potência de base 2 e a operação é o equivalente a obter o floor da
    // divisão de um número por 2^i, como estamos obtendo o floor da
    // divisão, em algum momento a divisão terá o resultado 1
    if (n >> i == 1)
        return i;
 
    // Caso não seja um, i é incrementado e a função é chamada de forma
    // recursiva, repare que i é o valor do expoente citado anteriormente
    maiorPot(n, ++i);
}
 
// Função que faz a análise das potências de 2 onde será escolhido a menor das
// diferenças, n - 2^i ou 2^(i+1) - n e as mesmas acontecerá de forma recursiva
// sendo analisada etapa por etapa, trazendo a melhor das soluções
int analisa(int n, int i, int quant)
{
    // É declarado aqui duas variáveias auxiliares onde uma obtém a potência
    // de 2 mais próxima sendo necessariamente menor ou igual a n, no caso
    // "potMenor", e a outra obtém a potência de base 2 mais próxima de n
    // sendo necessariamente maior do que n, no caso "potMaior"
    int potMenor = 1 << i, potMaior = 1 << i + 1;
 
    // Nesta condição é deslocado o bit para esquerda a partir de 1, ou 2^0,
    // i vezes e analisado se o resultado é o mesmo que n, isso por que ao
    // deslocarmos um bit a esquerda é equivalente a multiplicar por 2.
    // logo, para i vezes temos 1*2^i. Caso o valor de entrada n seja uma
    // potência de base 2, ele poderá ser escrito da forma 2^i onde i é o
    // valor que já teria sido calculado antes de entrar nessa função,
    // assim, quant que anteriormente era 0, será incrementado e o programa
    // resultará em 1 moeda, caso isso não aconteça, a função fará a sua
    // verificação passando para n a menor das diferenças e em algum momento
    // n poderá ser escrito como 2^i sendo n = 1 o limite onde o mesmo pode
    // ser escrito como 2^0
    if (1 << i == n)
        return ++quant;
 
    // Nesta condição temos, então, o início das análises das diferenças
    // citadas, para esta em específico é analisado se 2^(i+1) - n é menor
    // do que n - 2^i, caso seja, i obterá o resultado do expoente de 2^i
    // que mais se aproxima de 2^(i+1) - n onde 2^i é menor ou igual a
    // 2^(i+1) - n e, assim, a função é chamada de forma recursiva obtendo
    // como parâmetros o novo i e n igual a diferença 2^(i+1) - n. Caso a
    // condição não seja verdade, então, necessariamente, n - 2^i é menor do
    // que 2^(i+1) - n, assim, i obterá o resultado do expoente de 2^i que
    // mais se aproxima de n - 2^i onde 2^i é menor ou igual a n - 2^i e a
    // função é chamada de forma recursiva obtendo como parâmetros o novo i
    // e n igual a diferença n - 2^i
    if (potMaior - n < n - potMenor) {
        i = maiorPot(potMaior - n, 0);
        analisa(potMaior - n, i, ++quant);
    } else {
        i = maiorPot(n - potMenor, 0);
        analisa(n - potMenor, i, ++quant);
    }
}
 
int main()
{
    // Para o problema, foram declaradas 3 variáveis onde i representará o
    // expoente da potência de base 2, n é a entrada e quant é a quantidade
    // de moedas de saída
    int n, i, quant;
    scanf("%d", &n);
 
    // A princípio, é utilizado a função para encontrar a potência mais
    // próxima, pois, caso a entrada seja uma potência de base 2, i terá
    // examente o valor desse expoente
    i = maiorPot(n, 0);
 
    // Em seguida, quant receberá o valor que a função analisa, de
    // parâmetros n, i já calculado e 0 para a quantidade, retornará
    quant = analisa(n, i, 0);
 
    printf("%d\n", quant);
 
    return 0;
}
