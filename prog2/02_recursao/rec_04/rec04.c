#include <stdio.h>

int Palindromo(char *string, int tamanho); 

int Conta_Tamanho(char* str);

int main()
{
    char str[100]; int tam, p;

    while(scanf("%s", str) == 1)
    {
        tam = Conta_Tamanho(str);
        if(Palindromo(str, tam - 1) > 0)
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
        }
    }

    return 0;

}

int Palindromo(char *string, int tamanho)
{
    if(tamanho < 0)
    {
        return 1;
    }

    if(string[0] != string[tamanho])
    {
        return 0;
    }
    else
    {
        return Palindromo(string+1, tamanho-2);
    }

    return 1;

}

int Conta_Tamanho(char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}