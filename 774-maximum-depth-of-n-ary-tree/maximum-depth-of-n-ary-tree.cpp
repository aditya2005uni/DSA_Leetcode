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
    int maxDepth(Node* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return 0;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>lev;
            for(int i=0;i<size;i++){
                Node*temp=q.front();
                q.pop();
                for(auto child:temp->children){
                    q.push(child);
                }
                lev.push_back(temp->val);
            }
            ans.push_back(lev);
        }
        return ans.size();
    }
};