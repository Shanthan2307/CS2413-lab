struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode*temp,*prev;
    if(head!=NULL){
       
       if(head->val==val){
        head=head->next;
       }
    if(head!=NULL){
temp=head;
    while(temp->next!=NULL){
            if(temp->next->val==val){
            temp->next=temp->next->next;
        }
        else
        temp=temp->next;
        
    }
    if(temp->val==val)
        head->next=NULL;
    
    if(head->val==val){
         head=head->next;
    }
    }
    }
    return head;
}
