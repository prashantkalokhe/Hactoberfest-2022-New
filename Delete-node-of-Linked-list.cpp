class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *p=NULL;
        while(fast!=NULL&&fast->next!=NULL)
        {p=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //ListNode *a=slow;
        p->next=slow->next;
       // delete a;
        return head;
        
    }
};
