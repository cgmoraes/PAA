/*Uma agência de relacionamentos está planejando um novo serviço para formação de casais entre os participantes
através de um tipo inovador de evento. Neste evento, cada participante teria a chance de conhecer os outros
participantes do evento. Devido a questões de ideologia de gênero, a agência decidiu não fazer a divisão dos
participantes entre participantes do sexo masculino ou feminino e permitirá que todos se conheçam no evento
livremente.
Após a etapa inicial em que os participantes conhecem outros participantes, cada um deve indicar secretamente
em um papel um nome de outro participante que mais lhe despertou interesse no evento.
Para uma segunda etapa do evento, a agência pretende formar um subgrupo com alguns dos participantes iniciais
de forma que todos neste subgrupo tenham sido indicados por outro participante também neste subgrupo, ou seja,
cada convidado neste subgrupo foi indicado por outra pessoa neste mesmo subgrupo. A escolha dos participantes
neste subgrupo de participantes a serem convidados para a segunda etapa do evento deve ser feita de forma que o
número de participantes nesta segunda etapa seja o maior possível para que o evento consiga formar o maior
número possível de casais ao término do evento. A agência acredita que as pessoas que restarem para a segunda
etapa são as únicas que ainda têm chance de encontrar um parceiro/parceira no evento. A sua tarefa é determinar
os participantes a serem convidados para a segunda etapa de certos eventos conforme as regras propostas pela
agência.
Entrada
A entrada se inicia com uma linha contendo o número inteiro N (2 ≤ N ≤ 100.000) de participantes de um
evento. Cada participante é identificado por um número entre 1 e N. Em cada uma das próximas N linhas, serão
apresentados dois identificadores a e b para representar que a pessoa b foi indicada por outra pessoa a.
Saída
Imprima uma linha com os identificadores das pessoas a serem convidadas para a segunda etapa do
evento em ordem crescente. Imprima um espaço em branco entre 2 participantes.*/

#include <stdio.h>
#include <stdlib.h>
 
// Estrutura para o convidado onde contém o seu indice, grau e um ponteiro para
// quem o mesmo está interessado
typedef struct participante {
    int indice;
    struct participante *inter;
    int grau;
} Particip;
 
// Função para iniciar o atributo "grau" da struct com 0
void zeraGrau(Particip *convi, int quant)
{
    int i;
 
    for (i = 0; i < quant + 1; i++)
        convi[i].grau = 0;
}
 
void removeConvi(Particip *convi, int indice, int quant)
{
    // Caso o grau seja igual a 1 o convidado deve ser removido pois não há
    // interessados nele
    if (convi[indice].grau == 1) {
 
        // Como o convidado será removido, quem ele se interessa terá
        // que ter o grau decrementado
        convi[indice].inter->grau--;
 
        // Parâmetro para indicar que o convidado foi removido
        convi[indice].grau--;
 
        // Como a pessoa do qual o convidado removido tinha
        // interesse teve seu grau decrementado, precisamos analisar
        // novamente o grau agora em relação à pessoa interessada e isso
        // vai se dar de forma resursiva até que não há mais pessoas com
        // grau 1
        removeConvi(convi, convi[indice].inter->indice, quant);
    }
}
 
void analisaGrau(Particip *convi, int indice, int quant)
{
    // Passa o convidado para uma função que analisará se ele deve ser
    // removido
    if (convi[indice].grau == 1)
      removeConvi(convi, indice, quant);
 
    // Parâmetro para recursividade
    if (indice < quant)
 
      // Chama a função de forma recursiva analisando o próximo convidado
      analisaGrau(convi, indice + 1, quant);
}
 
void imprime(Particip *convi, int indice, int quant)
{
    if (convi[indice].grau > 1)
        printf("%d ", convi[indice].indice);
 
    // Parâmetro para recursividade
    if (indice < quant)
 
      // Chama a função de forma recursiva analisando o próximo convidado
      imprime(convi, indice + 1, quant);
}
 
int main()
{
    // Quantidade de participantes
    int quant;
    scanf("%d", &quant);
 
    // Declara a struct com tamanho da quantidade mais um com o intuito de
    // usar a posição relativa do vetor como número do convidado
    Particip *convi = (Particip *)malloc(sizeof(Particip) * (quant + 1));
 
    // Zera o grau de todos os membros do vetor struct
    zeraGrau(convi, quant);
 
    // i será o índice do for, indice é o numero do convidado e o inter é o
    // número de quem o convidado está interessado
    int i, indice, inter;
    
    for (i = 0; i < quant; i++) {
        scanf("%d %d", &indice, &inter);
 
        convi[indice].indice = indice;
 
        // Atribui o endereço de memória relativo a posição do qual se
        // têm interesse ao ponteiro do convidado no qual está
        // interessado
        convi[indice].inter = &convi[inter];
 
        // Incrementa o valor do grau para o convidado e para quem ele
        // está interessado
        convi[indice].grau++;
        convi[inter].grau++;
    }
 
    // Faz a análise do grau de cada convidado
    analisaGrau(convi, 1, quant);
 
    // Imprime os convocados
    imprime(convi, 1, quant);
    free(convi);
 
    return 0;
}
