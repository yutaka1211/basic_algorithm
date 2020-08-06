#include <stdio.h>
#include <string.h>
#define INF (100)

int min(int num1, int num2){
    int result;
    if(num1<num2){ result=num1; }
    else{ result = num2; }

    return result;
}

int dp[110][10010];

int main(){
    int n=4;
    int m=5;
    int a[5]={1,2,4,7};

    for(int i=0;i<110;i++){
        for(int j=0;j<10010;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
            if(j>=a[i]){ dp[i+1][j]=min(dp[i+1][j], dp[i][j-a[i]]+1); }
        }
    }

    if(dp[n][m]<INF){ printf("%d\n", dp[n][m]); }
    else printf("-1");

    return 0;
}