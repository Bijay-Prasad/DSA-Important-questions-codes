/*
110. Balanced Binary Tree [https://leetcode.com/problems/balanced-binary-tree/]
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

            3
          /   \
        9       20
               /  \
            15      7

Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:

                    1
                  /    \
                2        2
               /   \
            3       3
           /  \
        4       4

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

---------------------------------------------------------
*/

// Brute Force [T.C -> O(N^2)]
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1+max(lh, rh);
    }
    
    bool check(TreeNode* root){
        if(!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(rh-lh) > 1) return false;
        bool left = check(root->left);
        bool right = check(root->right);
        if(!left || !right) return false;
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        bool chk = check(root);
        return chk;
    }
};



// Optimal Solution [T.C -> O(N)]
class Solution {
private:
    int dfsHeight(TreeNode* root){
        if(!root) return 0;
        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};