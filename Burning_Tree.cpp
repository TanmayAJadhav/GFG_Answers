class Solution {
  public:
    unordered_map<Node*, Node*>parent;
    
    Node* parentMap(Node* root, int value)
    {
        queue<Node*>q;
        q.push(root);
        Node* tar = NULL;
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node->data == value)
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
        return tar;
    }
    
    int findMax(Node* current)
    {
        queue<Node*>q;
        unordered_map<Node*,bool>vis;
        q.push(current);
        vis[current] = true;
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            bool flag = false;
            for(int i = 0; i < sz; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    flag = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right])
                {
                    flag = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parent[node] && !vis[parent[node]])
                {
                    flag = true;
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        Node* tar = parentMap(root, target);
        return findMax(tar);
    }
};