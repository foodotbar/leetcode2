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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while( l1 != NULL ){
            s1.push( l1->val );
            l1 = l1->next;
        }
        while( l2 != NULL ){
            s2.push( l2->val );
            l2 = l2->next;
        }
        ListNode *ret = new ListNode(-1);
        int sum = 0;
        while( !s1.empty() || !s2.empty() ){
            if( !s1.empty() ){
                sum += s1.top() ;
                s1.pop();
            }
            if( !s2.empty() ){
                sum += s2.top() ;
                s2.pop();
            }
            ret->val = sum%10;
            ListNode *head = new ListNode(sum/10);
            head->next = ret;
            ret = head;
            sum /= 10;

        }
        return ret->val == 0 ? ret->next : ret ;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        ListNode *ret=new ListNode(1);
        ret->next = n1>n2?adder(l1,l2,n1-n2):adder(l2,l1,n2-n1);
        if(ret->next->val>9){
            ret->next->val%=10;
            return ret;
        }
        return ret->next;
    }
    int getLength(ListNode* head){
        int cnt = 0;
        while(head){
            ++cnt;
            head=head->next;
        }
        return cnt;
    }
    ListNode* adder(ListNode* l1, ListNode* l2, int diff){
        if(l1 == NULL) return NULL;
        ListNode* ret = (diff==0)?new ListNode(l1->val+l2->val):new ListNode(l1->val);
        ListNode* post= (diff==0)?adder(l1->next,l2->next,0):adder(l1->next,l2,diff-1);
        if(post && post->val > 9){
            post->val%=10;
            ++ret->val;
        }
        ret->next=post;
        return ret;
    }
};

*/
