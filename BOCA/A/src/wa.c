#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, ma=-100001, sma, sme, me=100001, aux, comp;

    scanf("%i", &n);
    for(i=0; i<n; i++){
        scanf("%i", &aux);
        if(aux>=ma){sma=ma; ma=aux;}
        else if(aux>=sma){sma=aux;}

        if(me>=aux){sme=me; me=aux;}
        else if(aux<=sme){sme=aux;}

    }
    if(n==1) printf("\n%i\nnao definido\n%i\nnao definido", ma, me);
    else printf("\n%i\n%i\n%i\n%i", ma, sma, me, sme);
    return 0;
}