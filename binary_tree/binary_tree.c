#include <stdio.h>

typedef struct node{
    int key;
    struct node *left, *right, *parent;
}Node;

int Find(Node *node, int k){
    if(node==NULL){ return -1; }
    if(k<(node->key)){ return Find(node->left, k); }
    else if((node->key)==k){ return 1; }
    else { return Find(node->right, k); }
}

void Insert(Node *root, Node *newitem){
    while(1){
        if((newitem->key)<(root->key)){                             //追加する接点よりルート接点の方が大きい場合
            newitem->parent=root;                                   //追加する接点の親をルート接点へ
            root=root->left;
        }else if((newitem->key)==(root->key)){                      //追加する接点とルート接点が同じ場合
            break;                                                  //何もせずに終了
        }else {                                                     //ルート接点より追加する接点の方が大きい場合
            if((newitem->key)<(root->parent->key) && root->left==NULL){
                newitem->parent=root->parent;
                root->parent->left=newitem;
                root->parent=newitem;
            }else if((newitem->key)<(root->parent->key) && root->left!=NULL){
                newitem->parent=root;
                root=root->right;
            }
            else{
                newitem->parent=root;
                root=root->right;
            }
        }
        if(root==NULL){                                              //ルートがNULLの場合
            root=newitem->parent;                                    //追加する接点の親をルートへ
            ((root->key)<(newitem->key))?(root->right=newitem):(root->left=newitem);
            break;
        }
    }
}

int main(void){
    int array[8]={3,4,9,21,17,15,18,22};


    Node root;
    root.key=11;
    root.parent=NULL;
    root.left=NULL;
    root.right=NULL;

    Node newitem;
    for(int i=0;i<2;i++){
        newitem.key=array[i];
        newitem.parent=NULL;
        newitem.left=NULL;
        newitem.right=NULL;
        Insert(&root, &newitem);
    }

    //printf("%d", Find(&root, 15));

    return 0;
}