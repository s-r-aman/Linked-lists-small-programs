#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start;

void insert (int x){
    struct node *tempins = (struct node*)malloc(sizeof(struct node));
    struct node *temp;

    if(start == NULL){
            tempins->data =x;
            tempins -> next = NULL;
            tempins -> prev = NULL;
            start = tempins;
    }else{
        temp = start;

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = tempins;
    tempins ->prev = temp;
    tempins->next = NULL;
    tempins -> data = x;
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
