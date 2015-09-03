#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        cout<<left<<","<<right<<endl;
        if(left == 0 && right == 0) {
            return 1;
        } else if(left == 0) {
            return (right + 1);
        } else if(right == 0) {
            return (left + 1);
        } else {
            return min(left, right) + 1;
        }
    }
    
    int main() {
    	TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(4);
    	//root->left = new TreeNode(2);
    	//root->left->left = new TreeNode(3);
    	cout<<minDepth(root)<<endl;
    	return 0;
    }