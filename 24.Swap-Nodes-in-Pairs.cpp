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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode dummy(0);
        ListNode *p=&dummy;
        dummy.next=head;
        
        while(p&&p->next&&p->next->next){
            ListNode *n=p->next;
            ListNode *nn=p->next->next;
            p->next=nn;
            n->next=nn->next;
            nn->next=n;
            p=p->next->next;
        }
        return dummy.next;
    }
};
