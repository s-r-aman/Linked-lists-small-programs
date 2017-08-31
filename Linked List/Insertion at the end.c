#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    };

struct node *head;

void insert(int x){
    if(head==NULL){
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=NULL;
        head = n;
    }else{
        struct node *n = (struct node*)malloc(sizeof(struct node));
        struct node *temp = head;
        int i = 0;
        while(temp!=NULL){
            temp= temp->next;
            i++;
        }
        printf("%d",i);
        int p = 0;
        temp = head;
        for(p=0;p<(i-1);p++){
            temp = temp->next;
        }
        n->data = x;
        n->next = NULL;
        temp->next = n;
        for(p=1;p==1;p++){

        }

    }

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
