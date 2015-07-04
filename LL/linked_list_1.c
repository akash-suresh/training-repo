#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *rptr;
};

typedef struct NODE node;

node* new_node(int val){
	node* new1;
	new1 = (node*) malloc (sizeof(node));
	if(new1 == NULL){
		printf("\ninsufficient memory");
		exit(0);
	}
	new1->rptr = NULL;
	new1->data = val;
	return new1;
}

void display(node* root){
	node *temp = root;
	if(temp == NULL){
		printf("\n the linked list is empty");
		return;
	}
	printf("The linked list is root -> ");
	while(temp->rptr!= NULL){
		printf("%d->", temp->data);
		temp = temp->rptr;
	}
	printf("%d -> NULL", temp->data);
	return;
}

node* insert_at_front(node* root){
	int val;
	node* new1;
	printf("\nenter data: ");
	scanf("%d",&val);
	new1 = new_node(val);
	new1->rptr = root;
	root = new1;
	return root;
}

node* insert_at_end(node *root){
	int val;
	node* new1,*temp = root;
	if(root==NULL){
		root = insert_at_front(root);
		return root;
	}
	printf("\nenter data: ");
	scanf("%d",&val);
	new1 = new_node(val);
	while(temp->rptr!=NULL){
		temp =temp->rptr;
	}
	temp->rptr=new1;
	return root;
}

node* delete_at_front(node *root){
	node *temp = root;
	if(root==NULL){
		return root;
	}
	root = temp->rptr;
	free(temp);
	return root;
}

node* delete_at_end(node *root){
	node *temp=root,*prev;
	if(root==NULL || root->rptr==NULL){
		root = delete_at_front(root);
		return root;
	}
	while(temp->rptr!=NULL){
		prev= temp;
		temp=temp->rptr;
	}
	prev->rptr=NULL;
	free(temp);
	return root;
}

node* reverse_list(node *root){
	node *new_root,*temp=root,*x=NULL;

	while(temp!=NULL){
		new_root= temp;
		temp=temp->rptr;
		new_root->rptr=x;
		x = new_root;
	}
	return x;
}
node* insert_split(node *root, node *split_node){

	node *temp = root;
	if(root==NULL){
		root = split_node;
		return root;
	}
	while(temp->rptr!=NULL){
		temp =temp->rptr;
	}
	temp->rptr=split_node;	
	return root;
}
void split(node *root){
	node *new_root=NULL,*temp=root,*root_cnt;
	if(root==NULL || root->rptr==NULL){
		printf("insufficent number of nodes");
		return;
	}
	root_cnt=root;
	while(temp!=NULL){
		temp=temp->rptr;
		if(temp==NULL){
			break;
		}
		root_cnt->rptr=temp->rptr;
		temp->rptr=NULL;
		new_root = insert_split(new_root,temp);
		temp=root_cnt->rptr;
		root_cnt=temp;
	}
	display(root);
	display(new_root);
}
int main(){
	node *root=NULL;
	int choice;
	printf("\nwelcome to the world of linked list");
	while(1){
		printf("\nMenu:\n1.insert at front\n2.insert at the end\n3.delete at front\n4.delete at end \n5.reverse the linked list\n6.split odd and even terms into two ll\nenter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: root = insert_at_front(root);
					display(root);
					break;
			case 2: root = insert_at_end(root);
					display(root);
					break;
			case 3: root = delete_at_front(root);
					display(root);
					break;
			case 4: root = delete_at_end(root);
					display(root);
					break;
			case 5: root = reverse_list(root);
					display(root);
					break;
			case 6: split(root);
					break;
			default:return 0;
		}	
	}
}