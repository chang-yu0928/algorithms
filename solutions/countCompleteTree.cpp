#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *temp = root;
        int height = 0, count = 0, level;
        while(temp) {
            temp = temp->left;
            height ++;
        }
        temp = root;
        level = height - 2;
        cout<<level<<endl;
        while(level >= 0) {
            TreeNode *left = temp->left;
            for(int i = 0;i < level;i ++) {
                left = left->right;
            }
            if(left) {
                temp = temp->right;
                count += (1 << level);
            } else temp = temp->left;
            level --;
        }
        if(temp) count ++;
        cout<<count<<endl;
        return (1 << (height - 1)) + count - 1;
    }
    
    int main() {
    	TreeNode *root = NULL;//new TreeNode(1);
    	//root->left = new TreeNode(1);
    	//root->right = new TreeNode(1);
    	//root->left->left = new TreeNode(1);
    	//root->left->right = new TreeNode(1);
    	//root->right->left = new TreeNode(1);
    	//root->right->right = new TreeNode(1);
    	cout<<countNodes(root)<<endl;
    	return 0;
    }