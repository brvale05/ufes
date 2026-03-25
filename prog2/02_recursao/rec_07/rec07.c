#include <stdio.h>

int somaDigitos(int n);

int main()
{
    int num;
    scanf("%d", &num);
    
    printf("%d\n", somaDigitos(num));

    return 0;

}

int somaDigitos(int n)
{
    if(n < 10)
    {
        return n;
    }
    return n%10 + somaDigitos(n/10);
}