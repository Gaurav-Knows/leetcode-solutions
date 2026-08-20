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

        

        
        

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        

        ListNode* current=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        
        

        while(current!=nullptr){

            ListNode* nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
           

            

        }

        while(prev!=nullptr){
            ListNode* firstNext = head->next;
            ListNode* secondNext = prev->next;
            head->next=prev;

            
            prev->next=firstNext;

            head = firstNext;
            prev = secondNext;
        }

        

        
    }
};