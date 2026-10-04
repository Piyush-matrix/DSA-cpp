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
    ListNode* getkthnode(ListNode* head,int k){
        ListNode* temp=head;
        k=k-1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        } return temp;
    }
    ListNode* reversell(ListNode* head){
        ListNode* temp=head,*prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        } return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head, *prevlast=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prevlast) prevlast->next=temp;
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reversell(temp);
            if(temp==head){
                head=kthnode;
            } else{
                prevlast->next=kthnode;
            }
           prevlast=temp;
           temp=nextnode;
        }
          return head;
    }
};