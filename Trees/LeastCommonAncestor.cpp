/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, vector<TreeNode* >& sta, int B,bool* flag)
{
    if(root == NULL || *flag == true) return;
    if(root->val == B) {
        *flag = true;
        return;
    }
    if(root->left) {
        sta.push_back(root->left);
        solve(root->left,sta,B,flag);
        if(*flag == true) return;
        sta.pop_back();
    }
    if(root->right) {
        sta.push_back(root->right);
        solve(root->right,sta,B,flag);
        if(*flag == true) return;
        sta.pop_back();
    }
}

int Solution::lca(TreeNode* A, int B, int C) {
    if(A == NULL) return 0;
    bool flag1 = false;
    bool flag2 = false;
    vector<TreeNode* > sta1; 
    vector<TreeNode* > sta2;
    sta1.push_back(A);
    sta2.push_back(A);
    solve(A,sta1,B,&flag1);
    solve(A,sta2,C,&flag2);
    int ans = -1;
    if(flag1 == true && flag2 == true)
        for(int i = 0;i<min(sta1.size(),sta2.size());i++)
        {
            if(sta1[i] == sta2[i]) ans = sta1[i]->val;
            else break;
        }
    return ans;
}