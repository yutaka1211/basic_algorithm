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

/*ソート(昇順)*/
void Sort(int *array){
    int i, j, h;

    for(h=4;h>0;h/=2){      //探索間隔(gap sequence)を4にする
        for(i=h;i<N;i++){
            j=i;
            while((j-h>-1)&&(array[j]<array[j-h])){ //hだけ離れている値を比較//降順なら while((j-h>-1)&&(array[j]<array[j-h])){
                Swap(&array[j], &array[j-h]);
                j-=h;
            }
        }
    }
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


    /*シェルソート(昇順)*/
    Sort(array);

    /*ソート後表示*/
    printf("After: ");
    Print(array);


    return 0;
}
//不安定な内部ソート
//最悪計算時間O(n^2)
//挿入ソートの応用