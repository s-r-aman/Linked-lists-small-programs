#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start;

void insert(int x, int n){
    struct node *temp2 = (struct node*)(malloc(sizeof(struct node)));
    struct node *temp1 = start;

    if(start==NULL){
        temp2->data = x;
        temp2->next = NULL;
        start = temp2;
    }else if(n==1){
        temp2->data = x;
        temp2->next = temp1;
        start = temp2;
    }else{
        int i;
        for(i=2;i<n;i++){
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        temp1->next = temp2;
        temp2->data = x;
    }

}

void print(){
    struct node *temp;
    temp = start;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
}

int main(){
    start = NULL;
    insert(5,1);
    insert(4,2);
    insert(6,1);
    print();
}
