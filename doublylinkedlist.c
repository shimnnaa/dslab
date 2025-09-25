#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node*prev;
	struct Node*next;
};
struct Node*head=NULL;
struct Node*createNode(int data){
	struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}
void insertAtBeginning(int data){
	struct Node*newNode=createNode(data);
	if(head!=NULL){
		newNode->next=head;
		head->prev=newNode;
	}
	head=newNode;
	printf("inserted %d at beginning\n",data);
}
void insertAtEnd(int data){
	struct Node*newNode=createNode(data);
	if(head==NULL){
		head=newNode;
	}else{
		struct Node*temp=head;
		while(temp->next!=NULL);
		temp=temp->next;
		temp->next=newNode;
		newNode->prev=temp;
	}
	printf("inserted %d at end \n",data);
}
void deleteNode(int key){
	struct Node*temp=head;
	while(temp !=NULL && temp->data!=key)
		temp=temp->next;
	if (temp==NULL){
		printf("node %d not found!\n",key);
		return;
	}
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	else
		head=temp->next;
	if(temp->next!=NULL)
		temp->next->prev=temp->prev;
	free(temp);
	printf("deleted node %d\n",key);
}
void display(){
	struct Node*temp=head;
	if(temp==NULL){
		printf("list is empty!\n");
return;
	}
	printf("doubly linked list:");
	while(temp!=NULL){
		printf("%d<->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main(){
	int choice,data;
	while(1){
		printf("\n---doubly linked list menu---\n");
		printf("1.inserted at beginning\n");
		printf("2.inserted at end\n");
		printf("3.delete a node\n");
		printf("4.display\n");
		printf("5.exit\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch (choice){
case 1:
			printf("enter data:");
			scanf("%d",&data);
			insertAtBeginning(data);
			break;
case 2:
			printf("enter data:");
			scanf("%d",&data);
			insertAtEnd(data);
			break;
case 3:
			printf("enter node value to delete:");
			scanf("%d",&data);
			deleteNode(data);
			break;
case 4:
			display();
                        break;
case 5:
			exit(0);	
default:
			printf("invalid choice!\n");		}
	}
	return 0;
}


	

