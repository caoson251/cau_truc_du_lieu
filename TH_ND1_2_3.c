#include <stdio.h>
#include <stdlib.h>

int ex5FindMax2()
{
    int i;
    printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
    int index, imax, numArray[10];
    imax = 0;
    printf("Nhap 10 gia tri so vao mang numArray: \n");
    for (index = 0; index < 10; index++) {
        scanf("%d", &numArray[index]);
    }
    for (index = 1; index < 10; index++) {
        if (numArray[index] > numArray[imax])
            imax = index;
    }
    printf("Gia tri lon nhat la %d.\n", numArray[imax]);
}

int main(){
    ex5FindMax2();
}
