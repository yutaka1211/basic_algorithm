#include <stdio.h>
#include <string.h>

int sum=0;                                                                  //照合回数

int Move(char *pattern, char a){
    int i, m;
    int skip[128]={0};

    m=strlen(pattern);                                                      //検索パターンの長さ

    for(i=m-2, skip[pattern[m-1]]+=m;i>=0;i--){                             //skip配列の作成
        if(skip[pattern[i]]>0){ continue; }                                 //右端からの距離を代入
        skip[pattern[i]]=(m-i-1);                                           //右端からの距離を代入
    }

    if(skip[a]==0){ return m; }                                             //パターン以外の文字の場合、パターンの長さを返す
    else if(skip[a]>0 && skip[a]<=80){ return skip[a]; }                    //パターン内の文字の場合、パターンi番目の値を返す
    else { return m; }                                                      //それ以外の場合、パターンの長さを返す
}

int Search(char *text, char *pattern, int line){

    int n=strlen(text);                                                     //行の長さ
    int m=strlen(pattern);                                                  //パターンの長さ
    int i=0;                                                                //パターンと文章が同じかを判断する
    int t=m-1;                                                              //文章の初期探索位置
    int findcount=0;

    while(t<n){
        for(int l=0;l<m;l++){
            sum++;                                                          //照合回数をカウント
            if(text[t-l]!=pattern[m-l-1]){                                  //パターンと行が異なる場合
                if(l-Move(pattern, text[t-l])>=0){                          //バックスライドとなる場合
                    t+=(l-Move(pattern, text[t-l])+2);                      //文章の位置を訂正
                }
                t=((t-l)+Move(pattern, text[t-l]));                         //skipにしたがって移動
                break;
            }else{ i++; }                                                   //パターンと行が同じである場合
        }
        if(i==m){                                                           //行にパターンと同じ単語が存在する場合
            printf("Line%d, t=%d\n", line, t+2-m);                          //表示
            findcount++;
            t++;
        }
        i=0;
    }
    return findcount;
}

int main(int argc, char *argv[]){
    char text[100];
    int line=0;
    int count=0;
    FILE *fp;

    if(argc!=3){
        printf("%s [search word][target txt file]\n", argv[0]);
        return -1;
    }else{
        printf("file is not found.\n");
        return -1;
    }
    while(fgets(text, 100, fp)!=NULL){                                       //1行ずつ読み込む
        line++;                                                              //今の行数を示す
        count+=Search(text, argv[1], line);                                  //パターンの発見数
    }
    fclose(fp);

    printf("照合回数:%d\n", sum);
    printf("%s: %d times\n", argv[1], count);

    return 0;
}