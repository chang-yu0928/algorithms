#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int n): val(n), left(NULL), right(NULL) {}
};

void printkdistanceNodeDown(TreeNode *root, int k)
{
    if (root == NULL || k < 0)  return;
 
    if (k==0)
    {
        cout << root->val << endl;
        return;
    }
 
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(TreeNode* root, TreeNode* target , int k)
{
    if (root == NULL) return -1;

    if (root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);

    if (dl != -1)
    {
         if (dl + 1 == k)
            cout << root->val << endl;
         else
            printkdistanceNodeDown(root->right, k-dl-2);
         return 1 + dl;
    }

    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->val << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }
    return -1;
}

int main()
{
    /* Let us construct the tree shown in above diagram */
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    TreeNode *target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
