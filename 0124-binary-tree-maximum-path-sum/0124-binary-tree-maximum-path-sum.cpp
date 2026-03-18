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
int height(TreeNode*root,int &sum){
if(root==NULL)return 0;
int l=height(root->left,sum);
int r=height(root->right,sum);
int lowe_is_good=l+r+root->val;
int only_root=root->val;
int anyone_good=max(l,r)+root->val;
sum=max({sum,lowe_is_good,only_root,anyone_good});
return max(anyone_good,only_root) ;
}
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        height(root,sum);
        return sum;
    }
};