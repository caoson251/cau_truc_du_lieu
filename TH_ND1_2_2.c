#include <stdio.h>
#include <stdlib.h>

int ex5FindMax1()
{
    int i;
    printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
    int index, max, numArray[10];
    max = -1;
    printf("Nhap 10 gia tri so vao mang numArray: \n");
    for (index = 0; index < 10; index++)
    {
        scanf("%d", numArray+index);
    }
    for (index = 0; index < 10; index++)
    {
        if (numArray[index] > max)
            max = numArray[index];
    }
    printf("Gia tri lon nhat la %d.\n", max);
}

int main()
{
    ex5FindMax1();
}
