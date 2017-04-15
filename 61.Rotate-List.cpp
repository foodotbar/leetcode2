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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
            return head;
        int length=1;
        ListNode* curr=head;
        while(curr->next){
            length++;
            curr=curr->next;
        }
        curr->next=head;
        int idx=length-k%length;
        for(int i=0;i<idx;i++){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};

/*

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
            return head;
        int length=0;
        ListNode* curr=head;
        while(curr){
            length++;
            curr=curr->next;
        }
        ListNode *slow=head,*fast=head;
        for(int i=0;i<k%length;i++)
            fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};

*/
