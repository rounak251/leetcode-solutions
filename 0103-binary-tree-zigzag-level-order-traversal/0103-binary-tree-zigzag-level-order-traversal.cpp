/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        q.push(root);int level=0;
        while(!q.empty()){
            int size=q.size();
             vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
            q.pop();
                
                    if(node->left!=NULL)q.push(node->left);
                    if(node->right!=NULL)q.push(node->right);
                
             
            if(level%2==0){
                temp[i]=node->val;}
                else temp[size-i-1]=node->val;

                 
            }
            ans.push_back(temp);level++;
        }
        return ans;
    }
};