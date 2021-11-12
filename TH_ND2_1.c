#include <stdio.h>
void print1DimArr(int arr[], int n) {
    for(int i=0; i < n;i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int print2DimArrA(int arr[][3], int m){
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", arr[i][j]);
        }
    printf("\n");
    }
}
int print2DimArrB(int arr[][3], int m){
    int i, j;
    for (i = 0; i < m; i++) {
        print1DimArr( arr[i], 3);
        printf("\n");
    }
}
int main(){
    int exam1[3][3] = {{1, 2}, {4}, {5, 7}};
    printf("print1DimArr\n");
    print1DimArr(exam1[1], 3);

    printf("print2DimArrA\n");
    print2DimArrA(exam1,3);
    printf("print2DimArrB\n");
    print2DimArrB(exam1, 3);
    return 0;
}
