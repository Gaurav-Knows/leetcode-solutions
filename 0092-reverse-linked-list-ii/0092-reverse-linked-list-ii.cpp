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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 1;
    ListNode* currentH = head;
    
    ListNode* beforeLeft=nullptr;
    ListNode* prev=nullptr;
    ListNode* leftH=nullptr;


    while (currentH != nullptr) {
       if(pos<left){
        beforeLeft=currentH;
        
        
       }
       
       if (pos == left) {
        leftH=currentH;

        
        while(pos<=right){
            
           
            ListNode *nextNode=currentH->next;
            

            
            currentH->next=prev;

            prev=currentH;
            currentH=nextNode;
            pos++;




        }

        

        
    
    leftH->next=currentH;

    if(beforeLeft!=nullptr){
    
    beforeLeft->next=prev;
    }
    else{
        head=prev;
        
    }
    return head;
    }
    currentH = currentH->next;
    pos++;
    }
    return head;

    
    }
};