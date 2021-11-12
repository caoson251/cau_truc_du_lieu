#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int ex4Search()
{
    int i;
    printf("\nDUYET MANG: TIM KIEM GIA TRI\n");
    char myChar[SIZE] = {'b', 'a', 'c', 'k', 's'};
    char searchChar;
    printf("Nhap vao ki tu can tim kiem: ");
    scanf("%c", &searchChar);
    for (i = 0; i < SIZE; i++) {
        if (myChar[i] == searchChar){
            printf ("Tim thay ki tu %c tai vi tri %d\n", myChar[i], i);
             break;
        }
    }
}

int main(){
    ex4Search();
}
