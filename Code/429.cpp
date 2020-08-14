/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            while(size--){
                Node* top = q.front();
                q.pop();
                temp.push_back(top->val);
                for(auto p:top->children){
                    q.push(p);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};