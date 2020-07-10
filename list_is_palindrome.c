/*Check if a given linked list is palindrome or not */
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


node *
stack_add(int data, node *s_root)
{
    node *tmp=NULL, *tmp_head=NULL;
    
    if(s_root == NULL){
        return newnode(data);
    }
    
    tmp_head = s_root;
    tmp = newnode(data);
    tmp->next = tmp_head;
    return tmp;
}

node *
stack_pop(node *s_root, int *val)
{
    node *tmp = NULL;
    if(s_root == NULL){
        printf("\n Stack is Empty.\n");
        *val = -1;
        return NULL;
    }
    
    tmp = s_root->next;
    *val = s_root->data;
    free(s_root);
    return tmp;
}

int
check_palindrome(node *root)
{
    /*
     * To check if its a palindrome, lets create a stack and store
     * all the elements of list into it in first pass.
     * In second pass, we pop each element from stack and compare
     * against each node of a list.
     */
    node *stack_root = NULL;
    node *tmp = root;  
    int val;
     
    while(tmp){
        stack_root = stack_add(tmp->data, stack_root);
        tmp = tmp->next;
    }
    
    tmp = root;
    while(tmp)
    {
        val = -1;
        stack_root = stack_pop(stack_root, &val);
        if((val != -1) && (val != tmp->data)){
            return -1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int main()
{
    node *root = NULL;
    int pal = -1;
    
    root = insert(10,root);
    root = insert(20,root);
    root = insert(30,root);
    root = insert(40,root);
    root = insert(10,root);
    
    display(root);
  
    pal = check_palindrome(root);
    printf("\nThe give list is %s\n",(pal == 0)?"Palindrome":"Not a Palindrome");
    return 0;
}
