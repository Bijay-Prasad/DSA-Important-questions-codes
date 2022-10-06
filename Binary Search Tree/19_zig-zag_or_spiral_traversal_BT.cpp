/*
103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

            3
          /   \
        9      20
              /   \
            15      7

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
---------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                int index = (leftToRight) ? i : size-1-i;
                row[index] = node->val;
                
                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};

// T.C => O(N^2) & S.C => O(N)