/*
  * Linked list basic program which does
  * 1. List node insert
  * 2. List node delete
  * 3. List display
 */

#include "stdio.h"
#include "malloc.h"

typedef struct node{
    int data;
    struct node *next;
}node;

node *
newnode(int data)
{
    node *tmp = NULL;
    tmp = malloc(sizeof(node));
    
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

node *
insert(int data, node *root)
{
    node *tmp;
    if(root == NULL)
        return newnode(data);

    if(root->next == NULL)
    {
        root->next = newnode(data);
        return root;
    }
    
    tmp = root;
    while(tmp)
    {
        if(tmp->next)
        tmp= tmp->next;
        else
        break;
    }
    tmp->next = newnode(data);
    return root;
}

void
display(node *root)
{
    node *tmp = root;
    while(tmp){
        printf("%d  ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return;
}

node *
delete(int data, node *root)
{
    node *tmp = NULL,*tmp1 = NULL,*tmp_prev=NULL;
    tmp = root;
    
    if(root == NULL)
        return NULL;
    
    if(root->next == NULL){
        if(data == root->data){
            free(root);
            return NULL;
        }
        printf("\nNode doesnt exist");
        return root;
    }
    
    tmp_prev = tmp;
    while(tmp)
    {
        if(tmp->data == data){
            if(tmp->next != NULL)
                tmp1 = tmp->next;
            else {
                /*deletion of last node*/
                tmp_prev->next = NULL;
                free(tmp);
                tmp = NULL;
                return root;
            }
            
            if(tmp == root){
                free(tmp);
                tmp = NULL;
                return tmp1;
            }
            
            tmp_prev->next = tmp1;
            free(tmp);
            tmp = NULL;
            return root;
        }
        
        tmp_prev = tmp;
        tmp = tmp->next;
    }
}

int main()
{
    node *root = NULL;
    
    root = insert(10,root);
    root = insert(20,root);
    root = insert(30,root);
    root = insert(40,root);
    root = insert(50,root);
    
    display(root);
    
    root = delete(10,root);
    display(root);
    root = delete(50,root);
    display(root);
    root = delete(30,root);
    display(root);
    root = delete(20,root);
    display(root);
    root = delete(40,root);
    display(root);
    return 1;
}
