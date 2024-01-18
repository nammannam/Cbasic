#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

int cnt = 0;

typedef int data_t;

typedef struct StackNode{
    data_t inf;
    struct StackNode *next;

}stack_s, *topStack;



stack_s* createNewNode(data_t x){
    stack_s* newNode = (stack_s*)malloc(sizeof(stack_s));
    newNode->inf = x;
    newNode->next = NULL;

    return newNode;
}

stack_s* push(topStack top, data_t x){
    if(cnt > MAX){
        return NULL;
    }
    stack_s* Node = createNewNode(x);

    if(top == NULL){
        cnt++;
        return Node;
    }
    Node->next = top;
    cnt++;

    return Node;
}

stack_s* pop(topStack top){
    if(top == NULL){
        return NULL;        //Stack empty
    }

    data_t x = top->inf;
    //printf("POP: %d\n", x);

    topStack tmp = top;
    top = top->next;
    free(tmp);
    cnt--;

    return top;

}

void showTop(topStack top){
    if(top == NULL){
        return; //Stack empty
    }
    printf("%d\n", top->inf);
    return;
}

void showStack(topStack top){
    if(top == NULL)
        return; //Stack empty

    topStack p;
    for(p = top; p!= NULL; p=p->next){
        showTop(p);
    }
    return;
}



int main(){
    topStack *top = malloc(sizeof(stack_s)); //cap phat dong top

    top[0] = NULL;
    top[0] = push(top[0], 1);
    top[0] = push(top[0], 2);
    top[0] = push(top[0], 3);
    top[0] = push(top[0], 4);
    top[0] = push(top[0], 4);
    top[0] = push(top[0], 4);
    top[0] = push(top[0], 4);

    printf("COUNT: %d\n",cnt );
/*
    showTop(top[0]);
    top[0] = pop(top[0]);
    printf("COUNT: %d\n",cnt );
    showStack(top[0]);
    top[0] = pop(top[0]);
    printf("COUNT: %d\n",cnt );
    showStack(top[0]);
*/
    while(top[0] != NULL){
        showTop(top[0]);
        top[0] = pop(top[0]);

    }


    return 0;


}
