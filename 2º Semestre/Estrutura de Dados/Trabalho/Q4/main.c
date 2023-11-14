#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

int main(){

    vetor * ve = create(100);

    add(ve,3,50);
    add(ve,4,70);
    add(ve,1,10);
    add(ve,5,90);
    add(ve,2,30);

    imprime(ve);

    mergeSort(ve,0,(ve->n)-1);

    imprime(ve);
}


