/*
543. Diameter of Binary Tree [https://leetcode.com/problems/diameter-of-binary-tree/]

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

---------------------------------------------------------
*/

//Brute Force [T.C => O(N^2)]
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh, rh);
    }
    
    void solve(TreeNode* root, int &ans){
        if(root == NULL) return;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans, lh+rh);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};



//Optimal Soln [T.C => O(N)]
class Solution {
private:
    int height(TreeNode* root, int &diameter){
        if(!root) return 0;
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};