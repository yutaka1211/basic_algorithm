#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (10)

/*配列の値を交換*/
void Swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

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

    /*選択ソート(昇順)*/
    for(int i=N-1;i>0;i--){
        int *max=&array[0]; //最初の値をmaxとする
        for(int j=1;j<=i;j++){
            if(*max<array[j]){ max=&array[j]; } //maxよりも大きければ、maxに格納
        }
        Swap(max, &array[i]);   //maxと探索位置とを交換
    }
    /*ソート後表示*/
    printf("After1: ");
    Print(array);


    /*選択ソート(降順)*/
    for(int i=N-1;i>0;i--){
        int *min=&array[0];
        for(int j=1;j<=i;j++){
            if(*min>array[j]){ min=&array[j]; }
        }
        Swap(min, &array[i]);
    }


    /*ソート後表示*/
    printf("After2: ");
    Print(array);

    return 0;
}