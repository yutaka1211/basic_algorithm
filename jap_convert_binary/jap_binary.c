#include <stdio.h>
#include <string.h>
#define N (1000)

void Jap_binary(int x, int *y){
    int a=0;
    int i, j;
    int array[N];                   //2進数を入れる箱

    while(x>0){
        array[a++]=(x%2);
        x/=2;
    }
    for(j=8-a;j>0;j--){ printf("0"); }
    for(i=a-1;i>=0;i--){
        printf("%d", array[i]);
        (*y)--;
    }
}

int main(void){

    int i, j;
    int count;
    char jap[21];

    printf("20文字以下の日本語を入力\n");
    fgets(jap, sizeof(jap), stdin);

    jap[strlen(jap)-1]='\0';        //改行を消してNULL文字を追加

    for(i=0;i<strlen(jap);i+=2){
        count=16;
        for(j=0;j<2;j++){ Jap_binary(jap[i+j], &count); }
        printf(" ");
    }

    return 0;
}
/*Shift_JISでのエンコードで動作*/