/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct cmp{
    bool operator()(ListNode* n1, ListNode* n2){
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];

        for(int i=0;i<lists.size();i++) if(lists[i] != nullptr)pq.push(lists[i]);
        ListNode* head = pq.top();
        if(head->next != nullptr) pq.push(head->next);
        pq.pop();
        ListNode* temp = head;
        bool first = true;

        while(!pq.empty()){
                temp -> next = pq.top();
                ListNode* t = pq.top()->next;
                pq.pop();
                if(t != nullptr) pq.push(t);
                temp = temp->next;
        }

        return head;

    }
};
