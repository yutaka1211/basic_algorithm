#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (10)

/*配列を表示*/
void Print(int *array){
    for(int i=0;i<N;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*ソート(昇順)*/
void Merge(int *array, int left, int right){
    int i, j, k, mid;
    int work[N];         //外部配列
    if(left<right){
        mid=(left+right)/2;  //中央の計算計算
        Merge(array, left, mid);    //中央より左側をソート
        Merge(array, mid+1, right); //中央より右側をソート
        for(i=mid;i>=left;i--){ work[i]=array[i]; } //ソート左側をwork左側へ
        for(j=mid+1;j<=right;j++){
            work[right-(j-(mid+1))]=array[j];   //ソート右側をwork右側へ
        }
        i=left;
        j=right;
        for(k=left;k<=right;k++){   //workの両端を比較
            if(work[i]<work[j]){ array[k]=work[i++]; }  //降順ならif(work[i]>work[j]){ array[k]=work[i++]; }
            else { array[k]=work[j--]; }
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

    /*挿入ソート(昇順)*/
    Merge(array, 0, N-1);

    /*ソート後表示*/
    printf("After: ");
    Print(array);

    return 0;

}
//安定な外部ソート
//平均計算量O(nlogn)
//最悪計算量でもO(nlogn)