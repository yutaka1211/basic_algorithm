#include <stdio.h>
#define N (100)

int Dp(int n, int memo[]){
    if(n<=3){ return memo[n]; }                                 //3点以下を取るパターン
    if(memo[n]!=0){ return memo[n]; }                           //既に計算してある場合
    return memo[n]=Dp(n-1, memo)+Dp(n-2, memo)+Dp(n-3, memo);   //未計算である場合
}

int main(void){
    int score;
    int memo[N]={0};
    memo[0]=0;
    memo[1]=1;                                                  //1点を取れるパターン
    memo[2]=2;                                                  //2点を取れるパターン
    memo[3]=4;                                                  //3点を取れるパターン

    printf("バスケの得点に対して、何パターンのゴールが存在するかを返します\n");
    printf("何点の時を調べますか？\n");

    scanf("%d", &score);

    printf("%dパターン存在します\n", Dp(score, memo));

    return 0;
}