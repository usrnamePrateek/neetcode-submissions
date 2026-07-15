/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node* newList = new Node(-1);
        Node* tempNew = newList;
        Node* temp = head;

        unordered_map<Node*, Node*> mp;

        while (temp) {
            Node* newNode = new Node(temp->val);
            tempNew->next = newNode;

            mp[temp] = newNode;

            temp = temp->next;
            tempNew = tempNew->next;
        }

        temp = head;
        tempNew = newList->next;

        while (temp) {
            Node* randomNode = mp[temp->random];
            tempNew->random = randomNode;
            temp = temp->next;
            tempNew = tempNew->next;
        }

        return newList->next;
    }
};
