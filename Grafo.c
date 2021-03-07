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
