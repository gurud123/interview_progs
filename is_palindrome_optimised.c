#include "stdio.h"
#include "malloc.h"

/**
 * Definition for singly-linked list.
 */ 
 struct ListNode {
      int val;
      struct ListNode *next;
 };

int isPalindrome(struct ListNode* head){
    struct ListNode *tmp, *tmp1, *tmp2, *slow, *fast, *head2 = NULL;
    int len;
    short int even = 0;
    if(head == NULL)
        return 1;
    
    if(head->next == NULL)
        return 1;
    
    len = 0;
    slow = fast = head;
    
    while(fast){
        
        if(fast->next == NULL) {
            even = 0;
            break;
        }
        if(fast->next->next)
            fast = fast->next->next;
        else {
            even = 1;
            break;
        }
        slow = slow->next;
    }
    
    if((fast == slow) && (fast == head)){
        if(fast->next->val == head->val)
            return 1;
        else
            return 0;
    }
    
    if(even == 0){
        tmp = malloc(sizeof(struct ListNode));
        tmp->val = slow->val;
    }
    
    tmp1 = tmp2 = NULL;
    /*reverse the second half of the linked list */
    tmp1 = slow->next;
    slow->next = NULL;
    
    if(even == 0){
        tmp->next = NULL;
    } else {
        tmp= tmp1;
        tmp1 = tmp1->next;
    }
    
    tmp2 = NULL;
    
    if(tmp1->next)
        tmp2 = tmp1->next;
    
    while(tmp1){
        tmp1->next = tmp;
        tmp = tmp1;
        
        if(tmp2)
            tmp1 = tmp2;
        else {
            head2 = tmp1;
            break;
        }
        
        if(tmp2->next){
            tmp2 = tmp2->next;
        } else {
            tmp1->next = tmp;
            head2 = tmp1;
            break;
        }
    }
    
    while(head && head2){
        if(head->val != head2->val){
            return 0;
        }
        head = head->next;
        head2 = head2->next;
    }
    return 1;
}

struct ListNode *
newnode(int data){
    struct ListNode *tmp = NULL;
    tmp = malloc(sizeof(struct ListNode));
    tmp->val = data;
    tmp->next = NULL;
    return tmp;
}


int main()
{
    struct ListNode *root = NULL;
    int res;
    root = newnode(1);
    root->next = newnode(2);
    root->next->next = newnode(2);
    root->next->next->next = newnode(2);
    root->next->next->next->next = newnode(1);
    
    res = isPalindrome(root);
    printf("\nValue is %s",(res==0)?"false":"true");
    
    return 0;
}
