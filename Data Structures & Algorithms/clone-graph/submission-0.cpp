/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        
        unordered_map<int, Node*> nodemap;
        return sol(node, nodemap);
    }

    Node* sol(Node* node, unordered_map<int, Node*>& nodemap) {
        Node* root;
        if (nodemap.count(node->val)) {
            return nodemap[node->val];
        }

        root = new Node(node->val);
        nodemap[node->val] = root;

        for (auto& neigh : node->neighbors) {
            Node* newNeigh = sol(neigh, nodemap);
            root->neighbors.push_back(newNeigh);
        }

        return root;
    }
};
