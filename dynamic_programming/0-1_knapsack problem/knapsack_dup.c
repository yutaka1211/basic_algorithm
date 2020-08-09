#include <stdio.h>
#include <stdlib.h>
#define Capacity (5)                        //袋の大きさ
#define Item (4)                            //アイテムの数

int value[Item+1]={0, 3, 5, 3, 8};
int weight[Item+1]={0, 2, 2, 1, 3};
int dp[Item+1][Capacity+1]={0};
int dp_dup[Item+1][Capacity+1]={0};

int Max2(int x, int y){
    return x>y?x:y;
}

int Max3(int x, int y, int z){
    int max=x;
    if(max<y){ max=y; }
    if(max<z){ max=z; }

    return max;
}

void Dp(){
    for(int i=1;i<=Item;i++){
        for(int j=0;j<=Capacity;j++){
            if((j-weight[i])>=0){
                dp[i][j]=Max2(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}

void Dp_dup(){
    for(int i=1;i<=Item;i++){
        for(int j=0;j<=Capacity;j++){
            if((j-weight[i])>=0){
                dp_dup[i][j]=Max3(dp_dup[i-1][j], dp_dup[i-1][j-weight[i]]+value[i], dp_dup[i][j-weight[i]]+value[i]);
            }else{
                dp_dup[i][j]=dp_dup[i-1][j];
            }
        }
    }
}

int main(void){

    for(int i=1;i<=Item;i++){
        printf("アイテム%dの重さは%d、価値は%d\n", i, weight[i], value[i]);
    }
    printf("\n袋の大きさは%dである\n", Capacity);


    printf("\n重複なしの場合\n");

    Dp();

    printf("   ");
    for(int i=0;i<=Capacity;i++){
        printf("%2d ", i);
    }printf("\n");
    for(int i=0;i<=Item;i++){
        printf("%2d ", i);
        for(int j=0;j<=Capacity;j++){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }


    printf("\n重複ありの場合\n");

    Dp_dup();

    printf("   ");
    for(int i=0;i<=Capacity;i++){
        printf("%2d ", i);
    }printf("\n");
    for(int i=0;i<=Item;i++){
        printf("%2d ", i);
        for(int j=0;j<=Capacity;j++){
            printf("%2d ", dp_dup[i][j]);
        }
        printf("\n");
    }

    return 0;
}



