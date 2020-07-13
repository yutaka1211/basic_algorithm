#include <stdio.h>
#define N (5)                                   //データを格納できる数

int top=0;                                      //現在のデータ格納場所について添字

/*プッシュ*/
void push(int *array, int x){
    if(top==N){ printf("Overflow\n"); }         //添字が格納可能数と等しくなった場合
    else { array[top]=x; }                      //そうでなければ、スタックに数字を代入

    top+=1;                                     //添字を変更
}

/*ポップ*/
void pop(int *array){
    if(top==-1){ printf("Underflow\n"); }       //添字が0以下となった場合
    else {                                      //それ以外
        top-=1;                                 //添字を変更
        printf("%d\n", array[top]);             //スタックに数字を代入
    }
}

int main(void){
    int array[N]={0};                          //配列全てを0で初期化

    /*例*/
    push(array, 1);
    push(array, 2);
    pop(array);
    push(array, 3);
    pop(array);
    pop(array);
    push(array, 4);
    pop(array);

    return 0;
}