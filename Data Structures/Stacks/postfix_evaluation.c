#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define OPERAND 1
#define OPERATOR 0
#define EMPTY 1
#define NOT_EMPTY 0

typedef struct stack_int{
    int capacity;
    int top;
    int *store;
}STACK_INT;

STACK_INT create_stack(int stack_size);
int pop(STACK_INT *s);
int isEmpty(STACK_INT *s);
int peek(STACK_INT *s);
int isOperand(char oper);
void push(STACK_INT *s, int keepit);


int main()
{
    char postfix[] = "73426^*+*8+"; // store the operands in the stack and pop them accordingly and perform the binary operations using the operators
    //char postfix[] = "231*+9-";
    int res, postfix_ind, postfix_size, op1, op2;
    STACK_INT operands;
    postfix_size = strlen(postfix);
    operands = create_stack(postfix_size+1);
    for(postfix_ind=0;postfix[postfix_ind];postfix_ind++)
    {
        if(isOperand(postfix[postfix_ind]) == OPERAND)
            push(&operands,postfix[postfix_ind]-'0');
        else{
            op2 = pop(&operands);
            op1 = pop(&operands);

            switch(postfix[postfix_ind])
            {
            case '+':
                push(&operands,op1 + op2);
                break;
            case '-':
                push(&operands,op1 - op2);
                break;
            case '*':
                push(&operands,(op1*op2));
                break;
            case '^':
                push(&operands,(int)pow(op1,op2));
                break;
            }
        }
    }
    res = pop(&operands);
    printf("\nThe value of the postfix expression is : %d", res);

    return 0;
}

STACK_INT create_stack(int stack_size)
{
    STACK_INT temp;
    temp.capacity = stack_size;
    temp.store = (int *) malloc(stack_size * sizeof(int));
    temp.top = -1;
    return temp;
}
int pop(STACK_INT *s)
{
    int safe;
    safe = s->store[s->top];
    s->top--;
    return safe;
}

int isEmpty(STACK_INT *s)
{
    return s->top == -1;
}

int peek(STACK_INT *s){

    return s->store[s->top];
}

int isOperand(char oper){

    return isdigit(oper);

}

void push(STACK_INT *s, int keepit){

    s->top++;
    s->store[s->top] = keepit;
}
