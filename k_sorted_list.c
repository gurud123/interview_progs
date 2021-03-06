/*
 *Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Example:

 *Input:
 *[
 * 1->4->5,
 * 1->3->4,
 * 2->6
 *]
 * Output: 1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 */
 #include "stdio.h"
 #include "malloc.h"
 
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 

struct ListNode * merge_2_list(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *tmp ,*l1_p, *l2_p, *l1_root;
    short int l2_list_null = 0;
    
    tmp = NULL;
    
    l1_p = l1_root = l1;
    l2_p = l2;
    if(l1_p == NULL){
        return l2;
    }
    if(l2_p == NULL){
        return l1;
    }
    
    if(l1_p->next == NULL){
        if(l1_p->val < l2_p->val){
            l1_p->next = l2_p;
            l1_root = l1_p;
            return l1_root;   
        }
    }

    while((l1_p != NULL) || (l2_p != NULL))
    {
        if(l1_p->val > l2_p->val){
            tmp  = l2_p;
            if(l2_p->next != NULL) {
                l2_p = l2_p->next;
                //l2_p->next = tmp;
            } else {
                l2_list_null = 1;
            }
            if(l1_p == l1){
                tmp->next = l1_p;
                l1_root = tmp;
                l1_p = l1_root;
                if(l2_list_null == 1) {
                    return l1_root;
                }
            }
            
        }
        
        if(l1_p->val == l2_p->val){
            //printf("\nHit the first node\n");
            
            tmp = l2_p;
            if(l2_p->next)
                l2_p = l2_p->next;
            else {
                tmp->next = l1_p->next;
                l1_p->next = tmp;
                return l1_root;
            }
            tmp->next = l1_p->next;
            l1_p->next = tmp;
            //printf("\nInserted tmp_val %d(L2) before L1 %d",tmp->val,l1_p->val);
            l1_p = l1_p->next;
            continue;
        }
        
        if(l2_p->val > l1_p->val){
            if(l1_p->next){
                if(l2_p->val < l1_p->next->val){
                    tmp = l2_p;
                    if(l2_p->next){
                        l2_p = l2_p->next;
                    } else {
                        l2_list_null = 1;
                    }
                        
                    tmp->next = l1_p->next;
                    l1_p->next = tmp;
                    l1_p = l1_p->next;
                    if(l2_list_null == 1){
                        return l1_root;
                    } else {
                        continue;
                    }
                }
                
                if(l2_p->val >= l1_p->next->val){
                    l1_p = l1_p->next;
                    continue;
                }
            }
        }
        if(l1_p->next)
            l1_p = l1_p->next;
        else{
            l1_p->next = l2_p;
            return l1_root;
        }
    }
    
    if(l2_p){
        if(l1_p->next == NULL){
            l1_p->next = l2_p;
            return l1_root;
        }
    }
    return l1_root;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *l1, *l2;
    int i=0;
    
    if(listsSize == 0)
        return NULL;
    
    if(lists == NULL){
        return NULL;
    }
    
    l1 = l2 = NULL;
    l1 = lists[i];
    i++;
    while(i < listsSize){
        l2 = lists[i];
        printf("\ncalling merge_2_lists\n");
        l1 = merge_2_list(l1, l2);
        i++;
    }
    return l1;
}

struct ListNode *newnode(int data)
{
    struct ListNode *tmp = NULL;
    tmp = malloc(sizeof(struct ListNode));
    tmp->val = data;
    tmp->next = NULL;
    return tmp;
}

int main()
{
    struct ListNode *p1, *p2, *p3, *pp[3], *ptr = NULL;
    
    p1 = newnode(1);
    p1->next = newnode(4);
    p1->next->next = newnode(5);
    
    /*p2 = newnode(1);
    p2->next = newnode(3);
    p2->next->next = newnode(4);
    
    p3 = newnode(2);
    p3->next = newnode(6);
    */
    p2 = newnode(0);
    p2->next = newnode(2);
    
    pp[0]=p1;
    pp[1]=p2;
    //pp[2]=p3;
    
    ptr = mergeKLists(pp, 2);
    printf("\n\n");
    while(ptr){
        printf("%d\t",ptr->val);
        ptr=ptr->next;
    }
}
