#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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

void initialize(stack_t *pStack)
{
    pStack->top = -1;
}

int isFull(stack_t stack)
{
    return stack.top == MAX - 1;
}

int isEmpty(stack_t stack)
{
    return stack.top == -1;
}

void push(Eltype el, stack_t *pStack)
{
    if (isFull(*pStack))
    {
        printf("2");
        exit(0);
    }
    else
    {
        pStack->top++;
        pStack->data[pStack->top] = el;
    }
}

Eltype pop(stack_t *pStack)
{
    if (isEmpty(*pStack))
    {
        printf("1");
        exit(0);
    }
    else
    {
        return pStack->data[pStack->top--];
    }
}

int main()
{
    stack_t s;
    initialize(&s);

    char input[504];
    // scanf("%s", input);
    // gets(input);
    fgets(input, sizeof(input), stdin);
    printf("%d\n", strlen(input));
    if(strlen(input) == 0){
    input[strcmp(input, "\n")] = '\0';
    
    if (input[0] == '\0') {
        printf("1");
        return 0;
    }
    }
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        push(convert(input[i]), &s);
    }
    printf("%d", s.top);

    // printf("%d", s.top);

    // Đảo ngược và hiển thị chuỗi
    while (!isEmpty(s))
    {
        Eltype c = pop(&s);
        printf("%c", c);
    }

    return 0;
}
