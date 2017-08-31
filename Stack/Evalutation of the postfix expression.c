#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*-----Defining the stack data structure using linked list------*/
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

int popValue(){
    if(top == NULL){
        printf("Error : There are no elements in the stack to pop.");
        exit(0);
    }else{
        struct stack *temp;
        int i;
        i = top->data;
        temp = top;
        top = top -> link;
        free(temp);
        return i;
    }
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

int showtop(){
    if(top == NULL){
        printf("Error : There are no elements in the stack.");
        return 0;
    }else{
        return top->data;
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

int isOperand(char c)
{
    if (c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/')
        return 1;
    else
        return 0;
}

int calculate(char c,int op1,int op2)
{
    if (c == '+'){
            return (op1 + op2);
        }else if(c == '-'){
            return (op1 - op2);
        }else if(c == '*'){
            return (op1 * op2);
        }else if(c == '/'){
            return (op1 / op2);
        }
}

int isNumericDigit(char c)
{
	if(c >= '0' && c <= '9')
        return 1;
	else
        return 0;
}

int evaluatePostfix(char exp[50]){
    int i,n;
    n = strlen(exp);
    //  printf("%d", n);
    for(i=0; i<n; i++){
        if(exp[i] == ' ' || exp[i] == ',')
            continue;
        else if(isOperand(exp[i])){
            int op1,op2;
            op2 = popValue();
            op1 = popValue();
            int result;
            result = calculate (exp[i],op1,op2);
            push(result);

        }else if(isNumericDigit(exp[i])){
            int operand = 0;
            while(i<n && isNumericDigit(exp[i])){
                operand = (operand*10) + (exp[i] - '0');
				i++;
            }
            i--;
            push(operand);
        }
    }

    return showtop();
}

int main(){
    int res;
    res = evaluatePostfix("3 5 * 2+");
    printf(" %d",res);
}
