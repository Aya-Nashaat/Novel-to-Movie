/* 
 * File:   binarySearchTree.c
 * Author: abdallah
 *
 * Created on February 12, 2019, 3:31 AM
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * bigchild, * smallchild;
	int val;
};
// Create a new node to the tree.
struct node * newNode(int value){
	struct node * n = (struct node *)malloc(sizeof(struct node));
	n->val = value;
	n->bigchild = n->smallchild = NULL;
	return n;
}
// insert the child node to the root node in a correct manner to maintain the binary search tree rules.
void insert(struct node ** root, struct node * child){ // the ** in order to preserve the value of the root not to loose it while moving inside its children as there is no back pointers from the children to their parent.
    printf("Inserting ...!\n");
	if(*root == NULL){ 
            *root = child;  // tree root not exists
        }
	else if((*root)->val >= child->val)
            insert(&(*root)->smallchild, child); 	  // child value is minor/equal to current node value, call insertion on left node	
	else
            insert(&(*root)->bigchild, child); 	  // child value is more than the current node value, call insertion on right node	
}

// search the root node and its children for a given value.
int numComparisons = 0;
struct node * search(struct node * root, int value){	
        if(root == NULL)
                return NULL;  		         // node not found
        else if (root->val == value){
                return root; 		         // first node address found
                numComparisons++;
        }
        else if(value > root->val){
                search(root->bigchild,value);	     // recursive search on right side of tree
                numComparisons++;
        }
        else{
                search(root->smallchild,value);       // recursive search on left side of tree
                numComparisons++;
        }
}

// print the tree nodes' values and their hight in the tree.
int level = 1;
void output(struct node * root){
    if(root == NULL)
        return; // empty subtree.
    int i;
    for (i = 0; i < level; i++) {
        printf("*"); // * indicates the tree hight.
    }
    printf("value = %d\n", root->val);
    level++; // as i shall move to the next level (the children level).
    output(root->smallchild);
    output(root->bigchild);
    level--; // as i am returning back to the parent level.
}

int main(int argc, char** argv) {
    // Constructing the tree from the user's input.
    struct node * rootptr = NULL;    
    struct  node * child=NULL;
    int num = 0;
    while(1){        
        printf("Please, enter a new positive integer value to store or a negative value to end the input process:\n");
        scanf("%d", &num);
        if(num < 0)
            break;
        child = newNode(num);
        insert(&rootptr, child);        
    }
    // display the tree.
    output(rootptr);
    // ask the user for a value to search for it on the tree.
    printf("Now, enter a value to search for it in the tree:\n");
    int v=-1;
    scanf("%d", &v);  
    // the searching process.
    struct node * found = search(rootptr, v);
    if(found == NULL)
        printf("%d not found in the tree!!\n", v);
    else
        printf("I found it with %d comparisons :) \n", numComparisons);
    
    return 0;
}