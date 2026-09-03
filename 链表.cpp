#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node*next;
}Node;
void tailInsert(Node**head,int val){
	Node*newNode=(Node*)malloc(sizeof(Node));
	newNode->data=val;
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node*p=*head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=newNode;
}
void printList(Node*head){
	Node*p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void delNode(Node**head,int val){
	if(*head==NULL)
		return;
	Node*p=*head;
	Node*pre=NULL;
	while(p!=NULL&&p->data!=val){
		pre=p;
		p=p->next;
	}
	if(p==NULL){
		return;
	}
	if(pre==NULL){
		*head=p->next;
	}else{
		pre->next=p->next;
	}
	free(p);
}
int main() {
    Node *head = NULL;

    tailInsert(&head, 10);
    tailInsert(&head, 20);
    tailInsert(&head, 30);
    tailInsert(&head, 40);

    printf("原链表：");
    printList(head);

    delNode(&head, 20);
    printf("删除20后：");
    printList(head);

    delNode(&head, 10);
    printf("删除头10后：");
    printList(head);

    delNode(&head, 40);
    printf("删除尾40后：");
    printList(head);

    return 0;
}































