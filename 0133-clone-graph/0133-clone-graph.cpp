/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;

    Node* cloneGraph(Node* node) {
        
        return clone(node);
       
    }

    Node* clone(Node* node){

        if (node == nullptr) {
           return nullptr;
        }

        
        Node* copy=new Node(node->val);
        mp[node] = copy;

        for(Node* neighbor: node->neighbors){
            if(mp.find(neighbor)==mp.end()){
                clone(neighbor);

                
            }

            copy->neighbors.push_back(mp[neighbor]);
        }

        return copy;

    }
};