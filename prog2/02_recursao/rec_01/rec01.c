#include <stdio.h>

void ImprimeInvertido(char* string); 

int main()
{
    char str[1000];

    while(scanf("%s", str) == 1)
    {
        ImprimeInvertido(str);
        printf(" ");
    }

    return 0;

}

void ImprimeInvertido(char* string)
{
    if(string[1] == '\0')
    {
        printf("%c", string[0]);
        return;
    }
    else
    {
        ImprimeInvertido(string+1);
        printf("%c", string[0]);
    }
}