#include <stdio.h>
#include <stdlib.h>

/*ノードを作成*/
struct CELL{
    struct CELL *prev;
    int data;
    struct CELL *next;
};
struct CELL *head=NULL, *tail=NULL;

/*ノードを表示*/
int ShowList(){
    struct CELL *q;
    if(head==NULL){ return 0; }
    for(q=tail; q->prev!=NULL; q=q->prev){
        printf("[%d]->", q->data);
    }
    printf("[%d]\n", q->data);
    return 1;
}

/*ノードを逆順に表示*/
int ShowListR(){
    struct CELL *q;
    if(head==NULL){ return 0; }
    for(q=head; q->next!=NULL; q=q->next){ printf("[%d]<-", q->data); }
    printf("[%d]\n", q->data);
    return 1;
}

/*データを追加*/
void AddData(int x){
    struct CELL *r;
    r=malloc(sizeof(struct CELL));                                                      //ノードの作成
    r->data=x;                                                                          //ノードに数字を格納
    r->next=head;                                                                       //ノードの次を頭に
    r->prev=NULL;                                                                       //ノードの前をNULLに
    if(head!=NULL) { head->prev=r; }
    if(tail==NULL) { tail=r; }
    head=r;
}

/*データを削除*/
int DelData(int y){
    struct CELL *q;
    if(head==NULL){ return 0; }                                                         //データがない場合
    for(q=head; q->next!=NULL; q=q->next){                                              //全てのデータを探索
        if(y==q->data){                                                                 //任意の数字を持ったノードを見つけた場合
            if(q==head){ head=q->next; }                                                //頭にそのノードを見つけた場合
            else { q->prev->next=q->next; }
            if(q==tail){ tail=q->prev; }                                                //最後にそのノードを見つけた場合
            else { q->next->prev=q->prev; }
            free(q);                                                                    //削除するノードを解放
            return 1;                                                                   //終了
        }
    }
    return 0;
}

int main(){
    int i, value;
    int a[6]={3, 4, 10, 1, 5, 9};
    char input;
    printf("input the number: ");
    scanf("%d", &value);
    AddData(value);                                                                     //任意の数字をリストに追加

    while(1){
        printf("\nContinue? y or n\n");
        scanf(" %c", &input);
        if(input=='y'){                                                                 //ノード作成続行の場合
            printf("\ninput the number: ");
            scanf("%d", &value);
            AddData(value);
        }else{ break; }                                                                 //ノード作成しない場合
    }
    ShowList();

    printf("\nwhat number do you delete: ");
    scanf("%d", &value);
    DelData(value);                                                                     //任意の数字を削除
    ShowList();
    return 0;
}