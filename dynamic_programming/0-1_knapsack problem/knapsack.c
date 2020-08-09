#include <stdio.h>
#define capacity (15)                       //袋の大きさ
#define item (4)                            //アイテムの数

int main(void){
    int size[item+1]={0, 2, 6, 6, 2};             //アイテムの大きさ
    int value[item+1]={0, 20, 30, 15, 25};        //アイテムの価値
    int table[item+1][capacity+1];                //表を作成
    int i, j, max, index;

    /*表を初期化*/
    for(i=0;i<=item;i++){
        for(j=0;j<=capacity;j++){
            table[i][j]=-1;
        }
    }
    table[0][0]=0;                          //品物が入っていない袋の価値は0

    /*表の作成*/
    for(i=1;i<=item;i++){
        for(j=0;j<=capacity;j++){
            if(table[i-1][j]!=-1){          //前のターンに何かアイテムを入れている場合
                if(table[i-1][j]>table[i][j]){ table[i][j]=table[i-1][j]; }             //i番目のアイテムを入れない場合
                if(j+size[i]<=capacity){ table[i][j+size[i]]=table[i-1][j]+value[i]; }  //i番目のアイテムを入れる場合
            }
        }
    }

    max=0;
    index=0;
    /*最大価値とその価値が入る添字を捜索*/
    for(j=0;j<=capacity;j++){
        if(table[item][j]>max){
                max=table[item][j];         //最大価値の更新
                index=j;                    //最大価値が格納されている添字を更新
        }
    }

    /*表示*/
    for(i=1;i<=item;i++){
        printf("アイテム%dの大きさは%d、価値は%d\n", i, size[i], value[i]);
    }
    printf("\n袋の大きさは%d\n\n", capacity);
    for(i=item;i>=1;i--){
        if(index>=size[i] && table[i][index]==value[i]+table[i-1][index-size[i]]){
            printf("アイテム%dは袋に入れとき\n", i);
            index-=size[i];
        }
    }
    return 0;
}