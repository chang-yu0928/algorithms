#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> result;
        TreeNode *curr;
        if(root) sta.push(root);
        while(!sta.empty()) {
            curr = sta.top();
            if(!curr->left && !curr->right) {
            	result.push_back(curr->val);
            	sta.pop();
            }
            if(curr->right) sta.push(curr->right);
            if(curr->left) sta.push(curr->left);
            curr->left = NULL; curr->right = NULL;
        }
        return result;
    }
    
    int main() {
    	TreeNode *root = new TreeNode(1);
    	root->right = new TreeNode(2);
    	root->right->left = new TreeNode(3);
    	TreeNode *test;
    	vector<int> result = postorderTraversal(test);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout <<endl;
    }