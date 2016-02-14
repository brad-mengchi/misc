#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM	10

struct tree {
	double val;
	struct tree *right;
	struct tree *left;
};

int insert_node(struct tree **root, double num) {
	if ((*root) == NULL) {
		(*root) = (struct tree*)malloc(sizeof(struct tree));
		(*root)->val = num;
		printf("try to assign %.3f\n", num);
		return 0;
	} else {
		if (num > (*root)->val) {
			insert_node(&((*root)->right), num);
		} else if (num < (*root)->val) {
			insert_node(&((*root)->left), num);
		} else {
			printf("same value! %.3f\n", num);
		}
		return 0;
	}
}

int process(struct tree *p) {
	printf("%.3f\n", p->val);
	return 0;
}

int inorder(struct tree *p) {
	if (p->left)
		inorder(p->left);
	process(p);
	if (p->right)
		inorder(p->right);
	return 0;
}

int main(){
	struct tree *head = NULL;
	int i;
	double num;
	for (i = 0; i < MAX_NUM; i++) {
		num = (rand() % 100) / 100.0;
		insert_node(&head, num);
	}
	inorder(head);
	return 0;
}
