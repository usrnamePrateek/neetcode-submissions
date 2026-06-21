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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp2 = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while (temp2) {
            ListNode* next = temp2->next;
            temp2->next = prev;
            prev = temp2;
            temp2 = next;
        }

        ListNode* temp1 = head;
        temp2 = prev;
        bool flag = true;

        while (temp1 && temp2) {
            ListNode* next1 = temp1->next;
            ListNode* next2 = temp2->next;
    
            if (flag) {
                temp1->next = temp2;
                temp1 = next1;
            }
            else {
                temp2->next = temp1;
                temp2 = next2;
            }

            flag = !flag;
        }
    }
};
