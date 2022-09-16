// Top View of Binary Tree [https://bit.ly/3PsvE5T]

// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100
// Your Task:
// Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Node Data ≤ 105

// Company Tags
// Walmart, Ola, CabsPaytm

// ---------------------------------------------------------------

// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;
// };
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        
        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;
            
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

};

// T.C => O(N) & S.C => O(N)