#include <stdio.h>

int fatorial(int n);

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d\n", fatorial(num));

    return 0;

}

int fatorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}