#include <stdio.h>
void print1DimArr(int* ar, int n)
{
    int i;
    for(int i=0; i < n; i++)
    {
        printf("%d\t", *(ar+i));
    }
    printf("\n");
}
int print2DimA(int* ar, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t",*(ar + i*m + j));
        }
        printf("\n");
    }
}
int print2DimB(int* ar, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        print1DimArr(ar + i*m, n);
    }

}
int main()
{
    int exam1[3][3] = {{1, 2}, {4}, {5, 7}};
    printf("print1DimArr\n");
    print1DimArr(exam1[1], 3);
    printf("print2DimArrA\n");
    print2DimA(exam1,3, 3);
    printf("print2DimArrB\n");
    print2DimB(exam1, 3, 3);
    return 0;
}
