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
        unordered_map<Node*,Node*>nodeMap;
       
        Node* curr = head;
        while(curr != NULL) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while(curr != NULL) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }
        
        return nodeMap[head];
    }
};
