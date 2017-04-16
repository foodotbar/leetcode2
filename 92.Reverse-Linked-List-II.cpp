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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        n-=m;
        ListNode *prehead=new ListNode(-1);
        prehead->next=head;
        ListNode *pre=prehead;
        while(--m){
            pre=pre->next;
        }
        ListNode *reverseStart=pre->next;
        while(n--){
            ListNode *p=reverseStart->next;
            reverseStart->next=p->next;
            p->next=pre->next;
            pre->next=p;
        }
        return prehead->next;
    }
};


/*

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prehead=new ListNode(-1);
        prehead->next=head;
        ListNode *pre=prehead;
        for(int i=0;i<m-1;i++)
            pre=pre->next;
        ListNode *curr=pre->next;
        for(int i=0;i<n-m;i++){
            ListNode *move=curr->next;
            curr->next=move->next;
            move->next=pre->next;
            pre->next=move;
        }
        return prehead->next;
    }
};

*/
