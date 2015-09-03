#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void binaryTreePaths(TreeNode* node, string part, vector<string> &result) {
        if(!node->left && !node->right) {
            part += to_string(node->val);
            result.push_back(part);
            return;
        }
        part += (to_string(node->val) + "->");
        if(node->left) binaryTreePaths(node->left, part, result);
        if(node->right) binaryTreePaths(node->right, part, result);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string part;
        vector<string> result;
        binaryTreePaths(root, part, result);
        return result;
    }
    
    int main() { 
    	TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(5);
    	vector<string> res = binaryTreePaths(root);
    	for(int i = 0;i < res.size();i ++) {
    		cout<<res[i]<<endl;
    	}
    	return 0;
    }