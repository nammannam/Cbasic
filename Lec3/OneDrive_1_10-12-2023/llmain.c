// https://code.visualstudio.com/docs/cpp/config-linux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

int main() {
  root_t lst = llInit();

  for (int i = 0; i < 5; i++) {
    lst = llInsertTail(lst, convert(i));
    lst = llInsertHead(lst, convert(-i));
  }
  /* 
   0 0
  -1 0 0 1
  ...
  -4 -3 -2 -1 0 0 1 2 3 4
   0  1  2  3 4 5 6 7 8 9  [index]
  */

  llPrint(lst); //In DS

  node_t *p = llSeek(lst, 1); // Trả vè con trỏ trỏ vào -3
  lst = llDeleteAfter(lst, p); // Xóa ptu sau p
  lst = llDeleteHead(lst); // -> -3 -1 0 0 1 2 3 4
  lst = llDeleteTail(lst); // -> -3 -1 0 0 1 2 3

  llPrint(lst);

  lst = llDeleteAll(lst);

  return 0;
}