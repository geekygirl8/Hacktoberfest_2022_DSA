
// problem link: https://leetcode.com/problems/linked-list-cycle/
// github link : https://github.com/speedcoder121 


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
