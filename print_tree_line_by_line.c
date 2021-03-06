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
print_level()
{
    btree *tmp_stack[20], *tmp;
    int c=0,i;
    i=0;
    while(count > 0)
    {
        tmp = stack[i];
        if(tmp->left)
            tmp_stack[c++] = tmp->left;
        if(tmp->right)
            tmp_stack[c++] = tmp->right;
        printf("%d ",tmp->data);
        stack[i] = NULL;
        count--;
        i++;
    }
    i=0;
    tmp = NULL;
    while(i < c)
    {
        stack[i] = tmp_stack[i];
        i++;
    }
    count = i;
    return;
}
void
print_each_level(btree *root)
{
    btree *tmp_stack[20], *tmp;
    
    tmp = root;
    if(tmp == NULL)
        return;
    
    printf("\n%d\n ",tmp->data);
    if(tmp->left)
        stack[count++] = tmp->left;
    if(tmp->right)
        stack[count++] = tmp->right;
        
    while(count > 0)
    {
        print_level();
        printf("\n");
    }
    return;
        
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
    
    print_each_level(root);
    return 0;
}
