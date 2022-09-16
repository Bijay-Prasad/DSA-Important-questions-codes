// Left View of Binary Tree [https://bit.ly/3PCqyE9]

/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000

--------------------------------------------------------------------
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void viewing(Node *node, int level, vector<int> &res){
    if(!node) return;
    if(level == res.size()) res.push_back(node->data);
    viewing(node->left, level+1, res);
    viewing(node->right, level+1, res);
}

vector<int> leftView(Node *root)
{
   vector<int> res;
   viewing(root, 0, res);
   return res;
}

// T.C => O(N) & S.C => O(H)





// Using LevelOrder Traversal

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0;i < size;i++) {
            Node *temp = q.front();
            q.pop();
            if(i == size-1) ans.push_back(temp->data);
            
            if(temp->right) q.push(temp->right);   
            if(temp->left) q.push(temp->left);
        }
    }
    return ans;
}

// T.C => O(N) & S.C => O(N) 

// --------------------------------------------------------------------

















// Right View of Binary Tree

/*
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side. The task is to complete the function rightView(), which accepts root of the tree as argument.

right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /  \      / \
  4    5    6   7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 2

Example 2:

Input:
        10
      /   \
    20      30
   /   \
40      60

Output: 10 30 60
Your Task:
You just have to complete the function rightView() that returns an array containing the nodes that are in the right view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000

--------------------------------------------------------------------
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void viewing(Node *node, int level, vector<int> &res){
    if(!node) return;
    if(level == res.size()) res.push_back(node->data);
    viewing(node->right, level+1, res);
    viewing(node->left, level+1, res);
}

vector<int> rightView(Node *root)
{
   vector<int> res;
   viewing(root, 0, res);
   return res;
}

// T.C => O(N) & S.C => O(H)





// Using LevelOrder Traversal

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0;i < size;i++) {
            Node *temp = q.front();
            q.pop();
            if(i == size-1) ans.push_back(temp->data);
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);   
        }
    }
    return ans;
}

// T.C => O(N) & S.C => O(N) 