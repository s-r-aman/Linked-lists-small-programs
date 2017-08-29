#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start;

/*------Function to Print a linked list------*/
void print(){
    struct node *temp;
     temp = start;
     while(temp!=NULL){
        printf(" %d", temp->data);
        temp = temp->next;
     }

}

/*------Function to insert data into a linked list------*/
void insert(int x){
    struct node *tempins = (struct node *)malloc(sizeof(struct node));
    struct node *temp1;

    if(start==NULL){                        //If the list is empty
        start = tempins;
        tempins->data = x;
        tempins->next = NULL;
    }else{
            temp1 = start;

            if(temp1->next == NULL){        //List has at least one element
                if((temp1->data) >= x){     //If it has only one element
                    tempins->next = start;
                    start = tempins;
                    tempins->data =x;

                    }else{
                        temp1 ->next = tempins;
                        tempins->next = NULL;
                        tempins->data = x;
                    }
                }else{                      //List has 2 or more that 2 elements

                    if((temp1->data) >= x){ //Checking it if it is smaller then the first element
                        tempins->next = start;
                        start = tempins;
                        tempins->data = x;
                    }else{                  //Checking in the other elements
                        while((temp1->next->data)  <= x){
                            if(temp1->next->next == NULL){
                            temp1=temp1->next;
                            temp1->next = tempins;
                            tempins->next=NULL;
                            tempins->data =x;
                            return;
                            }else{
                                temp1=temp1->next;

                            }

                        }

                        tempins->next = temp1->next;
                        temp1->next = tempins;
                        tempins->data = x;
                    }

                }



        }

    }



int main(){
    start = NULL;
    insert(1); //Calling the function insert
    insert(2);
    insert(3);
    insert(4);
    insert(7);
    insert(6);
    insert(1);
    insert(3);
    print();   //Calling Function to print
}
