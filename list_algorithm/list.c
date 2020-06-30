#include <stdio.h>
#include <stdlib.h>

/*ノードを作成*/
typedef struct node{
    int value;
    struct node *next;
}Node;

Node *head;             //全体のノードの始めを表す
Node *tail;             //全体のノードの終わりを表す

/*ノードを逆順にする*/
Node *Reverse(Node *x){
    Node *pre=NULL;     //前を表すノード
    Node *next;         //後を表すノード

    while(x){
        next=x->next;
        x->next=pre;
        pre=x;
        x=next;
    }

    return pre;
}

/*昇順に表示*/
void Print_ascend(Node *head){
    while(1){
        if(head->next==NULL){       //次がNULLの場合、表示して終了
            printf("%d \n", head->value);
            break;
        }
        else {                      //次にノードが存在する場合、表示して次のノードへ
            printf("%d ", head->value);
            head=head->next;
        }
    }
}

int main(void){
    int value;
    char input;
    Node *p;

    p=(Node *)malloc(sizeof(Node)); //1つ目のノード作成

    printf("input the number: ");   //1つ目のノードに格納する値を定める
    scanf("%d", &value);

    p->value=value;     //ノードに値を格納
    p->next=NULL;       //ノードの次はNULLを格納
    head=p;             //全体の始めのノードとして設定
    tail=p;             //全体の終わりのノードとして設定

    while(1){
        printf("Continue? y or n\n");
        scanf(" %c", &input);

        if(input=='y'){ //ノード作成続行の場合
            p=(Node *)malloc(sizeof(Node)); //新たなノードの作成

            printf("input the number");
            scanf("%d", &value);

            p->value=value;         //作成したノードに値を格納
            p->next=NULL;           //作成したノードの次はNULLを格納
            tail->next=p;           //tailの次に作成したノードを格納
            tail=p;                 //作成したノードを最後のノードにする

        }else if(input=='n'){ break;}       //終了の場合はループ終了
        else{ printf("input y or n\n"); }   //yとn以外を代入した場合
    }

    Print_ascend(head);             //全てを昇順に表示

    Print_ascend(Reverse(head));             //全てを降順に表示

}
/*リスト構造について*/
//リストの挿入、消去が容易
//リストを動的に作成できるので、必要に応じて作成できる
//アクセスに時間がかかる