#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
typedef struct pt{
    char name[100];
    char id[10];

}pt_s;
*/

typedef int data_t;

typedef struct Node{
    data_t inf;
    struct Node* leftChild;
    struct Node* rightChild;


}node_bst, *root_bst;

root_bst makeNode(data_t x){
    node_bst* newNode =(node_bst*)malloc(sizeof(node_bst));
    newNode->inf = x;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;

}

root_bst find_bst(root_bst root, data_t x);

void preOrder(root_bst root){
    if(root == NULL)
        return;
    printf("%d ", root->inf);
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

void inOrder(root_bst root){
    if(root == NULL)
        return;

    inOrder(root->leftChild);
    printf("%d ", root->inf);
    inOrder(root->rightChild);
}

void postOrder(root_bst root){
    if(root == NULL)
        return;

    postOrder(root->leftChild);
    postOrder(root->rightChild);
    printf("%d ", root->inf);
}

root_bst insertBST(root_bst root, data_t x){
    node_bst* newNode = makeNode(x);
    if(root == NULL){
        return newNode;
    }
    if(x == root->inf){
        return root; //If x has been added

    }else if(x < root->inf){
        root->leftChild = insertBST(root->leftChild, x);
        return root;
    }else if(x > root->inf){
        root->rightChild = insertBST(root->rightChild, x);
        return root;
    }
}

void addLeft_bst(root_bst root_main, root_bst root, data_t x){
    if(root->leftChild == NULL && x < root->inf && find_bst(root_main, x) == NULL ){
        root_bst newNode = makeNode(x);
        root->leftChild = newNode;
        return;
    }
    printf("KO THE ADD LEFT\n");
    return;
}

void addRight_bst(root_bst root_main, root_bst root, data_t x){
    if(root->rightChild == NULL && x > root->inf && find_bst(root_main, x) == NULL){
        root_bst newNode = makeNode(x);
        root->rightChild = newNode;
        return;
    }
    printf("KO THE ADD RIGHT\n");
    return;
}

root_bst find_bst(root_bst root, data_t x){
    if(root == NULL)
        return NULL;

    if(x == root->inf){
        return root;

    }else if( x < root->inf){
        return find_bst(root->leftChild, x);

    }

    return find_bst(root->rightChild, x);

}

root_bst findLeft(root_bst root){
    if(root == NULL)
        return NULL;

    return root->leftChild;
}

root_bst findRight(root_bst root){
    if(root == NULL)
        return NULL;

    return root->rightChild;
}

root_bst findMax(root_bst root){
    if(root == NULL){
        return NULL;
    }

    root_bst max = findMax(root->rightChild);
    if(max != NULL){
        return max;
    }

    return root;    //Neu khong co cay con ben trai -> tra ve nut root

}

root_bst findMin(root_bst root){
    if(root == NULL){
        return NULL;
    }

    root_bst min = findMin(root->leftChild);
    if(min != NULL){
        return min;
    }

    return root; //Neu khong co cay con ben trai -> tra ve nut root

}

root_bst findParent(root_bst root_main, root_bst root){
    if(root_main == root || root_main == NULL || root == NULL)
        return NULL;
    if(root_main->leftChild == root || root_main->rightChild == root){
        return root_main;
    }

    root_bst tmp = findParent(root_main->leftChild, root);
    if(tmp != NULL)
        return tmp;

    return findParent(root_main->rightChild, root);
}

root_bst removeNode_bst(root_bst root, data_t x){
    if(root == NULL)
        return NULL;

    if(x < root->inf){ // Lesses
        root->leftChild = removeNode_bst(root->leftChild, x);
    }else if(x > root->inf){ //Greater
        root->rightChild = removeNode_bst(root->rightChild, x);
    }else{
        //NO CHILD
        if(root->leftChild == NULL && root->rightChild == NULL){
            free(root);
            root = NULL;
            return root;
        }

        //1 CHILD
        if(root->rightChild == NULL){
            root_bst tmp = root;
            root = root->leftChild;
            free(tmp);
            return root;

        }else if(root->leftChild == NULL){
            root_bst tmp = root;
            root = root->rightChild;
            free(tmp);
            return root;
        }

        //2 CHILD
        if(root->leftChild != NULL && root->rightChild != NULL){
            root_bst tmp = findMin(root->rightChild);
            root->inf = tmp->inf; // Copy data vao nut can xoa
            root->rightChild = removeNode_bst(root->rightChild, tmp->inf); // Xoa nut bi copy data

        }

    }
    return root;
}

root_bst removeNode_bstV2(root_bst root, data_t x){
    if(root == NULL)
        return NULL;

    if(x < root->inf){ // Lesses
        root->leftChild = removeNode_bst(root->leftChild, x);
    }else if(x > root->inf){ //Greater
        root->rightChild = removeNode_bst(root->rightChild, x);
    }else{
        if(root->leftChild != NULL && root->rightChild != NULL){
            root_bst tmp = findMin(root->rightChild);
            root->inf = tmp->inf; // Copy data vao nut can xoa
            root->rightChild = removeNode_bst(root->rightChild, tmp->inf); // Xoa nut bi copy data
        }else{
            root_bst tmp = root;
            if(root->leftChild == NULL)
                root = root->rightChild;
            else if(root->rightChild == NULL)
                root = root->leftChild;
            free(tmp);

        }

    }
    return root;
}


void freeTree(root_bst root){
    if(root == NULL)
        return NULL;

    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root);

}

int height(root_bst root){
    if(root == NULL){
        return 0;
    }

    int hl = height(root->leftChild);
    int hr = height(root->rightChild);

    if(hl > hr)
        return hl + 1;
    else
        return hr + 1;
}

int stepdepth(root_bst root_main, root_bst root, int k){
    if(root_main == NULL)
        return 0;
    if(root_main == root)
        return k;

    int l1 = stepdepth(root_main->leftChild, root, k + 1 );
    if(l1 != 0)
        return l1;

    return stepdepth(root_main->rightChild, root, k + 1 );
}

int depth(root_bst root_main, root_bst root){
    if(root_main == NULL || root == NULL){
        return 0;
    }
    return stepdepth(root_main, root, 1);
}

int countNode_bst(root_bst root){
    if(root == NULL)
        return 0;

    return 1 + countNode_bst(findLeft(root)) + countNode_bst(findRight(root));
}

int main(){
    root_bst root = NULL;


/* //TEST
    root = insertBST(root, 5);
    root = insertBST(root, 4);
    root = insertBST(root, 8);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 7);
    root = insertBST(root, 9);

    //TEST FIND
    root_bst p = find_bst(root, 9);
    if(p != NULL){
        printf("%d\n", p->inf);
    }else{
        printf("NONE\n");
    }

    //TEST FINDMAX
    root_bst max = findMax(root);
    if(max != NULL){
        printf("%d\n", max->inf);
    }else{
        printf("NONE\n");
    }
    //TEST FINDMIN
    root_bst min = findMin(root);
    if(min != NULL){
        printf("%d\n", min->inf);
    }else{
        printf("NONE\n");
    }

    inOrder(root);
    printf("\n");

    //TEST REMOVENODE
    root = removeNode_bst(root, 3);

    preOrder(root);

    //NGUY HIEM : VI KHONG DUNG VOI BST
    //addRight_bst(root, find_bst(root, 9), 10);

    //preOrder(root);


    // TEST HEIGHT
    printf("\n%d\n", height(find_bst(root, 4)));

    //TEST DEPTH
    printf("\n%d\n", depth(root, find_bst(root, 7)));

    //TEST COUNT NODES
    printf("\n%d\n", countNode_bst(root));

    //TEST FIND PARENT
    root_bst parent = findParent(root, find_bst(root, 10));
    if(parent != NULL){
        printf("PARENT: %d\n", parent->inf);
    }else{
        printf("NO PARENT\n");
    }

    //TEST FREETREE
    freeTree(root);
    root = NULL; //Sau khi Free phai gan lai NULL

    preOrder(root);

*/
    char cmd[20];
    int u;
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd,"insert") == 0){
            scanf("%d", &u);
            root = insertBST(root, u);
        }else if(strcmp(cmd, "delete")==0){
            scanf("%d", &u);
            root_bst find = find_bst(root, u);
            if(find != NULL){
                root = removeNode_bstV2(root, u);
                inOrder(root);
                printf("\n");
            }else{
                printf("Not found\n");
            }
        }else if(strcmp(cmd, "#") ==0){
            break;
        }

    }
    //printf("%d\n", findRight(find_bst(root, 3))->inf);


    //TEST FREETREE
    freeTree(root);
    root = NULL; //Sau khi Free phai gan lai NULL

    return 0;

}
