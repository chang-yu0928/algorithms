#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

	vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> sta;
        vector<int> result;
        sta.push(root);
        while(!sta.empty()) {
            TreeNode *curr = sta.top();
            if(curr->left != NULL) {
                sta.push(curr->left);
                curr->left = NULL;
            } else {
                sta.pop();
                result.push_back(curr->val);
                if(curr->right != NULL) {
                    sta.push(curr->right);
                }
            }
        }
        return result;
    }
    
    int main() {
    	TreeNode *root = new TreeNode(1);
    	root->right = new TreeNode(2);
    	root->right->left = new TreeNode(3);
    	
    	vector<int> result = inorderTraversal(root);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }