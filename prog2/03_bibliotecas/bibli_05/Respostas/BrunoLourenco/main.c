#include <stdio.h>
#include "string_utils.h"

void Imprime_Operacoes();

void Executa_Operacao(int op, char *str);

int main()
{
    char str[1000];

    scanf("%[^\n]", str);

    int operacao;

    while (1)
    {
        scanf("%d", &operacao);
        Imprime_Operacoes();
        if(operacao == 6) break;
        Executa_Operacao(operacao, str);
    }

    return 0;
}

void Imprime_Operacoes()
{
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

void Executa_Operacao(int op, char *str)
{
    if (op == 1)
    {
        printf("Tamanho da string: %d\n", string_length(str) + 1);
    }
    if (op == 2)
    {
        char dest[string_length(str)];
        string_copy(str, dest);
        printf("String copiada: %s\n", dest);
    }
    if (op == 3)
    {
        string_upper(str);
        printf("String convertida para maiusculas: %s\n", str);
    }
    if (op == 4)
    {
        string_lower(str);
        printf("String convertida para minusculas: %s\n", str);
    }
    if (op == 5)
    {
        string_reverse(str);
        printf("String invertida: %s\n", str);
    }
}