#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define N   20


typedef struct node_tree 
{
	int data;
	struct node_tree* left;
	struct node_tree* right;
} node_tree;


typedef struct node_stack 
{
	node_tree* node;
	struct node_stack* next;
} node_stack;



// 树
node_tree* init_root();
void con_tree(node_tree* root);
void insert_tree(node_tree* root, node_tree* node);
void show_first(node_tree* root);
void show_mid(node_tree* root);
void show_last(node_tree* root);

void show_first_n(node_tree* root);
void show_mid_n(node_tree* root);
void show_last_n(node_tree* root);


// 栈
node_stack* initStack();
void push_stack(node_stack* head, node_tree* node);
node_tree* pop_stack(node_stack* head);
char is_empty(node_stack* head);
void destory_stack(node_stack* head);



int main(int argc, char const *argv[])
{
	srand(time(0));

	node_tree* root = init_root();
	con_tree(root);

	printf("递归前序   : ");
	show_first(root);
	printf("\n");
	printf("非递归前序 : ");
	show_first_n(root);

	printf("\n");

	printf("递归中序   : ");
	show_mid(root);
	printf("\n");
	printf("非递归中序 : ");
	show_mid_n(root);

	printf("\n");

	printf("递归后序   : ");
	show_last(root);
	printf("\n");
	printf("非递归后序 : ");
	show_last_n(root);

	return 0;
}



// Tree

node_tree* init_root(){
	node_tree* root = NULL;
	root = malloc(sizeof(node_tree));

	if(root == NULL){
		exit(-1);
	}

	root->data = rand() % MAX;
	root->left = NULL;
	root->right = NULL;

	return root;
}


void con_tree(node_tree* root){
	size_t i;
	node_tree* node = NULL;

	for(i = 0; i < N; i++){
		node = malloc(sizeof(node_tree));
		if(node == NULL){
			exit(-1);
		}

		node->data = rand() % MAX;
		node->left = NULL;
		node->right = NULL;

		insert_tree(root, node);
	}
}

void insert_tree(node_tree* root, node_tree* node){
	node_tree* cur = root;

	for(; ;){
		if(node->data < cur->data){		// 左子树
			if(cur->left == NULL){
				cur->left = node;
				break;
			}else{
				cur = cur->left;
			}
		}else{							// 右子树
			if(cur->right == NULL){
				cur->right = node;
				break;
			}else{
				cur = cur->right;
			}
		}
	}
}

void show_first(node_tree* root){
	printf("%d ", root->data);

	if(root->left != NULL)
		show_first(root->left);
	if(root->right != NULL)
		show_first(root->right);
}

void show_mid(node_tree* root){

	if(root->left != NULL)
		show_mid(root->left);

	printf("%d ", root->data);

	if(root->right != NULL)
		show_mid(root->right);
}

void show_last(node_tree* root){

	if(root->left != NULL)
		show_last(root->left);
	if(root->right != NULL)
		show_last(root->right);
	printf("%d ", root->data);

}


void show_first_n(node_tree* root){
	node_stack* stack = initStack();
	node_tree* t_node = NULL;

	push_stack(stack, root);

	while(!is_empty(stack)){
		t_node = pop_stack(stack);

		printf("%d ", t_node->data);

		if(t_node->right != NULL)
			push_stack(stack, t_node->right);
		if(t_node->left != NULL)
			push_stack(stack, t_node->left);
	}

	printf("\n");

	destory_stack(stack);
}

void show_mid_n(node_tree* root){
	node_stack* stack = initStack();
	node_tree* t_node = root;


	while(t_node || !is_empty(stack)){

		while(t_node){
			push_stack(stack, t_node);

			t_node = t_node->left;
		}

		if(!is_empty(stack)){
			t_node = pop_stack(stack);
			printf("%d ", t_node->data);

			t_node = t_node->right ? t_node->right : NULL;
		}
	}

	printf("\n");

	destory_stack(stack);
}

void show_last_n(node_tree* root){

	node_stack* stack = initStack();
	node_tree* cur;
	node_tree* pre = NULL;

	push_stack(stack, root);

	while(!is_empty(stack)){
		cur = stack->next->node;

		if((!cur->left && !cur->right) || 
			(pre && (pre == cur->left || pre == cur->right))){

			printf("%d ", cur->data);
			pop_stack(stack);
			pre = cur;
		}else{
			if(cur->right)
				push_stack(stack, cur->right);

			if(cur->left)
				push_stack(stack, cur->left);
		}
	}

	printf("\n");
	destory_stack(stack);
}





// Stack

node_stack* initStack(){
	node_stack* head = NULL;

	head = malloc(sizeof(node_stack));
	if(head == NULL){
		exit(-1);
	}

	head->node = NULL;
	head->next = NULL;

	return head;
}

void push_stack(node_stack* head, node_tree* node){
	node_stack* s_node = NULL;

	s_node = malloc(sizeof(node_stack));
	if(s_node == NULL){
		exit(-1);
	}

	s_node->node = node;

	s_node->next = head->next;
	head->next = s_node;
}

node_tree* pop_stack(node_stack* head){
	if(is_empty(head)){	// stack empty
		return NULL;
	}

	node_stack* node;
	node_tree* t_node;

	node = head->next;
	head->next = node->next;
	t_node = node->node;

	if(node != NULL){
		free(node);
	}

	return t_node;
}


char is_empty(node_stack* head){
	return head->next == NULL;
}

void destory_stack(node_stack* head){
	while(!is_empty(head))
		pop_stack(head);

	if(head){
		free(head);
	}
}

