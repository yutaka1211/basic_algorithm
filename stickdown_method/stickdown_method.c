#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Height (51)  //迷路の縦サイズ
#define Width (51)  //迷路の横サイズ

int map[Height][Width];  //迷路の配列
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

void make_map(){
    /*周りを壁で囲む*/
    for(int i=0;i<Height;i++){
        for(int j=0;j<Width;j++){
            if(i==0||j==0||i==Height-1||j==Width-1){ map[i][j]=Wall; }   //周りを壁で埋める
            else { map[i][j]=Road; }    //他は道で埋める
        }
    }

    srand((unsigned)time(NULL));

    for(int i=2;i<Height-1;i+=2){
        for(int j=2;j<Width-1;j+=2){
            map[i][j]=Wall; //必ず壁になるところに壁を置く

            while(1){
                int r;
                if(i==2){ r=rand()%4; } //最上段の壁のみ4方向に壁をおける
                else { r=rand()%3; }    //他の段は上に壁を置けない(周りが全て壁の可能性があるから)

                if(map[i+dir[r].y][j+dir[r].x]!=Wall){  //壁と壁が被っていないか確認
                    map[i+dir[r].y][j+dir[r].x]=Wall;   //被っていなければ、壁を置く
                    break;
                }
            }
        }
    }
}

int main(){
    make_map();

    Print();

    return 0;
}


