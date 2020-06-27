#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (11)  //ソートが添字1から始まるので探索個数+1

/*配列の値を交換*/
void Swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

/*配列を表示*/
void Print(int *array){
    for(int i=1;i<N;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*array[first]を適切な位置へ置く*/
void Push(int *array, int first, int last){
    int parent=first; //親指定
    int child=2*parent; //子指定
    while(child<=last){
        if((child<last)&&(array[child]<array[child+1])){ child++; } //右の子の方が大きい場合、右を子にする
        if(array[child]<=array[parent]){ break; };  //親の値が子以上であれば終了
        Swap(&array[child], &array[parent]);        //親と子を入れ替える
        parent=child;       //親指定
        child=2*parent;     //子指定
    }
}

/*ソート(昇順)*/
void Sort(int *array, int size){
    int i;

    for(i=size/2;i>0;i--){ Push(array, i, size); }  //全体をソート
    for(i=size;i>1;i--){
        Swap(&array[1], &array[i]);     //最大値を配列の後ろへ
        Push(array, 1, i-1);            //残りの配列についてソート
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

    /*クイックソート(昇順)*/
    Sort(array, N-1);

    /*ソート後表示*/
    printf("After: ");
    Print(array);

    return 0;
}
//不安定な内部ソート
//平均計算量O(nlogn)
//考え方が大事