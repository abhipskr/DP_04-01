//RECURSIVE

class Solution {
public:

    int solve(TreeNode* root){

        if(root==NULL) return 0;

        int take=0;
        take+=root->val;
        if(root->left) take+=solve(root->left->left)+solve(root->left->right);
        if(root->right) take+=solve(root->right->left)+solve(root->right->right);

        int notake= solve(root->left)+solve(root->right);

        return max(take,notake);

    }


    int rob(TreeNode* root) {
        return solve(root);
    }
};





//NEMOIZATION  



class Solution {
public:

    int solve(TreeNode* root,unordered_map<TreeNode* ,int>&mp){

        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];

        int take=0;
        take+=root->val;
        if(root->left) take+=solve(root->left->left,mp)+solve(root->left->right,mp);
        if(root->right) take+=solve(root->right->left,mp)+solve(root->right->right,mp);

        int notake= solve(root->left,mp)+solve(root->right,mp);

        return mp[root]=max(take,notake);

    }


    int rob(TreeNode* root) {
        unordered_map<TreeNode* ,int>mp;
        return solve(root,mp);
    }
};