/*
100. Same Tree [https://leetcode.com/problems/same-tree/]

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

            1           1 
          /   \       /    \
        2       3    2      3


Input: p = [1,2,3], q = [1,2,3]
Output: true


Example 2:

            1       1
          /           \
        2               2

Input: p = [1,2], q = [1,null,2]
Output: false


Example 3:

        1             1
      /   \          /  \
    2       1       1     2

Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

---------------------------------------------------------
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p==q;
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// T.C => O(N) & S.C => O(N)