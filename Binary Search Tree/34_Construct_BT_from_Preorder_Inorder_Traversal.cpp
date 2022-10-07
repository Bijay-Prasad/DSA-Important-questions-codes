/*
105. Construct Binary Tree from Preorder and Inorder Traversal [https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/]

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

                3
              /   \ 
            9       20
                  /    \
                15      7


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
---------------------------------------------------------
*/

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[preorder[preStart]];
        int numsLeft = inRoot - inStart;
        root->left =  helper(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1,  inMap);
        root->right =  helper(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd,  inMap);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode *root = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};

// T.C => O(N) & S.C => O(N)