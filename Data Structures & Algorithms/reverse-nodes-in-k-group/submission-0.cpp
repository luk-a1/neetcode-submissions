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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        bool first = true;
        while(temp != nullptr){
            ListNode* start = temp;
            bool ind = true;
            
            // temp je k-ti
            for(int i=0;i<k-1;i++){
                if(temp == nullptr) {ind = false; break;}
                temp = temp->next;
            }

            if(!ind || temp == nullptr) break;
            
            ListNode* next_start = temp->next;

            temp->next = nullptr;
            
            // start will be last
            // temp will be first
            temp = reverse(start);
            if(prev != nullptr)
                prev -> next = temp;

            if(first){
                head = temp;
                first = false;
            }

            prev = start;
            if(start != nullptr) start->next = next_start;
            temp = next_start;
        }

        return head;
    }
};
