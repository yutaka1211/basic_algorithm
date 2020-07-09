#include <stdio.h>
#define Size (1000)     //ユニットの最大数
#define N               //ユニットの数
#define INF (1000000000000)

int Cost[N];            //そのユニットまでの距離
int Used[N];            //探索済みか否か
int Dist[N][N];         //2点間の距離
int Via[N];             //ゴールまでのユニットを格納させて置く

int dijkstra(int start, int goal){
    int min;
    int target;

    Cost[start]=0;      //最初のユニットのコストを0に

    while(1){
        min=INF;        //最短距離を無限大に
        for(int i=0;i<N;i++){
            if((!Used[i]&&(min>Cost[i]))){                      //未探索かつ最短距離よりコストが小さい場合
                min=Cost[i];                                    //最短距離にコストを代入
                target=i;                                       //次の目標をiに
            }
        }
        if(target==goal){ return Cost[target]; }                //目標に到達すれば、最短距離を返す

        for(int next=0;next<N;next++){
            if(Cost[next]>(Dist[target][next]+Cost[target])){   //ユニットに格納された距離より、最短距離が小さい場合
                Cost[next]=Dist[target][N]+Cost[target];        //ユニットに距離を格納
                Via[next]=target;                               //通ったユニットとして格納
            }
        }
        Used[target]=1;                                         //通ったユニットを探索済にする
    }
}
//ユニットの数を指定していません