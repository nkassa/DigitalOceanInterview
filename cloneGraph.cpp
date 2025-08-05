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
    unordered_map<Node*, Node*> count;
    Node* cloneGraph(Node* node) 
    {
        if(!node)
        {
            return nullptr;
        }
        Node* curr = new Node(node->val);
        count[node] = curr;
        for(Node* neighbor: node->neighbors)
        {
            if(count.find(neighbor) != count.end())
            {
                count[node]->neighbors.push_back(count[neighbor]);
            }
            else
            {
                count[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return count[node];
    }
};
// not helper function 