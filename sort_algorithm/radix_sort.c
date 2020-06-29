#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (10)
#define M (99)  //乱数の最大値

int rad[N];     //基数をしまう配列
int work[N];    //作業用配列

/*配列を表示*/
void Print(int *array){
    for(int i=0;i<N;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*ソート(昇順)*/
void Sort(int *array, int size, int max){
    int i, j, k;
    int m=1;    //桁

    while(m<=max){  //桁が最大値以下の場合
        for(i=0;i<size;i++){ rad[i]=(array[i]/m)%10; }  //それぞれの桁の値を格納(m=1の時:123->3、m=10の時:123->2)
        k=0;
        for(i=0;i<size;i++){    //桁数を1から順に探していく //降順ならfor(i=size-1;i>=0;i--){
            for(j=0;j<size;j++){    //配列を探索
                if(rad[j]==i){ work[k++]=array[j]; }   //合致すれば、配列を作業に格納
            }
        }
        for(i=0;i<size;i++){ array[i]=work[i]; }    //作業用を配列に格納し直す
        m*=10;  //桁をあげる
    }
}

int main(){
    int array[N];

    srand((unsigned)time(NULL));

    /*Nの数乱数をarrayに代入*/
    array[0]=1;
    for(int i=1;i<N;i++){
        array[i]=1+rand()%M;   //1~99の乱数作成
    }

    /*ソート前表示*/
    printf("Before: ");
    Print(array);

    /*基数ソート(昇順)*/
    Sort(array, N, M);

    /*ソート後表示*/
    printf("After:  ");
    Print(array);

    return 0;
}
//安定な外部ソート
//最悪計算量O(kn) ここでkは桁数である
//最大値を知っておく必要がある