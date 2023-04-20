/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
public:
    
    Node* tar = NULL;
    unordered_map<Node*,Node*>parent;
    
    void parentfill(Node* root, int val)
    {
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int sze = q.size();
            
            for(int i = 0; i < sze; i++)
            {
                Node* node = q.front();
                q.pop();
                
                if(node->data == val)
                {
                    tar = node;
                }
                
                if(node->left)
                {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }   
    }
    
    int ladoos(Node* root, int home, int k)
    {
        parentfill(root,home);
        
        queue<Node*>q;
        q.push(tar);
        unordered_map<Node* , bool>vis;
        vis[tar] = true;
        
        int ans = 0;
        ans += home;
        while(!q.empty())
        {
            int sze = q.size();
            
            for(int i = 0; i < sze; i++)
            {
                Node* node = q.front();
                q.pop();
                
                
                if(node->left && !vis[node->left])
                {
                    ans += node->left->data;
                    q.push(node->left);
                    vis[node->left] = true;                
                }
                if(node->right && !vis[node->right])
                {
                    ans += node->right->data;
                    q.push(node->right);
                    vis[node->right] = true;                
                }
                
                if(parent[node] && !vis[parent[node]])
                {
                    ans += parent[node]->data;
                    q.push(parent[node]);
                    vis[parent[node]] = true;                
                }
            }
            k--;
            if(k == 0)
            {
                return ans;
            }            
        }
        return ans;
    }
};