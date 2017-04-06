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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(INT_MIN);
        dummy.next=head;
        ListNode *p=&dummy, *q=&dummy;
        for(int i=0;i<n;i++)
            p=p->next;
        while(p->next!=nullptr){
            q=q->next;
            p=p->next;
        }
        ListNode *tmp=q->next;
        q->next=q->next->next;
        delete tmp;
        return dummy.next;
    }
};
