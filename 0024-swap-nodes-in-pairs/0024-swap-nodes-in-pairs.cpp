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
    ListNode* swapPairs(ListNode* head) {
        ListNode* current=head;
        


        ListNode* prev = nullptr;
        if (head == nullptr || head->next == nullptr)
        return head;
        ListNode* ans=current->next;

        
        

        while(current!=nullptr&&current->next!=nullptr){
        
        ListNode* nextNode=current->next;
        ListNode* afterPair=nextNode->next;
        
        

        nextNode->next=current;
        current->next=afterPair;
         
        if(prev!=nullptr){

        prev->next=nextNode;
        }

        prev=current;
        

        current=afterPair;

       
        
       


      

       

        

        

        
        }
        return ans;
    }
};