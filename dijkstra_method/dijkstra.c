#include <stdio.h>
#define INF (255)
#define MAXN (16)

int len[MAXN];
int prev[MAXN];

void Printpath(int v){
    if(v!=-1){
        Printpath(prev[v]);
        printf("-%d", v);
    }
}

int Allvisited(int *array, int n){
    int r=1;
    for(int i=0;i<n;i++){ r*=array[i]; }
    return r;
}

void Compute(int *w, int n, int s, int g){
    int i;
    int visited[MAXN];
    int j, next, min;

    for(i=0;i<n;i++){
        len[i]=INF;                                     //最短経路をINFで初期化
        visited[i]=0;                                   //最短経路を調べたか確認するため、0で初期化
        prev[i]=-1;                                     //後で最短経路を表示するため、-1で初期化
    }

    i=s;                                                //最初の場所をiに格納
    len[i]=0;                                           //最初の場所を0に格納
    visited[i]=1;                                       //iを調べたので、1を代入

    while(Allvisited(visited, n)==0){
        min=INF;                                        //1つのユニットからの最短距離をINFにする
        next=g;                                         //次のユニットへの経路が最も短いユニットを格納

        for(j=0;j<n;j++){                               //全てのユニットの最短距離を調べる
            if(visited[j]==1){ continue; }              //既に調べているユニットの場合
            if(len[j]>len[i]+w[i*n+j]){
                len[j]=len[i]+w[i*n+j];                 //jの最短経路、更新
                prev[j]=i;                              //そのユニットへ行くユニット番号を格納
            }
            if(min>len[j]){                             //全体の中で最短経路が更新された場合
                min=len[j];
                next=j;                                 //最短距離が更新されたユニットを次のユニットにする
            }
        }
        i=next;                                         //iを更新
        visited[i]=1;                                   //iを調べたので、1を代入
    }
}

int main(void){
    int w[]={                                           //隣接行列
        0, 2, 5, INF,
        2, 0, 1, 1,
        5, 1, 0, 2,
        INF, 1, 2, 0
    };
    int n=4;                                            //全ユニット数

    printf("隣接行列\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d ", w[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");

    Compute(w, n, 0, 3);
    printf("Shortest path length is %d\n", len[3]);

    Printpath(3);                                       //ユニット3までの最短経路
    printf("\n");

    return 0;
}