/*
* Filename:	main.c
* Date:		16/11/2024
* Name:		EL Joubert
*
* Simple binary tree to showcase "sorting", in-order, pre-order and post-order traversal
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
		int data;
		struct TreeNode * left;
		struct TreeNode * right;
};

void add_to_tree(TreeNode * root, TreeNode * new_node);
void free_tree(TreeNode * root);
void print_tree_in_order(); // TODO
void print_tree_pre_order(); // TODO
void print_tree_post_order(); // TODO

TreeNode * make_node(int value) {
    TreeNode * node = malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
		TreeNode * root = make_node(5);
		TreeNode * branch1 = make_node(3);
		TreeNode * branch2 = make_node(7);
        TreeNode * node3 = make_node(4);
        TreeNode * node4 = make_node(9);

		add_to_tree(root, branch1);
		add_to_tree(root, branch2);
		add_to_tree(root, node3);
		add_to_tree(root, node4);

		printf("root: %d\n", root->data);
		printf("branch1: %d\n", branch1->data);
		printf("branch2: %d\n", branch2->data);

        //       5
        //  3         7
        //    4         9
        print_tree_in_order(root);
        printf("\n");
        print_tree_pre_order(root);
        printf("\n");
        print_tree_post_order(root);


		free_tree(root);

		return 0;
}

void add_to_tree(TreeNode * root, TreeNode * new_node) {
		if (root->data < new_node->data) {
				if (root->right == NULL) {
						root->right = new_node;
				} else {
						add_to_tree(root->right, new_node);
				}
		} else //root->data >= new_node
		{
				if (root->left == NULL) {
						root->left = new_node;
				} else {
						add_to_tree(root->left, new_node);
				}
		}
}
void free_tree(TreeNode * root) {
    // Post order
		if (root != NULL) {
				free_tree(root->left);
				free_tree(root->right);

				free(root); // stuff done here
		}
}

void print_tree_in_order(TreeNode * root) {
    if (root != NULL) {
        print_tree_in_order(root->left);
        printf(" %d", root->data); // do stuff
        print_tree_in_order(root->right);
    }
}

void print_tree_pre_order(TreeNode * root) {
    if (root != NULL) {
        printf(" %d", root->data); // do stuff
        print_tree_pre_order(root->left);
        print_tree_pre_order(root->right);
    }
}

void print_tree_post_order(TreeNode * root) {
    if (root != NULL) {
        print_tree_post_order(root->left);
        print_tree_post_order(root->right);
        printf(" %d", root->data); // do stuff
    }
}
