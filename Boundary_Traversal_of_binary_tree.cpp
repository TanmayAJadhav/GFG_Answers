class Solution {
    vector<int>ans;
public:
    bool checkLeaf(Node* node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void addLeftBoundary(Node* current)
    {
        while(current)
        {
            if(!checkLeaf(current))
            {
                ans.push_back(current->data);
            }
            if(current->left)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    
    void addRightBoundary(Node* current)
    {
        vector<int>right;
        while(current)
        {
            if(!checkLeaf(current))
            {
                right.push_back(current->data);
            }
            if(current->right)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        
        for(int i = right.size()-1; i >= 0; i--)
        {
            ans.push_back(right[i]);
        }
    }
    
    void addLeaf(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        if(checkLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        addLeaf(root->left);
        addLeaf(root->right);
        
    }

    vector <int> boundary(Node *root)
    {
        if(root==NULL)
        {
            return ans;
        }
        
        if(!checkLeaf(root))
        {
            ans.push_back(root->data);
        }
        
        addLeftBoundary(root->left);
        addLeaf(root);
        addRightBoundary(root->right);
        
        return ans;
        
    }
};