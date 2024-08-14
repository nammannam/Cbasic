#include<stdio.h>
#include<stdlib.h>

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

int main(){
    root_t llist = NULL;

    llist = insertLast(llist, 1);
    llist = insertLast(llist, 2);
    llist = insertLast(llist, 3);
    llist = insertLast(llist, 4);
    llist = insertLast(llist, 1);
    llist = insertLast(llist, 1);
    llist = insertLast(llist, 1);
    llist = insertLast(llist, 1);

    llist = insertTop(llist, 5);
    llist = insertTop(llist, 6);

    llist = insertAfter(llist, 10, 7);

    llist = insertBefore(llist, 10, 6);

    printList(llist);


    llist = removeSingleNode(llist, 10);

    printList(llist);


    llist = removeAllNode(llist, 1);

    printList(llist);


    //TEST FREELIST
    llist = freeList(llist);
    if(llist == NULL){
        printf("0");
    }
    printList(llist);


    //TEST FINDNODE
    if(findNode(llist, 7) != NULL)
        printf("1");
    else
        printf("0");

/*
    char cmd[20];
    data_t u , v;
    int n, i;

    scanf("%d", &n);
    for(i = 0 ; i < n ; ++i){
        scanf("%d", &u);
        llist = insertLast(llist, u);
    }
    do{
        scanf("%s", cmd);
        if(strcmp(cmd, "addlast")==0){
            scanf("%d", &u);
            if(findNode(llist,u) == NULL)
                llist = insertLast(llist, u);

        }else if(strcmp(cmd, "addfirst")==0){
            scanf("%d", &u);
            if(findNode(llist,u) == NULL)
            llist = insertTop(llist, u);
        }else if(strcmp(cmd, "addafter")==0){
            scanf("%d %d", &u,&v);
            if(findNode(llist,u) == NULL)
            llist = insertAfter(llist, u ,v);
        }else if(strcmp(cmd, "addbefore")==0){
            scanf("%d %d", &u,&v);
            if(findNode(llist,u) == NULL)
            llist = insertBefore(llist, u ,v);
        }else if(strcmp(cmd, "remove") ==0){
            scanf("%d", &u);
            llist = removeSingleNode(llist, u);

        }else if(strcmp(cmd, "reverse")==0){
            llist = reverseList(llist);
        }

    }while(strcmp(cmd,"#")!=0);

    printList(llist);

*/


    return 0;
}
