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
    ListNode* partition(ListNode* head, int x) {
        if(!head || x<=INT_MIN)
            return head;
        ListNode * pre, *curr,*tmp;
        ListNode dummy(-1);
        dummy.next=head;
        pre=&dummy;
        while(pre->next && pre->next->val <x)
            pre=pre->next;
        curr=pre;
        while(curr->next){
            if(curr->next->val<x){
                tmp=curr->next;
                curr->next=curr->next->next;
                tmp->next=pre->next;
                pre->next=tmp;
                pre=pre->next;
            }else{
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};
