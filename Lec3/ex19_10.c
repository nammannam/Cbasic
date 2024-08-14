#include<stdio.h>

typedef int data_t;

typedef struct node_s{
    data_t data;
    struct node_s *prev;
    struct node_s *next;
}node_t, *root_t;

node_t *createNewNode(const data_t data){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL)
        return NULL;
        
    newNode->data = data;
    

}

int main(){



}