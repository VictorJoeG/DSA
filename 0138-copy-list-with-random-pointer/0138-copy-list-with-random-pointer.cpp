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
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;

        while (current != nullptr) {
            Node* clonedNode = new Node(current->val);
            clonedNode->next = current->next;
            current->next = clonedNode;
            current = clonedNode->next;
        }

        current = head;

        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        current = head;
        Node* clonedHead = head->next;

        while (current != nullptr) {
            Node* clonedNode = current->next;
            current->next = clonedNode->next;
            if (clonedNode->next != nullptr) {
                clonedNode->next = clonedNode->next->next;
            }
            current = current->next;
        }

        return clonedHead;
    }
};
