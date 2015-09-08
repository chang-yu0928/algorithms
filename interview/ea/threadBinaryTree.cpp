#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    bool tLeft, tRight;
    TreeNode *left, *right;
    TreeNode(int n) : val(n), tLeft(false), tRight(false), left(NULL), right(NULL) {}
};

void threadize(TreeNode *root, TreeNode **pre) {
    if(!root) return;
    threadize(root->left, pre);
    if(!root->left) root->tLeft = true;
    if(!root->right) root->tRight = true;
    if(*pre) {
        if((*pre)->tRight) (*pre)->right = root;
        if(root->tLeft) root->tLeft = pre;
    }
    *pre = root;
    threadize(root->right, pre);
}

void travsal(TreeNode *root) {
    TreeNode *curr = root;
    while(curr->left) {
        curr = curr->left;
    }
    while(curr) {
        cout<<curr->val<<" ";
        if(curr->tRight) {
            curr = curr->right;
        } else {
            curr = curr->right;
            while(curr->left) {
                curr = curr->left;
            }
        }
    }
    cout<<endl;
}

int main() {
    TreeNode* root = new TreeNode(4);
    TreeNode* pre = NULL;
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    threadize(root, &pre);
    travsal(root);
    return 0;
}
