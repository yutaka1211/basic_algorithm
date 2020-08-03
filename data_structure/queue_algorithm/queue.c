#include <stdio.h>
#include <stdlib.h>
#define N (256)

int qd[N];
int qhead;
int qtail;

/*キューに格納された残りの値を出力*/
void Printqueue(void){
    int i;
    for(i=qhead;i!=qtail;i=(i+1)%N){
        printf("p %d\n", qd[i]);
    }
}

/*dをエンキュー*/
void Enqueue(int d){
    if((qtail+1)%N!=qhead){
        qd[qtail]=d;
        qtail=(qtail+1)%N;
    }else{ exit(1); }
}

/*デキュー*/
void Dequeue(void){
    int i;
    if(qhead!=qtail){
        printf("d %d\n", qd[qhead]);
        qhead=(qhead+1)%N;
    }else{ exit(1); }
}

int main(void){
    FILE *fp;
    int n, i, d;

    qhead=0;
    qtail=0;

    fp=fopen("qdata.txt", "r");
    fscanf(fp, "%d\n", &n);                         //1行目(操作の回数)を読み込む
    for(i=0;i<n;i++){
        fscanf(fp, "%d\n", &d);                     //数字を読み込む
        if(d==0){ Dequeue(); }                      //数字が0の場合、出力
        else if (d>0){ Enqueue(d); }                //0より大きい場合、dを入力
    }

    fclose(fp);
    Printqueue();                                   //残りを出力
    return 0;
}