#include <stdio.h>
#include <string.h>


int Soboku(char *text, char *pattern, int line){

    int i, j;
    int n=strlen(text);                                 //行の長さ
    int m=strlen(pattern);                              //パターンの長さ
    int findcount=0;

    for(int t=0;t<n-m;t++){                             //探索開始
        for(i=t, j=0;j<m;i++, j++){                     //左端から文字照合
            if(text[i]!=pattern[j]){ break; }
        }
        if(j==m){                                       //発見
            printf("Line%d, t=%d\n", line, t+1);        //パターンの位置を表示
            findcount++;                                //発見数
        }
    }
    return findcount;
}

int main(int argc, char *argv[]){
    char text[100];                                     //1行の長さの最大値
    int line=0;
    int count=0;
    FILE *fp;

    if(argc!=3){                                        //形式が違っていれば
        printf("%s [search word][target txt file]\n", argv[0]);
        return -1;
    }
    while(fgets(text, 100, fp)!=NULL){                  //1行ずつ読み込む
        line++;                                         //今の行数を示す
        count+=Soboku(text, argv[1], line);             //パターンの発見数
    }
    fclose(fp);

    printf("%s: %d times\n", argv[1], count);

    return 0;
}