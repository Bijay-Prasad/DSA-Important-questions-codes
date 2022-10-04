// 101. Symmetric Tree [https://leetcode.com/problems/symmetric-tree/]

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:
                1
              /   \
            2       2
          /   \    /  \
        3      4  4     3

Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:
                1
              /   \
             2     2
              \      \
               3      3

Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

-------------------------------------------------------------------------
*/

// Recursive Approach:

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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricSolve(root->left, root->right);
    }
    bool isSymmetricSolve(TreeNode* left, TreeNode* right){
        if(!left || !right) return left == right;
        if(left->val != right->val) return false;
        return isSymmetricSolve(left->left, right->right) 
            && isSymmetricSolve(left->right, right->left);
    }
};

// T.C => O(N) & S.C => O(N)




// Iterative Approach:

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            
            if(!left && !right) continue;
            if(!left || !right) return left == right;
            if(left->val != right->val) return false;
            q.push(left->left); q.push(right->right);
            q.push(left->right); q.push(right->left);
        }
        return true;
    }
};

// T.C => O(N) & S.C => O(N)