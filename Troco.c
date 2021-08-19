/*Atualmente existe uma grande variedade de moedas digitais para se realizar simples transações on-line ou até
mesmo para guardar reserva de valor. Entre esses diferentes tipos de moedas, existem desde criptomoedas
descentralizadas até mesmo moedas digitais que são controladas por bancos centrais de certos países. Para muitas
dessas moedas, existe um grande custo computacional para se processar as transações realizadas pelos usuários da
moeda devido à dificuldade computacional de se realizar as devidas verificações para que essas transações sejam
processadas corretamente.
Uma nova moeda digital que veio para competir com as moedas digitais existentes, a Power2coin
(PW2C), criada por uma comunidade de cientistas da computação que propõem uma mudança de paradigma para
se reduzir a quantidade de energia gasta nas transações e para se distribuir o seu custo utilizando a capacidade
ociosa de processamento de equipamentos dos próprios participantes nas transações dessas moedas digitais
existentes, mas que pode possivelmente implicar em transferências de maior volume de dados por transação.
Como o protocolo usado em Power2coin torna o processamento de transações mais simples e rápido, o gasto
energético para a manutenção da rede pode ser reduzido de forma que simples equipamentos como smartphones
dos próprios usuários que realizam a transação podem ser utilizados para fazer o processamento das suas próprias
transações sem a necessidade de nós adicionais na rede processando as transações de terceiros.
Como em outras moedas digitais, as moedas de Power2coin podem ser guardadas em carteiras digitais em
que o valor total é a soma de todas as moedas guardadas. Para se realizar uma transferência de valor na rede de
uma carteira A (origem) para uma carteira B (destino), são criadas novas moedas a partir da carteira A em valores
que são sempre potência de 2 e em valores distintos, sendo que o volume de dados transferidos é proporcional à
quantidade de moedas transacionadas. Por exemplo, para se realizar um pagamento no valor de 30 PW2C de uma
carteira A para outra carteira B, é possível criar 4 moedas de valores 2, 4, 8 e 16 PW2C cada em A e enviá-las
para B. Outra forma seria, por exemplo, a partir da carteira A, criar-se uma moeda de valor 32 PW2C e enviá-la
para B, além de criar-se uma moeda de 2 PW2C a partir da carteira B e enviá-la para A de forma que, no balanço
após a transação, A terá pago 30 PW2C para B.
Como o custo para se realizar as transações pelo protocolo utilizado pela Power2coin é relativo à
quantidade de moedas transacionadas entre as partes, então o objetivo é, dado o valor em PW2C a ser pago,
encontrar a menor quantidade de moedas que devem ser transferidas em ambas as direções entre os usuários em
uma dada transação. No exemplo dado anteriormente deve-se escolher a segunda opção em que são transferidas 2
ao invés de 4 moedas da primeira opção, de forma a se minimizar o volume de dados transferidos na rede. Para
que a Power2coin possa ser efetivamente utilizada na prática, é necessário primeiro que um novo aplicativo seja
desenvolvido para se determinar no início de uma transação qual é a quantidade mínima de moedas a serem
criadas e transferidas na rede dado o valor a ser pago a partir de uma dada carteira. Então, a sua tarefa é a de
projetar um algoritmo eficiente e implementar um programa para resolver esse problema. Devido às restrições de
capacidade de processamento e a necessidade de se ter transações concluídas rapidamente, é necessário que essa
resposta seja fornecida em curto espaço de tempo. Você pode assumir que o valor a ser enviado já existe na
carteira de origem e que os valores de moedas específicas armazenadas nessa carteira que correspondem ao saldo
antes da transação não precisam ser verificados, pois havendo saldo suficiente na carteira o software da carteira
digital é capaz de criar novas moedas e fazer os ajustes necessários. Considerando que a carteira B de destino
sempre recebe um valor maior do que envia, pois só é possível pagar valores que são inteiros positivos na rede, a
carteira B pode, se necessário para que a transação de fato ocorra, criar temporariamente, enquanto a transação
estiver ocorrendo, moedas para o “troco” em valor, inclusive maior do que o existe em seu saldo pré-transação.
Além das moedas criadas a partir de outras pré-existentes em mesmo valor para se realizar as transferências, é
necessário que essas moedas pré-existentes tenham sido criadas em algum momento no passado para existirem na
rede. Portanto, o sistema considera também como política de expansão monetária uma atribuição de pontos para
ambos os usuários de cada transação, o que os seus criadores chamaram de “cash back mútuo”, ou seja, novas
unidades de PW2C são adicionadas às carteiras digitais após uma certa quantidade de pontos ser atingida como
uma forma de incentivar o maior uso da Power2coin, assim como aumentar e manter em elevado nível a
velocidade da moeda enquanto a oferta de moeda é aumentada.

Entrada
A entrada contém uma única linha que apresenta o valor N (1 ≤ N ≤ 10.000) do valor a ser pago na
transação em PW2C.
Saída
Imprima uma linha com a quantidade mínima de moedas a serem transacionadas para se realizar o
pagamento no valor de N.*/

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
