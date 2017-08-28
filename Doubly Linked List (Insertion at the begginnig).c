#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start;

void insert (int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if(start == NULL){
            temp->data =x;
            temp -> next = NULL;
            temp -> prev = NULL;
            start = temp;
    }else{
        temp->next = start;
        temp->next->prev = temp;
        temp->prev = NULL;
        start = temp;
        temp->data =x;
    }
}

void print(){
    struct node *temp;
     temp = start;
     while(temp!=NULL){
        printf(" %d", temp->data);
        temp = temp->next;
     }

}

int main(){
    start = NULL;

    insert(5);
    insert(6);
    print();
}
