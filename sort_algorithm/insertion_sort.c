#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (10)  //探索数

/*配列を表示*/
void Print(int *array){
    for(int i=0;i<N;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[N];

    srand((unsigned)time(NULL));

    /*Nの数乱数をarrayに代入*/
    array[0]=1;
    for(int i=1;i<N;i++){
        array[i]=2+rand()%99;   //2~100の乱数作成
    }

    /*ソート前表示*/
    printf("Before: ");
    Print(array);

    /*挿入ソート(昇順)*/
    for(int i=1;i<N;i++){
        int x, j;
        x=array[i];
        j=i;
        while((array[j-1]>x)&&(j>0)){   //降順ならwhile((array[j-1]<x)&&(j>0)){
            array[j]=array[j-1];
            j--;
        }
        array[j]=x;
    }

    /*ソート後表示*/
    printf("After: ");
    Print(array);

    return 0;

}
//安定な内部ソート
//最悪計算量O(n^2)
//ほぼ整列してあるとO(n)で動作