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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = head;
        while(p != nullptr && p->next != nullptr){
            ListNode* tmp = p->next;
            if(p->val == p->next->val){
                p->next = p->next->next;
                delete tmp;
            }else{
                p = p->next;
            }
        }
        return dummy.next;
    }
};


/**********
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while(p != nullptr && p->next != nullptr){
            ListNode* tmp = p->next;
            if(p->val == p->next->val){
                p->next = p->next->next;
                delete tmp;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};
***********/

/*******
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur){
            while(cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur=cur->next;
            }
        return head;
    }
};
************/
