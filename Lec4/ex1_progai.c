#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Eltype char
#define MAX 100
#define amnt 3

typedef struct stack_s
{
    Eltype data[MAX];
    int top;

} stack_t;

Eltype convert(char c)
{
    return c;
}

void initialize(stack_t *pStack)
{
    pStack->top = -1;
}

bool push(stack_t *pStack, Eltype data)
{
    if (pStack->top >= MAX - 1) // Check MAX
        return false;

    (pStack->top)++;
    pStack->data[pStack->top] = data;
    return true;
}

Eltype pop(stack_t *pStack)
{
    if (pStack->top == -1)
    {
        printf("stack underflowed\n");
        exit(2);
    }

    Eltype popRes = pStack->data[pStack->top];
    (pStack->top)--;

    return popRes;
}



int main()
{
    stack_t testStack[amnt];
    initialize(&testStack[0]);
    initialize(&testStack[1]);
    char s1[100], s2[100];
    // push(&testStack[0], '1');
    // push(&testStack[0], '2');
    // push(&testStack[0], '3');
//Input string 1
    scanf("%s", &s1);
    int i = 0;
    while (s1[i] != '\0')
    {
        push(&testStack[0], s1[i]);
        i++;
    }

//Input string 2
    scanf("%s", &s2);
    i = 0;
    while (s2[i] != '\0')
    {
        push(&testStack[1], s2[i]);
        i++;
    }


    int carry = 0;
    stack_t resultStack;
    initialize(&resultStack);

    while (testStack[0].top != -1 || testStack[1].top != -1 || carry != 0)
    {
        int a = 0, b = 0;
        if (testStack[0].top != -1)
            a = testStack[0].data[testStack[0].top] - '0';

        if (testStack[1].top != -1)
            b = testStack[1].data[testStack[1].top] - '0';

        int sum = a + b + carry;
        carry = sum / 10;
        int digit = sum % 10;

        push(&resultStack, digit + '0');

        if (testStack[0].top != -1)
            pop(&testStack[0]);
        
        if (testStack[1].top != -1)
            pop(&testStack[1]);
    }

    while (resultStack.top != -1)
    {
        printf("%c", pop(&resultStack));
    }

    return 0;
}