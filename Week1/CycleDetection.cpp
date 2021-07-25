bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *slow=head, *fast=head;
    while(fast->next){
        fast=fast->next;
        if(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow) return true;
    }
    return false;

}