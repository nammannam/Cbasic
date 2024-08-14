#ifndef __LLIST_H__
#define __LLIST_H__

#include <string.h>

// ==================================================================
// Must Adapt to new problem
// ==================================================================
typedef int data_t; //Tùy vào kiểu data của Linked list VD: mssv (char), name , ...

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(const data_t data);
data_t convert(int n);

// ==================================================================

root_t llPrint(root_t root);

root_t llInit(); //Khởi tạo phần tử đầu tiên
node_t *llSeek(root_t root, int index); //Con trỏ trỏ tới phần tử đầu

root_t llInsertHead(root_t root, const data_t data); //Chèn phần tử vào đầu ds liên kết
root_t llInsertTail(root_t root, const data_t data); // Chèn vào cuối
root_t llInsertAfter(root_t root, node_t *pAElem, const data_t data); // Thêm vào sau ptu con trỏ trỏ

// Xóa tương tự trên
root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);
root_t llDeleteAfter(root_t root, node_t *pA);
root_t llDeleteAll(root_t root);

// Tools
int llLength(root_t root);
root_t llReverse(root_t root);

#endif