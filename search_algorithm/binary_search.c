#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (16)              //探索数

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

/*分割部分(昇順)*/
int Partition1(int *array, int left, int right){
    int i=left;
    int j=right+1;
    int pivot=left;

    do{
        do{ i++; }while(array[pivot]>array[i]); //基準の値以下なら続行
        do{ j--; }while(array[pivot]<array[j]); //基準の値以上なら続行
        if(i<j) Swap(&array[i], &array[j]);     //i、jともに進まなくなれば交換
    }while(i<j);    //i、jがぶつかるまで実行

    Swap(&array[j], &array[pivot]); //ぶつかったところと基準を交換し、範囲内で昇順にする

    return j;   //境目の添字を返す
}

/*ソート実行部分(昇順)*/
void Sort1(int *array, int left, int right){
    int pivot;

    if(left<right){
        pivot=Partition1(array, left, right);   //基準点の境目を見つける
        Sort1(array, left, pivot-1);    //境目より左側をソート
        Sort1(array, pivot+1, right);   //境目より右側をソート
    }
}

/*二分探索部分*/
int Bs(int *array, int x){
    int left, right, mid;
    left=0;
    right=N-1;

    while(left<=right){
        mid=(left+right)/2;
        if(array[mid]==x){ return mid; }
        else if(array[mid]<x){ left=mid+1; }
        else { right=mid-1; }
    }
    return -1;
}

int main(){
    int array[N];
    int x, answer;

    srand((unsigned)time(NULL));

    /*Nの数乱数をarrayに代入*/
    array[0]=1;
    for(int i=1;i<N;i++){
        array[i]=2+rand()%99;   //2~100の乱数作成
    }

    Print(array);               //数字の表示

    printf("Input the looking number: ");
    scanf("%d", &x);

    /*クイックソート(昇順)*/
    Sort1(array, 0, N-1);

    /*二分探索*/
    answer=Bs(array, x);

    if(answer!=-1)  { printf("found\n"); }
    else            { printf("Not exist.\n"); }

    return 0;
}

