/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *p=head;
        while(prev!=nullptr&&p!=nullptr){
            if(p->val==val){
                ListNode* tmp=p;
                prev->next=p->next;
                p=p->next;
                delete tmp;
            }else{
                prev=p;
                p=p->next;
            }
        }
        return dummy.next;
    }
};

/***********************
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
**********************/

/********************
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **ptr = &head;
        while(*ptr != nullptr){
            if((*ptr)->val == val){
                *ptr = (*ptr)->next;
            }else{
                ptr=&((*ptr)->next);
            }
        }
        return head;
    }
};
*********************/
