#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *node1;
TreeNode *node2;
TreeNode *node;

void findTarget(TreeNode* root) {
        if(!root) return;
        findTarget(root->left);
        if(node && root->val < node->val) {
            if(!node1) {
            	node1 = node;
            	node2 = root;
            } else {
            	node2 = root;
            } 
        }
        node = root;
        findTarget(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        node1 = NULL;
        node2 = NULL;
        node = NULL;
        findTarget(root);
        cout<<node1->val<<", "<<node2->val<<endl;
        swap(node1->val, node2->val);
    }
    
    void printTree(TreeNode *root) {
    	if(root->left) printTree(root->left);
    	cout<<root->val<<" ";
    	if(root->right) printTree(root->right);
    }
    
    int main() {
    	TreeNode *root = new TreeNode(3);
    	root->left = new TreeNode(4);
    	root->right = new TreeNode(8);
    	root->left->left = new TreeNode(6);
    	root->left->right = new TreeNode(5);
    	root->right->left = new TreeNode(7);
    	root->right->right = new TreeNode(9);
    	recoverTree(root);
    	printTree(root);
    }