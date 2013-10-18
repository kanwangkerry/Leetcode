
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class mycomparison : public binary_function<ListNode*, ListNode*, bool>
{
public:
  bool operator() (const ListNode* lhs, const ListNode* rhs) const
  {
    return lhs->val > rhs->val;
  }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        priority_queue<ListNode*, vector<ListNode*>, mycomparison> q;
        if(lists.size() == 0)
            return NULL;
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != NULL)
                q.push(lists[i]);
        }
        ListNode *p, *head = NULL;
        if(q.empty())
            return NULL;
        head = q.top();
        q.pop();
        if(head->next != NULL)
            q.push(head->next);
        p = head;
        while(!q.empty()){
            p->next = q.top();
            p = q.top();
            q.pop();
            if(p->next != NULL)
                q.push(p->next);
        }
        return head;
    }
};
