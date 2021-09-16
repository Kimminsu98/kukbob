#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 

struct linked_list
{
   char data;
   struct linked_list *link;
};
struct linked_list *head;

void add_node(char data);
void print_linked_list(struct linked_list *now);
void print_reverse_linked_list(struct linked_list *now);

int main(void){
   int count=0;
   char key;
   head = (struct linked_list*)malloc(sizeof(struct linked_list));
   head->link = NULL;
   do
   {
      count++;
      printf("2d번 문자입력>", count);
      key=getch();
      add_node(key);
      printf("%c \n", key);
   }while(key != 27);
   
   printf("\n\n");
   printf("입력된 순서 : ");
   print_linked_list(head->link);
   printf("입력의 역순 : ");
   print_reverse_linked_list(head->link);
   printf("\n");
   return 0; 
}

void add_node(char data)
{
   struct linked_list *new_node, *last;
   
   last=head;
   while(last->link != NULL)   // 마지막 노드를 찾음
   last=last->link;

   new_node=(struct linked_list*)malloc(sizeof(struct linked_list)); //동적할당
   new_node->data=data;   // 새 노드 데이터 입력
   new_node->link=last->link;  // 새 노드 링크에 NULL 입력
   last->link=new_node;      // 마지막 노드와 새 노드를 연결
}

void print_linked_list(struct linked_list *now)
{
   while(now != NULL){   
     printf("%c ", now->data); 
   now=now->link;      // 앞으로 전진
   }
   printf("\n"); 
}

void print_reverse_linked_list(struct linked_list *now)
{
  if(now->link != NULL){   
     print_reverse_linked_list(now->link);   // 재귀 함수 이용 - stack
     printf("%c ", now->data); 
  }
  else
   printf("%c ", now->data); 
}
