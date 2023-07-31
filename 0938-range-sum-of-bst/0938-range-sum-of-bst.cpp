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
int sum = 0; // Initialised Sum
    void Traversal(TreeNode* root,int low,int high)
    {
        if(root==NULL) // If Node is NULL then we return 
        return;
        Traversal(root->left,low,high); // To check for left Node
        if(root->val <= high && root->val >=low)sum+=root->val;// If value of node is in range then add to sum.
        Traversal(root->right,low,high); // To check for right Node
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr); // To make input output fast
        Traversal(root,low,high); //To Traverse in BST
        return sum;
    }
};