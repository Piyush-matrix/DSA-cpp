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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dnode=new ListNode(-1);
        dnode->next=head;
        ListNode* prev=dnode;
        while(prev->next && prev->next->next){
              ListNode* first=prev->next;
              ListNode* snd=prev->next->next;

             first->next=snd->next;
             snd->next=first;
             prev->next=snd;
             prev=first;
            }
        return dnode->next;
    }
};