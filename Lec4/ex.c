#include <stdio.h>
#include <stdlib.h>

#define MAX 500

typedef char Eltype;

typedef struct stack_arr
{
    Eltype data[MAX];
    int top;
} stack_t;

Eltype convert(char i)
{
    return i;
}

stack_t initialize(stack_t *pStack)
{
    pStack->top = 0;
}

int isFull(stack_t stack)
{
    return stack.top == MAX;
}

int isEmpty(stack_t stack)
{
    return stack.top == 0;
}

void push(Eltype el, stack_t *pStack)
{
    if (isFull(*pStack))
    {
        printf("Overflowed");
        exit(0);
    }
    else
    {
        pStack->data[pStack->top++] = el;
    }
}

Eltype pop(stack_t *pStack)
{
    if (isEmpty(*pStack))
    {
        printf("Underflowed");
        exit(0);
    }
    else
    {
        return pStack->data[--pStack->top];
    }
}

void showData(Eltype c){
    printf("%c", c);
}

int main()
{
    stack_t s;
    initialize(&s);

    char input[100];
    // scanf("%s", &input);
    fgets(input, sizeof(input), stdin);
    int i;
    
    for (i = 0; input[i] != '\0'; i++)
    {
        push(convert(input[i]), &s);
    }
    
    //Đảo ngược chuỗi
        for (i = s.top; s.top != 0; )
        {
            printf("%c", pop(&s));
        }
        printf("\n");
        printf("%d", s.top);
        return 0;
    }
    
