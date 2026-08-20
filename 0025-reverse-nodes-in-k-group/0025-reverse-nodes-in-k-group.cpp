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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current=head;
        ListNode* prev=nullptr;
        ListNode* nextN=nullptr;
        
        ListNode* reverseH = nullptr;
        ListNode* prevTail=nullptr;

        
        

        if(head==nullptr){
            return nullptr;
        }

        while(current!=nullptr){
            ListNode* groupStart = current;
            ListNode* temp=groupStart;
            int count = 0;
            ListNode* check = groupStart;
            
            while (count < k && check != nullptr) {
            check = check->next;
            count++;
            }

            if (count < k) {
            break;
            }

            nextN = check;
           
            
            

            int pos1=0;
            prev=nullptr;

                

                while(pos1<k){
                
                
                    
                ListNode* nextNode=temp->next;

                temp->next=prev;
                
                prev=temp;
                temp=nextNode;
                
                pos1++;
                }
                current = nextN;
                groupStart->next=nextN;
                

                
                
                

                if (reverseH == nullptr) {
                reverseH = prev;
                }
                

                if(prevTail!=nullptr){
                    prevTail->next=prev;
                }

                prevTail=groupStart;
            
                
                
                
                



            
           
            
            

        }
        return (reverseH == nullptr) ? head : reverseH;
        
    }
};