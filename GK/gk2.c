#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct node
{
    char time[20];
    char plate[50];
    struct node* next;
}node, *root_t;
 
root_t createnewNode(char time[],char plate[]){
     root_t p = (root_t)malloc(sizeof(node));
     strcpy(p->time,time);
     strcpy(p->plate,plate);
     p->next = NULL;
     return p;
}
 
root_t llInsertTail(root_t root,char time[],char plate[]) {
  root_t pNewNode = createnewNode(time,plate);
  if (root == NULL) return (root_t)pNewNode;
  root_t p = root;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}
 
root_t llDeleteAfter(root_t root,char mau[]) {
      root_t p_run = root;
    for (p_run = root;p_run != NULL;p_run = p_run->next)
    {
        if (strcmp(p_run->next->plate,mau) == 0)
        {
            break;
        }
       
    }
  root_t pA = p_run;
  root_t pToDelElem = pA->next;
  pA->next = pA->next->next;
  free(pToDelElem);
  return root;
}
int check(root_t root,char mau[]){
    root_t p_run = root;
    int check = 0;
    for (p_run = root;p_run != NULL;p_run = p_run->next)
    {
        if (strcmp(mau,p_run->plate) == 0)
        {
            check = 1;
            return check;
        }
    }
    return check;
}
int find(root_t root,char mau[]){
    if (check(root,mau) == 0)
    {
        return -1;
    }
    int tt = 0;
    for (root_t p_run = root;p_run != NULL;p_run= p_run->next)
    {
       
        if (strcmp(p_run->plate,mau)== 0)
        {
           
            break;
        }
      //  printf("%s_find",p_run->plate);
        tt++;
    }
    return tt;
}
int cnt_bicycle(root_t root){
    int cnt = 0;
    for (root_t p_run = root;p_run != NULL;p_run= p_run->next)
    {
        if (p_run->plate[0] == 'x')
        {
            cnt++;
        }
    }
    return cnt;
}
int check_out(root_t root,char mau[]){
    if (check(root,mau) == 1 || check(root, mau) != 1)
    {
        return -1;
    }
    return 0;
}
 
void llPrint(root_t root){
  //  root_t p_run = root;
    for (root_t p_run = root;p_run != NULL;p_run = p_run->next)
    {
        printf("%s\n",p_run->plate);
    }
}
int main(){
    root_t root = NULL;
    root_t root2 = NULL;
    char time[50];
    char plate[50];
    char checkEnd[50];
    do {
        scanf("%s", checkEnd);
        if(strcmp(checkEnd, "*") == 0) break;
        strcpy(time,checkEnd);
        scanf("%s",plate);
        root = llInsertTail(root,time,plate);
        root2 = llInsertTail(root2,time,plate);
    } while(1);
    fflush(stdin);
    char temp[100];
    char temp_plate[100];
    char temp_time[100];
    do {
       scanf("%s",temp);
       if (strcmp(temp,"***") == 0)
       {
          break;
       }
       if (strcmp(temp,"list") == 0){
          llPrint(root);
       }
       else if (strcmp(temp,"in") == 0){
          scanf("%s",temp_time);
          scanf("%s",temp_plate);
          root2 = llInsertTail(root2,temp_plate,temp_time);

          if (check(root,temp_plate) == 0)
          {
              root = llInsertTail(root,temp_time,temp_plate);
              printf("1\n");
          }
          else
          {
             printf("0\n");
          }
         
       }
       else if (strcmp(temp,"out") == 0)
       {
          scanf("%s",temp_time);
          scanf("%s",temp_plate);
          if (check(root,temp_plate) == 1)
          {
              root = llDeleteAfter(root,temp_plate);
              printf("1\n");
          }
          else
          {
              printf("0\n");
          }  
       }
       else if (strcmp(temp,"find") == 0){
  
          scanf("%s",temp_plate);
     
        int f = find(root,temp_plate);
          printf("%d\n",f);
       }
       else if (strcmp(temp,"cnt-bicycle") == 0){
          printf("%d\n",cnt_bicycle(root));
       }
       else if (strcmp(temp,"has-checkout") == 0){
          scanf("%s",temp_plate);
        
          int c = check_out(root2,temp_plate);
          printf("%d\n",c);
       }
   
    } while(1);

    return 0;
}