#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;
        TreeNode *curr = root;
        path1.push_back(curr);
        while(curr->val != p->val) {
            if(curr->val > p->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
            path1.push_back(curr);
        }
        curr = root;
        path2.push_back(curr);
        while(curr->val != q->val) {
            if(curr->val > q->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
            path2.push_back(curr);
        }
        
        for(int i = 0;i < min(path1.size(), path2.size());i ++) {
            if(path1[i] != path2[i]) {
                return path1[i-1];
            }
        }
        if(path1.size() > path2.size()) {
            return path2[path2.size()-1];
        } else {
            return path1[path1.size()-1];
        }
    }
    
    
    int main() { 
    	TreeNode *root = new TreeNode(2);
    	root->left = new TreeNode(1);
    	
    	TreeNode *res = lowestCommonAncestor(root, root, root->left);
    	cout<<res->val<<endl;
    	return 0;
    }