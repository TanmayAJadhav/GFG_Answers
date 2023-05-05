class Solution{
public:
    int ans;
    
    unordered_set<int> helper(Node*root, int k)
    {
        if(root==NULL)
        {
            unordered_set<int>s;
            return s;
        }
        
        unordered_set<int>l = helper(root->left, k);
        unordered_set<int>r = helper(root->right, k);
        
        unordered_set<int>tot;
        
        for(int x : l)
        {
            tot.insert(x);
        }
        
        for(int x : r)
        {
            tot.insert(x);
        }
        
        tot.insert(root->data);
        
        if(tot.size() <= k)
        {
            ans++;
        }
        
        return tot;
        
    }
    
    int goodSubtrees(Node *root,int k){
        ans  = 0;
        helper(root,k); 
        return ans;
    }
};