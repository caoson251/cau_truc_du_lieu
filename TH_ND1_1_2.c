#include <stdio.h>
#include <stdlib.h>
#define MTHS 12

int main(void)
{
    int days[MTHS]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int days2[MTHS]= {31,28,31,30,31,30,31};
    int days3[]= {31,28,31,30,31,30,31};
    printf("So luong phan tu cua days:%d\n",sizeof(days)/sizeof(days[0]));
    printf("So luong phan tu cua days2:%d \n",sizeof(days2)/sizeof(days2[0]));
    printf("So luong phan tu cua days3:%d \n",sizeof(days3)/sizeof(days3[0]));
    printf("Gia tri cua phan tu days2[7]: %d\n",days2[7]);
    printf("Gia tri cua phan tu days3[7]: %d\n",days3[7]);
    return 0;
}
