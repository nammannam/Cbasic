#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int data_t;

typedef struct Node{
    data_t inf;
    struct Node *next;

}node_s, *root_t;


void printList(root_t root){
    root_t p;
    if(root == NULL)
        return;
    for(p = root; p != NULL ; p=p->next){
        printf("%d ", p->inf);
    }
    printf("\n");
    return;
}


root_t createNewNode(data_t x){
    root_t newNode = (root_t)malloc(sizeof(node_s));
    newNode->inf = x;
    newNode->next = NULL;

    return newNode;
}

root_t insertLast(root_t root, data_t x){
    root_t newNode = createNewNode(x);

    if(root == NULL){
        return newNode;
    }


    root_t p = root;

    for(p = root; p->next != NULL ; p = p->next);
        p->next = newNode;

    return root; //return ve first

}

root_t insertTop(root_t root, data_t x){
    if(root == NULL)
        return createNewNode(x);

    root_t newNode = createNewNode(x);
    newNode->next = root;

    return newNode;

}

root_t findNode(root_t root, data_t x){
    if(root == NULL)
        return NULL;

    if(root->inf == x){
        return root;
    }else{
        return findNode(root->next, x);
    }
}

root_t insertAfter(root_t root, data_t x, data_t y){
    if(root == NULL)
        return createNewNode(x);
    //Cant find y
    if(findNode(root, y) == NULL)
        return root;

    root_t newNode = createNewNode(x);

    root_t p = findNode(root , y);

    newNode->next = p->next;
    p->next = newNode;



    return root;
}

root_t insertBefore(root_t root, data_t x, data_t y){
    if(root == NULL)
        return createNewNode(x);

    root_t newNode = createNewNode(x);

    if(findNode(root,y) == NULL)
        return root;

    if(root->inf == y){
        newNode->next = root;
        root = newNode;
        return root;
    }

    root_t p;
    for(p = root; p->next->inf != y; p = p->next);
        newNode->next = p->next;
        p->next = newNode;


    return root;
}

root_t removeSingleNode(root_t root, data_t x){
    if(root == NULL)
        return root;

    if(root->inf == x){
        root_t tmp = root;
        root = root->next;
        free(tmp);
        return root;
    }

        root->next = removeSingleNode(root->next, x);

        return root;
}

root_t removeAllNode(root_t root, data_t x){
    if(root == NULL)
        return root;

    if(root->inf == x){
        root_t tmp = root;
        root = root->next;
        free(tmp);
        root = removeAllNode(root, x);
        return root;
    }

        root->next = removeAllNode(root->next, x);

        return root;
}

int countNode(root_t root){
    if(root == NULL)
        return 0;
    int cnt = 0;
    root_t p;
    for(p = root; p != NULL ; p=p->next)
        cnt++;

    return cnt;

}

root_t reverseList(root_t root){
    if(root == NULL)
        return NULL;

    root_t p = root;
    root_t pp = NULL;
    root_t np = NULL;

    while( p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }

    return pp;


}

root_t freeList(root_t root){
   if(root == NULL)
        return NULL;
   root_t tmp = root;
   root = root->next;
   free(tmp);

    return freeList(root);
}

root_t sortList(root_t root, root_t result){
    if(root == NULL)
        return NULL;

    root_t p;
    for(p = root; p != NULL; p = p->next){
        if(p->inf % 2 == 0){
            result = insertLast(result, p->inf);
        }
    }

     for(p = root; p != NULL; p = p->next){
        if(p->inf % 2 != 0){
            result = insertLast(result, p->inf);
        }
    }

    return result;

}

int main(){
    root_t llist = NULL;
    root_t sorted = NULL;



char cmd[20];
int inp;
int print;
while(1){
    scanf("%s", cmd);

    if(strcmp(cmd, "InsertTail") == 0){
        scanf("%d", &inp);
        if(inp > 0 && findNode(llist, inp) == NULL)
            llist = insertLast(llist, inp);

    }else if(strcmp(cmd, "InsertHead") == 0){
        scanf("%d", &inp);
        if(inp > 0 && findNode(llist, inp) == NULL )
            llist = insertTop(llist, inp);
    }else if(strcmp(cmd, "Print") == 0){
        scanf("%d", &print);
        break;
    }


}

    if(print == 0){
        printList(llist);
    }else if(print == 1){
        sorted = sortList(llist, sorted);
        printList(sorted);
    }else{
        return 0;
    }



 //TEST FREELIST
    llist = freeList(llist);
    sorted = freeList(sorted);
    return 0;
}
