
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 1;
        ListNode *p = head;
        while(i < m-1){
            i++;
            p = p->next;
        }
        ListNode *prevList, *listTail, *prevNode, *nextNode;
        if( m == n)
            return head;
        if(m == 1){
            prevList = NULL;
            listTail = p;
            nextNode = p->next;
            prevNode = NULL;

        }
        else{
            prevList = p;
            listTail = p->next;
            nextNode = p->next->next;
            p = p->next;
            prevNode = NULL;
        }
        i = m;
        while(i++ < n){
            p->next = prevNode;
            prevNode = p;
            p = nextNode;
            if(p == NULL){
                nextNode = NULL;
                continue;
            }
            nextNode = p->next;
            p->next = prevNode;
        }
        listTail->next = nextNode;
        if(m == 1){
            head = p;
        }
        else{
            prevList->next = p;
        }
        return head;
    }
};
