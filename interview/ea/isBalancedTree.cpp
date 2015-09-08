#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

int s, l;
void treeHeight(TreeNode *root, int length) {
    if(!root->left && !root->right) {
        s = min(s, length + 1);
        l = max(l, length + 1);
        return;
    }
    if(root->left) treeHeight(root->left, length + 1);
    if(root->right) treeHeight(root->right, length + 1);
}

bool isBalanced(TreeNode *root) {
    s = INT_MAX; l = INT_MIN;
    treeHeight(root, 0);
    if(l - s >= 2) return false;
    else return true;
}

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(3);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(2);

    cout<<isBalanced(root)<<endl;
    return 0;
}
