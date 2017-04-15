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
    bool isPalindrome(ListNode* head) {
        ListNode *walker = head, *runner = head;
        if( head == NULL || head->next == NULL )
            return true;
        while( runner->next != NULL && runner->next->next != NULL ){
            walker = walker->next;
            runner = runner->next->next;
        }
        //reverse the right-half-part-of-list
        walker->next = reverseList(walker->next);
        walker = walker->next; 
        while( walker!= NULL ){
            if( walker->val != head->val ){
                return false;
            }
            head = head->next;
            walker = walker->next;
        }
        return true;    
    }
    
    ListNode* reverseList(ListNode* head) {
        if( head == NULL || head->next == NULL)
            return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

/*

    ListNode* reverseList( ListNode* head ) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }

*/
