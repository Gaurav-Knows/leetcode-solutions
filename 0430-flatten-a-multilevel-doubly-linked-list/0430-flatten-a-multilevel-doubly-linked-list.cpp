/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* current=head;

        while(current!=nullptr){
            if(current->child!=nullptr){
                Node* nextNode=current->next;


                Node* childNode=current->child;

                current->next=childNode;
                childNode->prev=current;

                while(childNode->next!=nullptr){
                    childNode=childNode->next;
                }

                childNode->next=nextNode;

                if(nextNode!=nullptr){
                nextNode->prev=childNode;
                }

                current->child = nullptr;
            }

            current=current->next;

            
        }
        return head;

        
        
    }
};