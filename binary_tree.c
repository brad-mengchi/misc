#include <stdio.h>
#include <stdlib.h>

#define LAYER	3

struct tree {
	double val;
	struct tree *right;
	struct tree *left;
};

struct tree *initialize(int layer) {
	struct tree *p = NULL;
	p = (struct tree*)malloc(sizeof(struct tree));
	p->val = (rand() % 100) / 100.0;
	if (layer >= LAYER)
		return p;
	p->left = initialize(layer + 1);
	p->right = initialize(layer + 1);
	return p;
}

int process(struct tree *p) {
	printf("%.3f\n", p->val);
	return 0;
}

int preorder(struct tree *p) {
	process(p);
	if (p->left)
		preorder(p->left);
	if (p->right)
		preorder(p->right);
	return 0;
}

int main(){
	struct tree *head;
	head = initialize(1);
	preorder(head);
	return 0;
}
