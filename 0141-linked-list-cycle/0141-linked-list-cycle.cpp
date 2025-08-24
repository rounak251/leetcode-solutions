/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        std::unordered_map<ListNode*,int>hashnode;
        while(temp!=NULL){
            if(hashnode.find(temp)!=hashnode.end())return true;
            hashnode[temp]=1;
            temp=temp->next;
        }
    return false;}
};