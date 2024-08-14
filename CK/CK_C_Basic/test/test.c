#include<stdio.h>
#include<stdlib.h>

typedef double data_t;

void swap(data_t *x, data_t *y) {
  data_t tmp = *x;
  *x = *y;
  *y = tmp;
}

void insertion_Sort(data_t arr[], int size){
    int i,j;
    data_t next;
    for(i = 0 ; i < size ; ++i){
        next = arr[i];
        for(j = i - 1 ; j >= 0 && next < arr[j] ; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = next;

    }

}

void selection_Sort(data_t arr[], int size){
    int min_index, i, j;

    for(i = 0 ; i < size - 1 ; ++i ){
        min_index = i;
        for(j = i + 1; j < size ; ++j){
            if(arr[j] < arr[min_index])
                min_index = j; //Save min index of arr
        }
        //SWAP
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

void _quicksort(data_t list[], const int left, const int right) {
  int pivot, i, j;
  if (left < right) {
    i = left;
    j = right+1;
    pivot = list[right];  // <=== Chọn pivot
    do {
      do i++;
      while (list[i] < pivot);
      do j--;
      while (list[j] > pivot);
      if (i < j) swap(&list[i], &list[j]);
    } while (i < j);
    swap(&list[left], &list[j]);
    _quicksort(list, left, j - 1);
    _quicksort(list, j + 1, right);
  }
}

void quickSort(data_t lst[], const int n) {
  _quicksort(lst, 0, n - 1);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int partition(data_t arr[],int low,int high)
{
  //choose the pivot

    data_t pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);

  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}

// The Quicksort function Implement

void quickSortver2(data_t arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot

    int pi = partition(arr,low,high);

    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSortver2(arr,low,pi-1);
    quickSortver2(arr,pi+1,high);
  }
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
  int max = i;
  if(l < n && lst[l] > lst[max])
        max = l;
  if(r < n && lst[r] > lst[max])
        max = r;
  if(max != i) {
    // swap(lst, i, m);
    swap(&lst[i], &lst[max]);
    correctHeapNode(lst, n, max);
  }
}



int main(){
    int n;
    scanf("%d", &n);
    int size = n;
    data_t arr[size];
    int i;
    for(i = 0 ; i < size; ++i){
        scanf("%lf", &arr[i]);
        // printf("IN: %.2lf\n", arr[i]);
    }

    // insertion_Sort(arr, n);
    // selection_Sort(arr, size);
    //quickSortver2(arr, 0 ,size-1);
    // qsort(arr, size, sizeof(data_t), cmpfunc);

    heapSort(arr,size);
    for(i = 0 ; i < size; ++i){
        printf("%.2lf\n", arr[i]);
    }

    return 0;
}
