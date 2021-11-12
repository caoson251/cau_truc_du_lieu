#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ADJUST(int K[], int i, int n)
{
    int KEY = K[i];  //KEY nhận giá trị khoá ở nút gốc i 
    int j = 2 * i;   //j ghi nhận số thứ tự nút con trái của nút i
    while (j <= n)
    {
        if ( (j < n) && (K[j] < K[j+1]) ) j = j + 1;
        //Nếu khoá con phải lớn hơn thì j ghi nhận số thứ tự của nó
        if (KEY > K[j])// TH KEY lớn hơn khoá con
        {
            K[j/2] = KEY;   // thì xác định được vị trí của KEY -> dừng lại
                            // KEY sẽ ở vị trí nút cha của khóa con
            return;
        }
        // TH KEY nhỏ hơn khóa con -> Đưa khoá con lên 
        K[(int)floor(j/2)] = K[j];
        j = 2 * j ;     // Tiếp tục đi xuống nhánh này để tìm vị trí cho KEY
                        // vì KEY có thể nhỏ hơn nút ở nhánh nà
    }
    K[(int)floor(j/2)] = KEY;
}
void HeapSort(int K[], int n)
{
    int i;
    // Tạo đống
    for (i = n/2 ; i >=1; i--)
        ADJUST(K, i, n);
    // Sắp xếp
    for (i = n - 1; i >= 1; i--)
    {
        int tmp = K[1];
        K[1] = K[i+1] ;
        K[i+1] = tmp;
        ADJUST(K, 1, i);
    }
}
void print_array(int k[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        printf("%d ", k[i]);
    }
}
int main(void)
{
    int K[11]= {0,42,23,74,11,65,58,94,36,99,87};
    printf("\nMang truoc khi sap xep: ");
    print_array(K, 11);
    HeapSort(K, 10);
    printf("\nMang sau khi sap xep: ");
    print_array(K, 11);
    return 0;
}
