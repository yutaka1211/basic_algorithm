#include <stdio.h>
#include <stdlib.h>

struct CELL{
    struct CELL *prev;
    int data;
    struct CELL *next;
};
struct CELL *head=NULL, *tail=NULL;

int ShowList(){
    struct CELL *q;
    if(head==NULL){ return 0; }
    for(q=head; q->next!=NULL; q=q->next){ printf("[%d]->", q->data); }
    printf("[%d]\n", q->data);
    return 1;
}

int ShowListR(){
    struct CELL *q;
    if(head==NULL){ return 0; }
    for(q=tail; q->prev!=NULL; q=q->prev){
        printf("[%d]<-", q->data);
    }
    printf("[%d]\n", q->data);
    return 1;
}

void AddData(int x){
    struct CELL *r;
    r=malloc(sizeof(struct CELL));
    r->data=x;
    r->next=head;
    r->prev=NULL;
    if(head!=NULL) { head->prev=r; }
    if(tail==NULL) { tail=r; }
    head=r;
}

int DelData(int y){
    struct CELL *q;
    if(head==NULL){ return 0; }
    for(q=head; q->next!=NULL; q=q->next){
        if(y==q->data){
            if(q==head){ head=q->next; }
            else { q->prev->next=q->next; }
            if(q==tail){ tail=q->prev; }
            else { q->next->prev=q->prev; }
            free(q);
            return 1;
        }
    }
    return 0;
}

int main(){
    int i, a[6]={3, 4, 10, 1, 5, 9};
    for(i=0;i<6;i++){
        AddData(a[i]);
    }
    ShowList();
    DelData(a[2]);
    DelData(a[5]);
    ShowListR();
    return 0;
}