#include <stdio.h>
#include <stdlib.h>
int k0[11] = {0,42,23,74,11,65,58,94,36,99,87};
int k[10] = {42,23,74,11,65,58,94,36,99,87};
//k[1] -> k[n] giảm dần
void selection_sort2(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, m, x;
    for (i = 1; i < n + 1; i++) // i duyệt n - 1 lần, mỗi 1 lầni đưa ra 1 phần tử vào đúng vị trí của nó
    {
        m = i;
        for (j = i + 1; j < n + 1; j++) // j tìm phần tử lớn nhất từ vị trí i cho đến vị trí n
            if (k[j] > k[m]) m = j;
        if (m != i) // Nếu phần tử lớn nhất khác i thì đổi chỗ để đặt đúng vị trí
        {
            x = k[i];
            k[i] = k[m];
            k[m] = x;
        }
    }
}
void insert_sort2(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, x;
    for (i = 2; i <= n; i++) // chèn phần tử k[i] vào dãy thành i phần tử được sắp xếp
    {
        x = k[i] ;
        j = i - 1;

        while (x > k[j] && j >= 1) // Đặt vị trí ptu i vào trong dãy có i ptu để cho dãy được sắp xếp
        {
            k[j+1] = k[j];
            j = j - 1;
        }
        k[j + 1 ] = x;
    }
}
void bubble_sort2(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, x;
    for (i = 1; i < n; i++) // duyệt i từ 1 đến n, ở lượt thứ i thì phần tử lớn thứ i được lên vị trí i
        for (j = n-1; j > i; j--) // duyệt j = n cho đến j > i, duyệt từ dưới lên
            if (k[j] > k[j - 1]) // nếu 2 phần tử liền nhau không đúng vị trí thì đổi cho nhau
            {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
}
//k[0] -> k[n-1] giảm dần
void selection_sort3(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, m, x;
    for (i = 0; i < n - 1; i++) // i duyệt n - 1 lần, mỗi 1 lần i đưa ra 1 phần tử vào đúng vị trí của nó
    {
        m = i;
        for (j = i + 1; j < n; j++) // j tìm phần tử lớn nhất từ vị trí i cho đến vị trí n
            if (k[j] > k[m]) m = j;
        if (m != i) // Nếu phần tử lớn nhất khác i thì đổi chỗ để đặt đúng vị trí
        {
            x = k[i];
            k[i] = k[m];
            k[m] = x;
        }
    }
}
void insert_sort3(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, x;
    for (i = 1; i < n; i++) // chèn phần tử k[i] vào dãy thành i phần tử được sắp xếp
    {
        x = k[i];
        j = i - 1; //
        while (x > k[j] && j >= 0) // Đặt vị trí ptu i vào trong dãy có i ptu để cho dãy được sắp xếp
        {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = x;
    }
}
void bubble_sort3(int k[], int n) // Đầu vào mảng k với n số phần tử
{
    int i, j, x;
    for (i = 1; i < n; i++) // duyệt i từ 1 đến n, ở lượt thứ i thì ptu nhỏ thứ i được lên vị trí i
        for (j = n-1; j >= i; j--) // duyệt j = n cho đến j >= i, duyệt từ dưới lên
            if (k[j] > k[j - 1]) // nếu 2 phần tử liền nhau không đúng vị trí thì đổi cho nhau
            {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
}
void print_array0(int k[], int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%d ", k[i]);

    }
}
void print_array1(int k[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", k[i]);

    }
}
int main(void)
{
    printf("k1 -> kn giam dan\n");
    printf("\nMang truoc khi sap xep: ");
    print_array0(k0,10);
    //selection_sort2(k0,10);
    insert_sort2(k0,10);
    //bubble_sort2(k0,n1);
    printf("\nMang sau khi sap xep: ");
    print_array0(k0,10);

    //printf("k0 -> kn-1 giam dan\n");
    //printf("\nMang truoc khi sap xep: ");
    //print_array(k,n2);
    //selection_sort3(k,n2);
    //insert_sort3(k,n2);
    //bubble_sort3(k,n2);
    //printf("\nMang sau khi sap xep: ");
    //print_array(k,n2);
    return 0;
}
