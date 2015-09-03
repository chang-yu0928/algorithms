#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkBalanced(TreeNode* root) {
        if(root == NULL) {
        	return 1;
        }
        int left = checkBalanced(root->left);
        int right = checkBalanced(root->right);
        if(left && right) {
        	int diff = abs(left - right);
        	if(diff > 1) {
        		return 0;
        	} else {
        		return max(left + 1, right + 1);
        	}
        }
        return 0;
    }

    bool isBalanced(TreeNode* root) {
        if(checkBalanced(root)) return true;
        return false;
    }
    
    int main() {
    	TreeNode *root = new TreeNode(1);
    	root->left = new TreeNode(2);
    	root->left->left = new TreeNode(3);
    	cout<<isBalanced(root)<<endl;
    	return 0;
    }