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
      printf("2d�� �����Է�>", count);
      key=getch();
      add_node(key);
      printf("%c \n", key);
   }while(key != 27);
   
   printf("\n\n");
   printf("�Էµ� ���� : ");
   print_linked_list(head->link);
   printf("�Է��� ���� : ");
   print_reverse_linked_list(head->link);
   printf("\n");
   return 0; 
}

void add_node(char data)
{
   struct linked_list *new_node, *last;
   
   last=head;
   while(last->link != NULL)   // ������ ��带 ã��
   last=last->link;

   new_node=(struct linked_list*)malloc(sizeof(struct linked_list)); //�����Ҵ�
   new_node->data=data;   // �� ��� ������ �Է�
   new_node->link=last->link;  // �� ��� ��ũ�� NULL �Է�
   last->link=new_node;      // ������ ���� �� ��带 ����
}

void print_linked_list(struct linked_list *now)
{
   while(now != NULL){   
     printf("%c ", now->data); 
   now=now->link;      // ������ ����
   }
   printf("\n"); 
}

void print_reverse_linked_list(struct linked_list *now)
{
  if(now->link != NULL){   
     print_reverse_linked_list(now->link);   // ��� �Լ� �̿� - stack
     printf("%c ", now->data); 
  }
  else
   printf("%c ", now->data); 
}
