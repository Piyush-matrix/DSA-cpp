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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
          ListNode* temp=head,*slow=head,*fast=head,*traver=head;
          int cnt=0;
          while(traver!=NULL){
              traver=traver->next;
              cnt++;
          }
         if (cnt == 0) return head;
         k = k % cnt;
        if (k == 0) return head; 
          for(int i=0;i<k;i++){
            fast=fast->next;
          }
          while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;

          }
          ListNode* newhead=slow->next;
          fast->next=head;
          slow->next=NULL;
          return newhead;
          
        
    }
};