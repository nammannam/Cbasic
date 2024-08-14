#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char email[21];
} Student;

typedef Student data_t;

int compare(const void *a, const void *b) {
    return strcmp(((Student*)a)->email, ((Student*)b)->email);
}

void buildHeap(data_t lst[], const int n);
void correctHeapNode(data_t lst[], const int n, const int i);

void heapSort(data_t lst[], const int n) {
  buildHeap(lst, n);

  for (int i = n; i > 1; i--) {
    swap(&lst[0], &lst[i - 1]);
    correctHeapNode(lst, i - 1, 0);
  }
}

void buildHeap(data_t lst[], const int n) {
  for (int i = (n / 2); i >= 0; i--) correctHeapNode(lst, n, i);
}

void correctHeapNode(data_t lst[], const int n, const int i) {
  const int l = i * 2 + 1;
  const int r = l + 1;
  int m = i;
  int c = strcmp(lst[]->email)
  if (l < n && lst[l] > lst[m]) m = l;
  if (r < n && lst[r] > lst[m]) m = r;
  if (m != i) {
    // swap(lst, i, m);
    swap(&lst[i], &lst[m]);
    correctHeapNode(lst, n, m);
  }
}

int main() {
    int n;
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &students[i].id, students[i].email);
    }

    qsort(students, n, sizeof(Student), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", students[i].id, students[i].email);
    }

    return 0;
}