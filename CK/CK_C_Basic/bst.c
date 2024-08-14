#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct info{
    char lop[10];
    char phong[9];

}info_s;


typedef info_s data_t;

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

void inOrder(root_bst root){
    if(root == NULL)
        return;

    inOrder(root->leftChild);
    printf("%s ", root->inf.lop);
    inOrder(root->rightChild);
}

root_bst insertBST(root_bst root, data_t x){
    node_bst* newNode = makeNode(x);
    if(root == NULL){
        return newNode;
    }
    int c = strcmp(x.lop, root->inf.lop);
    if(c == 0){
        return root; //If x has been added

    }else if(c < 0){
        root->leftChild = insertBST(root->leftChild, x);
        return root;
    }else if(c > 0){
        root->rightChild = insertBST(root->rightChild, x);
        return root;
    }
}


root_bst find_bst(root_bst root, data_t x){
    if(root == NULL)
        return NULL;
    int c = strcmp(x.lop, root->inf.lop);
    if(c == 0){
        return root;

    }else if(c < 0){
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

    info_s thongtin;

    char cmd[20];
    int u;
    while(1){
        scanf("%s", cmd);

        if(strcmp(cmd, "insert") == 0){
            char lop[10];
            char room[9];
            scanf("%s", lop);
            strcpy(thongtin.lop, lop);
            scanf("%s", room);
            strcpy(thongtin.phong, room);

            root = insertBST(root, thongtin);

        }else if(strcmp(cmd, "inOrder") == 0){
            root_bst p = findMax(root);
                p->inf.lop[9] = '!';
                p->inf.lop[10] = '\0';
                
            inOrder(root);

        }

    }
    //printf("%d\n", findRight(find_bst(root, 3))->inf);





    //TEST FREETREE
    freeTree(root);
    root = NULL; //Sau khi Free phai gan lai NULL

    return 0;

}
