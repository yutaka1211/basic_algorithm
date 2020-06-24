#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Height (51) //迷路の高さ
#define Width (101)  //迷路の高さ

int map[Height][Width]; //迷路の配列
int Road=0;
int Wall=1;

struct{
    int x;
    int y;
}dir[]={
    {1,0},  //右に進む
    {0,1},  //下に進む
    {-1,0}, //左に進む
    {0,-1}  //上に進む
};

/*ターミナルに迷路表示*/
void Print(){
    for(int i=0;i<Height;i++){
        for(int j=0;j<Width;j++){
            if(map[i][j]==Wall){ printf("■"); }
            else { printf(" "); }
        }
        printf("\n");
    }
}

/*ランダムに1〜引数の中での奇数を出力*/
int rand_odd(int mod){

    srand((unsigned)time(NULL));

    int r=1+rand()%mod; //1~modまでの整数乱数作成
    if(r%2==0){ r++; }  //乱数を奇数にする

    return r;   //作成した乱数を返す
}

/*道作成*/
void make_map(int x, int y){
    int d=rand()%4; //壁を置く方向を格納
    int dd=d;   //壁を置いた方向を格納(行き止まりを判定)
    while(1){
        int px=x+(dir[d].x)*2;
        int py=y+(dir[d].y)*2;
        if(px<0||py<0||px>=Width||py>=Height||map[py][px]==Road){   //もし進めない場合
            d++;    //方向転換
            if(d==4){ d=0; }
            if(d==dd){ return; }    //一周回ったら終了
            continue;   //進めない場合は以下を実行しない
        }
        map[y+(dir[d].y)][x+(dir[d].x)]=Road;   //一個隣を道にする
        map[py][px]=Road;   //二個隣を道にする
        make_map(px,py);    //再帰的道作りを実行
        d=dd=rand()%4;  //進んで行き止まりの場合、進む方向をもう一度決め直す
    }
}

/*道のスタート位置決定*/
void maze(){
    int x=rand_odd(Width-2);    //道を作るスタート地点を決める
    int y=rand_odd(Height-2);   //道を作るスタート地点を決める

    make_map(x, y);
}

int main(){

    srand((unsigned)time(NULL));

    for(int y=0;y<Height;y++){
        for(int x=0;x<Width;x++){ map[y][x]=Wall; } //迷路を壁で埋める
    }

    maze(); //迷路作成

    Print();    //迷路表示

    return 0;
}

//macのターミナルだと汚い
//windowsのコマンドプロンプトだと綺麗