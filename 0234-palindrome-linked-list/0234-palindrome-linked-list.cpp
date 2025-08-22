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
ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev1=temp->next;
        ListNode* prev2=prev1->next;
        temp->next=NULL;
        while(prev2){
            prev1->next=temp;
            temp=prev1;
            prev1=prev2;
            prev2=prev1->next;
        }
        prev1->next=temp;
        return prev1;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseList(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second){
            if(second->val!=first->val){
                return false;
            }
            second=second->next;
            first=first->next;
        }
        return true;
    }

};