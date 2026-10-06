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
    ListNode* reversell(ListNode* head){
        ListNode* temp=head,*prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        } return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return head;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reversed=reversell(slow);
        ListNode* temp=head;
        ListNode* sndhalf=reversed;
        while(sndhalf!=NULL){
            if(temp->val!=sndhalf->val) return false;
            else {
                temp=temp->next;
                sndhalf=sndhalf->next;
            }

        } return true;


        
    }
};