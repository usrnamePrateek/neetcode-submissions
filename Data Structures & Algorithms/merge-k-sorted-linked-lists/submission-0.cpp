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
    class Compare {
       public:
        bool operator()(ListNode* v1, ListNode* v2) { return v1->val > v2->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* head2 = new ListNode(-1);
        ListNode* temp = head2;

        for (auto& head : lists) {
            if (head) pq.push(head);
        }
    
        while (!pq.empty()) {
            ListNode* least = pq.top();
            pq.pop();
            temp->next = least;
            temp = temp->next;
            if (least->next) {
                pq.push(least->next);
            }
        }

        return head2->next;
    }
};
