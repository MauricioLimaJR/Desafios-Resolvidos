#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int i;
    unsigned int j;
} Pair;

int verify_numbers(unsigned int i, unsigned int j)
{
    if(i > 0 && i < 10000 && j > 0 && j > 10000)
    {
        return 1;
    }
    else 0;
}

int calculate_cycle_length(unsigned int input){
    int length=1;
    while(1){
    if(input==1)
        break;
    if(input % 2 != 0)
        input = (3*input)+1;
    else
        input /=2;
    length++;
    }
    return length;
}

int calculate_maximun_cycle_length(Pair numbers){
    int value, maximun_length=0, start = numbers.i, end = numbers.j;
    for( ; start <= end; start++){
        value = calculate_cycle_length(start);
        if(value >= maximun_length)
            maximun_length = value;
    }
    return maximun_length;
}

int main()
{
    int next=0, order=0;
    char way;
    Pair reader, numbers[10];

    printf("Write the pairs of numbers whised:\n(Type 0 0 to finish)\n");

    do
    {
        scanf("%u %u", &reader.i, &reader.j );

        if(verify_numbers(reader.i, reader.j))
        {
            numbers[next].i = reader.i;
            numbers[next].j = reader.j;
            next++;
        }
        else{
                printf("Ops, the numbers format is wrong!\n\tType 'y' to try again or 'n' to exit:\n");
                way = getch();
                if(way=='n') break;
                else if(way != 'y')puts("Type error, exiting...");
        }
    }
    while(1);
    next--;

    printf("\n\nComputing...\n\n");

    for( ; order <= next; order++){
        printf("%d  %d  %d\n", numbers[order].i, numbers[order].j, calculate_maximun_cycle_length(numbers[order]));
    }
}
