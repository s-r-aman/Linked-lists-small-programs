#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *link;
};

struct stack *top;

void push(int x){
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));

    if(top == NULL){

        top = temp;
        temp -> data = x;
        temp -> link = NULL;
    }else{
        temp -> link = top;
        temp -> data = x;
        top = temp;
    }
}

void pop(){
    if(top == NULL){
        printf("Error : There are no elements in the stack to pop.");
        return;
    }else{
        struct stack *temp;
        temp = top;
        top = top -> link;
        free(temp);
    }
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

void showtop(){
    if(top == NULL){
        printf("Error : There are no elements in the stack.");
        return;
    }else{
        printf(" %d", top->data);
    }
}

void print(){
    struct stack *temp;
    temp = top;
    printf("The list is :");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main(){
    top = NULL;
    push(5);
    push(7);
    push(4);
    print();
    pop();
    print();
}
