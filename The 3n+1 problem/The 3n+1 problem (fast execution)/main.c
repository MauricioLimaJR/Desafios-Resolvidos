#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int cache[MAX];
int cycle(unsigned int n){
    int length=1;
    while(1){
    if(n==1)break;
    if(n % 2 != 0)
        n = (3*n)+1;
    else
        n /=2;
    length++;
    }
    return length;
}

 int next(int n) {
    if (n % 2 == 0)
        return n / 2;
        return 3 * n + 1;
    }
int cycleLength(int n) {
        if (n == 1)
            return 1;
        if (n < MAX && cache[n] != 0)
            return cache[n];
        int length = cycle(n);
        if (n < MAX)
            cache[n] = length;
        return length;
    }



int main(){
    int i,j, x, n, from, to, max, value=0;
    for(i=0; i<MAX; i++){cache[i]=0;}
    while (scanf("%d%d", &i, &j)==2) {
        max=0;
        printf("%d %d ", i, j);
        if(i>j){
            x=i; i=j; j=x;
        }
    from = i;
    to = j;
    for (n = from; n <= to; n++) {
        value = cycleLength(n);
        if(value > max) max = value;
            }
            printf("%d\n",max);
        }
}

