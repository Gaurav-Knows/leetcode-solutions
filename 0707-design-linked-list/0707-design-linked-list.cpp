class MyLinkedList {
    ListNode *head;
public:
    MyLinkedList() {
        
        head=nullptr;
        
    }
    
    int get(int index) {

        ListNode* current=head;
        int pos=0;

        if(head==nullptr){
            return -1;
        }

        while(current!=nullptr){
            if(pos==index){
                return current->val;
            }

            current=current->next;

            pos++;

        }
        return -1;
        
    }
    
    void addAtHead(int val) {
       

        ListNode* newNode=new ListNode(val);

        newNode->next=head;
        head=newNode;

        
    }
    
    void addAtTail(int val) {
        ListNode* current=head;
        ListNode* newNode=new ListNode(val);

        if(head==nullptr){
            head=newNode;
            return;
        }
        while(current->next!=nullptr){
            current=current->next;
        }

        

        current->next=newNode;
        
    }
    
    void addAtIndex(int index, int val) {
        ListNode* newNode=new ListNode(val);
        int pos=0;
        if(index==0){
            newNode->next=head;
            head=newNode;
            return;
        }

        ListNode* current=head;

        while(current!=nullptr){
            
            if(pos==index-1){
                newNode->next=current->next;
                current->next=newNode;
                return;
                
            }
            current=current->next;
            pos++;
        }

        

        
    }
    
    void deleteAtIndex(int index) {
        ListNode *current=head;
        int pos=0;
        ListNode *prev=nullptr;

        if(head==nullptr){
            return;
        }

        while(current!=nullptr){
            if(index == 0){
                head = head->next;
                return;
            }
            
            if(pos<index){
                prev=current;
            }

            if(pos==index){

                prev->next=current->next;

            }

            current=current->next;
            pos++;

        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */