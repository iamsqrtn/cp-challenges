#include "stdc++.h"

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {
public:
    TreeNode* buildTree(vector<int>& nums) {
        int n=nums.size(),i;
        TreeNode* root;
        queue<TreeNode*>q;
        if(n==0 || nums[0]==-1)
            return nullptr;
        root=new TreeNode(nums[0]);
        q.push(root);
        i=1;
        while(i<n) {
            TreeNode* p=q.front();
            q.pop();
            if(i<n && nums[i]!=-1) {
                p->left=new TreeNode(nums[i]);
                q.push(p->left);
            }
            i++;
            if(i<n && nums[i]!=-1) {
                p->right=new TreeNode(nums[i]);
                q.push(p->right);
            }
            i++;
        }
        return root;
    }
    void showTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* p=q.front();
            q.pop();
            cout<<p->val<<" ";
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);    
        }
    }    
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int i,n,mx=-1;
        vector<int>dis(1001,-1),par(1001,-1);
        set<int>s,t;
        map<int,TreeNode*>f;
        queue<TreeNode*>q;
        q.push(root);
        par[root->val]=-1;
        dis[root->val]=0;
        while(!q.empty()) {
            TreeNode* p=q.front();
            q.pop();
            f[p->val]=p;
            if(p->left) {
                q.push(p->left);
                dis[p->left->val]=dis[p->val]+1;
                par[p->left->val]=p->val;
            }
            if(p->right) {
                q.push(p->right);
                dis[p->right->val]=dis[p->val]+1;
                par[p->right->val]=p->val;
            }
        }
        mx=*max_element(dis.begin(),dis.end());
        for(i=0;i<1001;i++) {
            if(dis[i]==mx)
                s.insert(i);
        }
        while(s.size()>1) {
            n=s.size();
            t.clear();
            while(n--) {
                t.insert(par[*s.begin()]);
                s.erase(s.begin());
            }
            s.insert(t.begin(),t.end());
        }
        return f[*s.begin()];
    }
};

int main() {
    Tree tree;
    Solution sol;
    vector<int>nums={3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root=tree.buildTree(nums);
    tree.showTree(sol.lcaDeepestLeaves(root));
    return 0;
}