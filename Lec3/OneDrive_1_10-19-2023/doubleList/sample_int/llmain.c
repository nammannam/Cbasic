#include <stdio.h>
#include "dllist.h"

int main() {
  root_t lst = llInit();
  
  for (int i = 0; i < 5; i++) {
    lst = llInsertTail(lst, convert(i));
    lst = llInsertHead(lst, convert(-i));
  }
  llPrint(lst);

  node_t *p = llSeek(lst, 1);
  printf("p = llSeek(lst, 1):\n");
  showNode(p);

  lst = llDeleteAfter(lst, p);
  printf("\n\nDeleteAfter(lst,p):");
  showNode(p);

  lst = llDeleteHead(lst);
  printf("\n\nDeleteHead():");
  llPrint(lst);
  

  lst = llDeleteTail(lst);
  printf("\n\nDeleteTail():");
  llPrint(lst);

  llPrint(lst);

  lst = llDeleteAll(lst);

  return 0;
}