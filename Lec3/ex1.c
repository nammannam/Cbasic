#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int data_t; //Tùy vào kiểu data của Linked list VD: mssv (char), name , ...

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL; //Check if success or not

  newNode->data = data; // Có dữ liệu thì lưu về
  newNode->next = NULL; 
  return newNode;
}

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

void showData(data_t data){
    printf("%d ", data);
}

data_t convert(int n){
    return n;
}

root_t llPrint(root_t root) {
  for(node_t* p = root; p != NULL; p = p->next)
     showData(p->data);
  printf("\n");
  return root;
}

root_t llInit() { return NULL; }

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data); //Create new node

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next) // Scan for last elm
    ;
  p->next = pNewNode; //Sau khi chạy for tới ptu cuối -> trỏ tới ptu vừa tạo new Node
  return root;
}



int main(){
    char input[50] = "0";
    int n;
    
    root_t lst = llInit();
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        int num;
        scanf("%d", &num);

        lst = llInsertTail(lst, convert(num));
    }

    llPrint(lst);
    
    // while(scanf("%s", input), strcmp(input, "#") != 0){
    //     // sscanf(input, %s-%d,   )

    // }
    
      return 0;
}