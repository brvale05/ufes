#include "base_alunos.h"
#include "aluno.h";
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos
{
    tAluno **alunos;
    int tamanho;
    int capacidade;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos *vetor = malloc(sizeof(tBaseAlunos));

    vetor->alunos = malloc(sizeof(tAluno*)*10);

    vetor->tamanho = 0;
    vetor->capacidade = 10;

    return vetor;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    if(baseAlunos)
    {
        if(baseAlunos->alunos)
        {
            for(int i = 0; i < baseAlunos->tamanho; i++)
            {
                DestruirAluno(baseAlunos->alunos[i]);
            }
        }
        free(baseAlunos->alunos);
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    int tamanho;

    FILE *fp = fopen(nomeArquivo, "rb");

    //lendo qtd de alunos
    fread(&tamanho, sizeof(int), 1, fp);

    for(int i = 0; i < tamanho; i++)
    {
        baseAlunos->alunos[i] = LeAluno(fp);
    }

    baseAlunos->tamanho = tamanho;

    fclose(fp);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    float soma = 0;

    for(int i = 0; i < baseAlunos->tamanho; i++)
    {
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    return soma/(float)baseAlunos->tamanho;
}
