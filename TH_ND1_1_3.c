#include <stdio.h>
#include <stdlib.h>
#define MTHS 12

int main()
{
    int i;
    int days[MTHS]= {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("\nDUYET MANG: LIET KE GIA TRI CAC PHAN TU\n");
    for (i = 0 ; i < MTHS; i++ )
        printf("Thang %d co %d ngay\n", i+1, days[i]);
}
