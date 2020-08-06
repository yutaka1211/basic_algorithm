#include <stdio.h>
#include <string.h>
#define INF (10000)

int dp[100][100];
int a[4]={1,2,4,7};                                     //コインの額面

/*3つの引数から最小値を返す*/
int min(int num1, int num2, int num3){
    int result;
    result=num1;
    if(result>num2){ result=num2; }
    if(result>num3){ result=num3; }

    return result;
}

void CalcT(int n, int m){
    /*初期化*/
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i==0){ dp[i][j]=j;}
            else{ dp[i][j]=INF; }
        }
    }
    dp[0][0]=0;                                         //0個の整数の和は0であり、0個

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i+1][j]=min(dp[i+1][j], dp[i][j], INF);       //整数a[i]を選ばずに、値を更新
            if(j>=a[i]){ dp[i+1][j]=min(dp[i+1][j], dp[i][j-a[i]]+1, dp[i+1][j-a[i]]+1); }             //dp[i][j]が値を持っている場合、a[i]を加えて最小枚数を1増加させる
        }
    }
}

int main(){
    int n=2;                                                //コインの使える枚数
    int m=3;                                                //支払う額面
    int N=4;                                                //表の縦の大きさ
    int M=7;                                                //表の横の大きさ

    CalcT(N, M);

    /*表の表示*/
    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    /*値の表示*/
    if(dp[n+1][m]<INF){ printf("\nC0からC%dまでのコインを使って%d円支払う場合のコインの最小枚数は%d\n", n, m, dp[n+1][m]); }
    else printf("-1");

    return 0;
}
//dp[i+1][j]: i番目での整数の中からいくつかを選び、その総和をjとする方法を全て考えた時の、選んだ整数値の最小値