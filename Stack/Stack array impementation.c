#include<stdio.h>
#include<stdlib.h>

int a[101];
int top = -1;

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(int x){
    if(top == 100){
        printf("Error : Stack Overflow\n");
        return;
    }
    top = top+1;
    a[top] = x;
}

void pop(){
    if(isEmpty() == 1){
        printf("No elements to pop\n");
    }else{
        top = top-1;
    }

}

void print(){
    int i = 0;
    printf("\n");
    for(i=0; i<=top ;i++ ){
        printf(" %d",a[i]);
    }
    printf("\n");
}

int main(){
    push(1);
    push(2);
    push(5);
    push(6);
    print();
    pop();
    print();
}
