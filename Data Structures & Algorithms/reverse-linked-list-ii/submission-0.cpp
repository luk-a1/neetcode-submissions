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
class Solution {
public:
    void reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        //return prev;
    }

    void printlist(ListNode* head){
        ListNode* t = head;

        while(t){
            cout<<t->val<<" ";
            t=t->next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* t1 = dummy;

        //printlist(head);

        for(int i=0;i<left-1;i++)
            t1 = t1->next;
        
        ListNode* revhead = t1->next;
        t1->next = nullptr;
        ListNode* t2 = revhead;

        for(int i=0;i<right-left;i++)
            t2 = t2->next;

        ListNode* revend = t2;
        t2 = t2->next;
        revend->next = nullptr;

        reverse(revhead);

        revhead->next = t2;
        t1 -> next = revend;

        return dummy->next;
    }
};