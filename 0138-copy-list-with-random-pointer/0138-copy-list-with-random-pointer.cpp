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
    void insertcopy(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
    }

    void Pointrandoms(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copy = temp->next;
            if (temp->random)
                copy->random = temp->random->next;
            else
                copy->random = nullptr;
            temp = temp->next->next;
        }
    }

    Node* PointNext(Node* head) {
        Node* temp = head;
        Node* newhead = temp->next;
        while (temp != NULL) {
            Node* copy = temp->next;
            temp->next = copy->next;
            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }
            temp = temp->next;
        }
        return newhead;
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        insertcopy(head);
        Pointrandoms(head);
        return PointNext(head);
    }
};

