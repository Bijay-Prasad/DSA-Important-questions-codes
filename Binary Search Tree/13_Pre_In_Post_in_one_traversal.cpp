/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
    public:
    void allInOne(Node* node, stack<pair<Node*, int>> &st,  vector<int> &pre, vector<int> &in, vector<int> &post){
        if(!node) return;
        
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            
            if(it.second == 1){
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->left) st.push({it.first->left, 1});
            }
            else if(it.second == 2){
                in.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->right) st.push({it.first->right, 1});
            }
            else{
                post.push_back(it.first->data);
            }
        }
    }

    vector<int> postOrder(Node* node) {
        // Preorder, Inorder and Postorder all in one
        stack<pair<Node*, int>>st;
        st.push({node, 1});
        vector<int> pre, in, post;
        allInOne(node, st, pre, in, post);
        return post;
    }
};