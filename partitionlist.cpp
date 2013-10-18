
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p, *q, *index, *insertHead;
        p = head;
        if(p == NULL)
            return NULL;
        if(p->next == NULL)
            return head;
        q = NULL;
        while(p!= NULL && p->val < x){
            q = p;
            p = p->next;
        }
        if(p == NULL)
            return head;
        index = p;
        insertHead = q;
        while(p != NULL){
            while(p!= NULL && p->val >= x){
                q = p;
                p = p->next;
            }
            if(p == NULL)
                break;
            if(index == head){
                q->next = p->next;
                head = p;
                p->next = index;
                insertHead = p;
            }
            else{
                q->next = p->next;
                insertHead ->next = p;
                insertHead = p;
                p->next = index;
            }
            p = q;
        }
        return head;
    }
};
