#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    };

struct node *head;

void insert(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;

}

void print(){
    struct node *temp = head;
    printf("List is : ");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    head = NULL;

    printf("Enter the number of elements you want to Enter\n");

    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){

        printf("Enter the element you want to enter\n");
        scanf("%d",&x);
        insert(x);
        print();
    }

    return 0;
}
