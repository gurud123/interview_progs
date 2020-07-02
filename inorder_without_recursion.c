#include <stdio.h>
#include "malloc.h"
typedef struct btree {
    int data;
    struct btree *left;
    struct btree *right;
}btree;

btree *stack[100];
int count=0;

int min(int x, int y){
    return (x < y)?x:y;
}

btree *
newnode(int data)
{
    btree *tmp = NULL;
    
    tmp = (btree *)malloc(sizeof(btree));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

btree *
addnode(int data, btree *root)
{
    btree *tmp = NULL;
    
    if(root == NULL)
        return newnode(data);
        
    if(data < root->data){
        root->left = addnode(data, root->left);
    }
    else if(data > root->data){
        root->right = addnode(data, root->right);
    } else {
        printf("\nError:Duplicate entry");
    }
}

void
inorder(btree *root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
    return;
}

int
is_bst(btree *root, int *prev)
{
    int res1=0, res2=0;
    if(root == NULL)
        return 1;
        
    if(root->left)
        res1 = is_bst(root->left, prev);
    
    if(prev > root->data)
        return -1;
    else 
        prev = root->data;
        
    if(root->right)
        res2 = is_bst(root->right, prev);
        
    return min(res1, res2);
}

int
print_bst_wo(btree *root)
{
    btree *tmp = NULL;
    int count=0;
    if(root == NULL)
        return 0;
        
    tmp = root;
    while(1){
        if(tmp){
            stack[count]=tmp;
            count++;
            tmp = tmp->left;
        }
        else {
            if(count > 0) {
            count--;
            tmp = stack[count];
            printf("%d  ",tmp->data);
            tmp = tmp->right;
            } else 
            break;
        }
    }
    
    return 0;
}

int main()
{
    int val = 0;
    btree *root = NULL;
    /*root = addnode(10,root);
    root = addnode(12,root);
    root = addnode(8,root);
    root = addnode(15,root);
    root = addnode(5,root);*/
    /*
            4
        1       5 
    0     2    3  6  
    
    
    
    
    */
    root = newnode(4);
    root->left = newnode(1);
    root->right = newnode(5);
    root->left->left = newnode(0);
    root->left->right = newnode(2);
    root->right->left = newnode(3);
    root->right->right = newnode(6);
    inorder(root);
    
    val = print_bst_wo(root);
    
    return 0;
}