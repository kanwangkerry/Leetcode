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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        lists[len-2] = merge(lists[len-2], lists[len-1]);
        lists.erase(lists.end()-1);
        return mergeKLists(lists);
    }
    
    ListNode *merge(ListNode* l1, ListNode *l2){
        ListNode* result = NULL;
        ListNode* p;
        if(l1 != NULL && l2 != NULL){
            if(l2->val < l1->val){
                result = new ListNode(l2->val);
                l2 = l2->next;
            }
            else{
                result = new ListNode(l1->val);
                l1 = l1->next;
            }
        }
        else if(l1 != NULL){
            result = new ListNode(l1->val);
            l1 = l1->next;
        }
        else if(l2 != NULL){
            result = new ListNode(l2->val);
            l2 = l2->next;
        }
        else return NULL;
            
        p = result;
        while(l1 != NULL && l2 != NULL){
            if(l2->val < l1->val){
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }
            else{
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }
            
        }
        while(l1 != NULL){
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;
           
        }
        while(l2 != NULL){
            p->next = new ListNode(l2->val);
            p = p->next;
            l2 = l2->next;
            
        }
        return result;
    }
};
