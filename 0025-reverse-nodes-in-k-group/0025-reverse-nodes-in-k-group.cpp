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
    ListNode* reverse(ListNode* head) {
        ListNode* node=nullptr;
        while(head != nullptr){
            ListNode*temp =head->next;
            head->next =node;
            node=head;
            head=temp;
        }
        return node;
    }
    ListNode* getK(ListNode* temp, int k){
        k=k-1;
        while(temp != NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp != NULL){
            ListNode* KthNode=getK(temp,k);
            if(KthNode ==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* newnode= KthNode->next;
            KthNode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=KthNode;
            }
            else prev->next=KthNode;
            prev=temp;
            temp=newnode;
        }
        return head; 
    }
};