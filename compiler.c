#include <stdio.h>
#include <stdlib.h>
 

struct stack
{
    int size;
    int top;
    char *arr;
};

char operators[] = {'+', '-', '*', '/'};
char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
void parser(char *exp)
{
    printf("----PARSING----");
    char oper[100];
    char num[100];
    for ( int i = 0; exp[i] != '\0'; i++)
    {
        for(int j = 0; j < sizeof(operators); j++){
            if (exp[i] == operators[j])
            {
                oper[i] = operators[j];
                printf("operators are %c\n", oper[i]);
            }
            
        }
        for(int j = 0; j < sizeof(numbers); j++){
            if (exp[i] == numbers[j])
            {
                num[i] = numbers[j];
                printf("numbers are %c\n", num[i]);
            }
            
        }
        
    }
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char **argv)
{

   char *exp = "[4-6]((8){(9-8)})";
 
    if (parenthesisMatch(exp))
    {
        printf("ENTERED STRING IS VALID\n");
    }
    else
    {
        printf("ENTERED STRING IS NOT VALID\n");
    }
    parser(exp);
    return 0;
}