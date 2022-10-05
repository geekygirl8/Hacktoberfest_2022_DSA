class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f)return true;
            
            
        }
        return false;
    }
};
