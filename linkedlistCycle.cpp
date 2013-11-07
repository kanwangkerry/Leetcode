
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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p, *q;
        p = head;
        q = head;
        while(p != NULL && p->next != NULL){
            p = p->next->next;
            q = q->next;
            if(p == q)
                break;
        }
        if(p == NULL || p->next == NULL)
            return false;
        else
            return true;
        
    }
};
