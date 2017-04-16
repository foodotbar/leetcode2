/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead, *l1, *l2;
        if (head == NULL) 
            return NULL;
        //在每个节点后面添加一个他的copy节点
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        //给copy节点的random指针赋值    
        newHead = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL) 
                l1->next->random = l1->random->next;
        }
        //把新添加的节点从原来链表里剥离出来    
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL) 
                l2->next = l2->next->next;
        }
        //返回新链表的表头
        return newHead;
    }
};
