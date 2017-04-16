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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode * oddhead=new ListNode(1);
        ListNode * evenhead=new ListNode(2);
        ListNode *step=head;
        ListNode *odd=oddhead;
        ListNode *even=evenhead;
        int cnt=0;
        while(step){
            ++cnt;
            ListNode *next=step->next;
            if(cnt%2==1){
                step->next=odd->next;
                odd->next=step;
                step=next;
                odd=odd->next;
            }else if(cnt%2==0){
                step->next=even->next;
                even->next=step;
                step=next;
                even=even->next;
            }
        }
        odd->next=evenhead->next;
        return oddhead->next;
    }
};


/*

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *odd=head,*even=head->next,*evenhead=even;
        while(even && even->next){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};

*/
