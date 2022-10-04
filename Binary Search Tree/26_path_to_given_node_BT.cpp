// Path to Given Node [https://www.interviewbit.com/problems/path-to-given-node/]

/*
Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105 

 1 <= Data Values of Each Node <= N

 1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [1]


Example Explanation
Explanation 1:

 We need to find the path from root node to node with data value 5.
 So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
Explanation 2:

 We need to find the path from root node to node with data value 1.
 As node with data value 1 is the root so there is only one node in the path.
 So we will return [1]

Asked In: Amazon
--------------------------------------------------------------------------
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool helper(TreeNode* root,vector<int> &ans, int x) {
    if(!root) return false;
    ans.push_back(root->val);
    
    if(root->val == x) return true;
    
    if(helper(root->left, ans, x) || helper(root->right, ans, x)) return true;
    
    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(!A) return ans;
    helper(A, ans, B);
    return ans;
}

// T.C => O(N) & S.C => O(H)



// Same question with minor changes

/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:

        1
      /   \
    2       3
      \
        5

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

------------------------------------------------------------------------------------
*/

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
private:
    void helper(TreeNode* root, string cur, vector<string> &ans){
        if(!root) return;
        if(root->left || root->right) cur+=to_string(root->val)+"->";
        else{
            cur+=to_string(root->val);
            ans.push_back(cur);
        }
        helper(root->left, cur, ans);
        helper(root->right, cur, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        string cur = "";
        helper(root, cur, ans);
        return ans;
    }
};

// T.C => O(N) & S.C => O(H)