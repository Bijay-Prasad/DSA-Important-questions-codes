/*
222. Count Complete Tree Nodes [https://leetcode.com/problems/count-complete-tree-nodes/]

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:

                    1
                  /   \
                2      3
              /   \   /
            4      5 6


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

---------------------------------------------------------
*/

// Brute Force [T.C => O(N) & S.C => O(N)]

class Solution {
public:
    void inorder(TreeNode* root, int &cnt){
        if(!root) return;
        cnt++;
        inorder(root->left, cnt);
        inorder(root->right, cnt);
    }
    
    int countNodes(TreeNode* root) {
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
};

// Optimal Solution [T.C => O(log^2 N) & S.C => O(log N)]

class Solution {
public:
    int findLeftHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    
    int findRightHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};