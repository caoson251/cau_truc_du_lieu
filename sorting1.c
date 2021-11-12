#include <stdio.h>
#include <stdlib.h>
int k[10] = {42,23,74,11,65,58,94,36,99,87};
// Bài 5
void selection_sort4(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, m, x;
    for (i = n - 1; i >= 0; i--) // i duyệt n - 1 lần, mỗi 1 lần i đưa ra 1 phần tử vào đúng vị trí của nó
    {
        m = i;
        for (j = i - 1; j >= 0; j--) // j tìm phần tử nhỏ nhất từ vị trí i cho đến vị trí n
            if (k[j] > k[m]) m = j;
        if (m != i) // Nếu phần tử nhỏ nhất khác i thì đổi chỗ để đặt đúng vị trí
        {
            x = k[i];
            k[i] = k[m];
            k[m] = x;
        }
    }
}
void insert_sort4(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, x;
    for (i = n - 2 ; i >= 0; i--) // chèn phần tử k[i] vào dãy thành i phần tử được sắp xếp
    {
        x = k[i];
        j = i + 1; //
        while (x > k[j] && j >= 1) // Đặt vị trí ptu i vào trong dãy có i ptu để cho dãy được sắp xếp
        {
            k[j - 1] = k[j];
            j = j + 1;
        }
        k[j - 1] = x;
    }
}
void bubble_sort4(int k[], int n)
{
    int i, j, x;
    for (i = 0; i < n-1 ; i++)
        for (j = 0 ; j < n - i; j++)
            if (k[j] < k[j - 1]) // nếu 2 phần tử liền nhau không đúng vị trí thì đổi cho nhau
            {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
}
void print_array(int k[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", k[i]);

    }
}
int main(void)
{
    printf("k0 -> kn-1 tang dan\n");
    printf("\nMang truoc khi sap xep: ");
    print_array(k,10);
    selection_sort4(k,10);
    //insert_sort4(k,10);
    //bubble_sort4(k,n2);
    printf("\nMang sau khi sap xep: ");
    print_array(k,10);
    return 0;
}
