class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode* start=new ListNode(head->val -1);
        start->next=head;
        ListNode* pre=start;
        while(pre->next){
            ListNode* curr=pre->next;
            while(curr->next && curr->val==curr->next->val)
                curr=curr->next;
            if(curr !=pre->next )
                pre->next=curr->next;
            else
                pre=pre->next;
        }
        return start->next;
    }
};

/*

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode* p = head->next;
        if(p->val != head->val){
            head->next=deleteDuplicates(p);
            return head;
        }else{
            while(p && p->val== head->val )
                p=p->next;
            return deleteDuplicates(p);
        }
    }
};

*/
