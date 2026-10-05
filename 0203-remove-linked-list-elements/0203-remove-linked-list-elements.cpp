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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dnode=new ListNode(0);
        dnode->next=head;
        if(head==NULL) return head;
         ListNode* temp=dnode;
         while(temp->next!=NULL){
            if(temp->next->val==val) {
                ListNode* dlt=temp->next;
                temp->next=temp->next->next;
                delete(dlt);
            }
            else temp=temp->next;
         }
         return dnode->next;
    }
};