#include<stdio.h>

void fact(int n)
{
    if (n==1)
        return;
    int i=2;
    while (n%i != 0)
        i++;
    fact (n/i);
    printf("%d ",i); 

}

int main ()
{
    int n;
    printf("sayi giriniz: \n");
    scanf("%d",&n);
    fact(n);
}
