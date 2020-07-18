#include <stdio.h>

void Big(int array[], int n, int k){
    int i, j, x;
    int sum=0;
    int index=0;
    int max;
    int b[100]={0};
    int Use[100]={0};

    for(i=0;sum<n;){                                //n回繰り返す
        if(!Use[i]){                                //iが探索済でない場合
            max=array[i];                           //iを最大値として設定
            x=i;                                    //最大値の添字をxに格納
            for(j=0;j<n;j++){                       //探索済でない配列から最大値を見つける
                if(max<array[j] && !Use[j]){
                    max=array[j];
                    x=j;
                }
            }
            b[index++]=x;                           //最大値を配列bに格納
            Use[x]=1;                               //最大値を探索済にする
            sum++;
        }else{ i++; }
    }
    for(i=0;i<k;i++){
        printf("%d %d\n", array[b[i]], b[i]);
    }
}

int main(void){
    int array[8]={3,9,0,5,6,2,1,4};

    Big(array, 8, 3);

    return 0;
}