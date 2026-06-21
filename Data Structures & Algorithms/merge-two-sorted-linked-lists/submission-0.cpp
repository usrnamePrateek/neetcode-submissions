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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newHead = new ListNode(-1);
        ListNode* temp3 = newHead;

        while (temp1 != NULL && temp2 != NULL) {
            ListNode* next = NULL;
            if (temp1->val <= temp2->val) {
                next = temp1->next;
                temp1->next = NULL;
                temp3->next = temp1;
                temp1 = next;
            } else {
                next = temp2->next;
                temp2->next = NULL;
                temp3->next = temp2;
                temp2 = next;
            }
            temp3 = temp3->next;
        }

        if (temp1 != NULL) {
            temp3->next = temp1;
        }

        if (temp2 != NULL) {
            temp3->next = temp2;
        }

        return newHead->next;
    }
};
