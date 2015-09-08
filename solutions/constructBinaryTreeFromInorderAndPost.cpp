#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

	TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder, int in1, int in2, int pos1, int pos2) {
        int i;
        if(in1 > in2) return NULL;
        if(in1 == in2) return new TreeNode(inorder[in1]);
        TreeNode *root = new TreeNode(postorder[pos2]);
        for(i = in1;i <= in2;i ++) {
            if(inorder[i] == postorder[pos2]) break;
        }
        root->left = buildTree(inorder, postorder, in1, i - 1, pos1, pos1 + i - in1 - 1);
        root->right = buildTree(inorder, postorder, i + 1, in2, pos1 + i - in1, pos2 - 1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    void printTree(TreeNode *root) {
    	if(root == NULL) return;
    	printTree(root->left);
    	cout<<root->val<<" ";
    	printTree(root->right);
    }
    
    int main() {
    	int in[] = {7,4,2,5,1,6,3};
    	int pos[] = {7,4,5,2,6,3,1};
    	vector<int> inorder(in, in + sizeof(in)/sizeof(int));
    	vector<int> postorder(pos, pos + sizeof(pos)/sizeof(int));
        TreeNode *root = buildTree(inorder, postorder);
        printTree(root);
        return 0;
    }