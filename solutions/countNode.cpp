#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

	int countLeaf(TreeNode *root, int level, int depth) {
        if(level == depth - 1) {
            if(root->left != NULL && root->right != NULL) {
                return 2;
            } else if(root->left == NULL && root->right == NULL) {
                return 0;
            } else {
                return 1;
            }
        } else {
            int sum = countLeaf(root->left, level + 1, depth);
            if(sum < pow(2, depth - level - 1)) {
                return sum;
            } else {
                return (sum + countLeaf(root->right, level + 1, depth));
            }
        }
    }

    int countNodes(TreeNode* root) {
        TreeNode *p = root;
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }
        int depth = 0;
        while(p->left != NULL) {
            p = p->left;
            depth ++;
        }
        cout<<depth<<endl;
        return pow(2, depth - 1) + countLeaf(root, 0, depth);
    }
    
  	int main() {
  		TreeNode *root = new TreeNode(1);
  		root->left = new TreeNode(2);
  		root->right = new TreeNode(3);
  		cout<<countNodes(root)<<endl;
  		return 0;
  	}