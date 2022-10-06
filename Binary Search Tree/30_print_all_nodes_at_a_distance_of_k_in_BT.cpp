/*
863. All Nodes Distance K in Binary Tree [https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/]

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:

                     3
                   /    \
                5         1
               /  \      /  \
              6    2    0    8
                  /  \  
                  7   4


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

---------------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left){
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        makeParents(root, parent_track, target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()){
            int size = queue.size();
            if(curr_level++ == k)break;
            for(int i=0;i<size;i++){
                TreeNode*current = queue.front();
                queue.pop();
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

// T.C => O(N) & S.C => O(N)