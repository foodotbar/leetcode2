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
    ListNode* sortList(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return head;
        ListNode *pre=head,*fast=head,*slow=head;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        return merge(sortList(head),sortList(slow));
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1)
            curr->next=l1;
        if(l2)
            curr->next=l2;
        return dummy->next;
    }
};


/*

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return head;
        ListNode *pre=head,*fast=head,*slow=head;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        return merge(sortList(head),sortList(slow));
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) 
            return l2;
        if(!l2)
            return l1;
        if(l1->val < l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }
};

*/
