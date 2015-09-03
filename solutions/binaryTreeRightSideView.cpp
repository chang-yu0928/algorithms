#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
        bool nextLevel = true;
        TreeNode *guard = new TreeNode(0), *curr;
        queue<TreeNode *> que;
        vector<int> result;
        que.push(root);
        que.push(guard);
        while(!que.empty()) {
            curr = que.front();
            que.pop();
            if(curr == guard) {
                nextLevel = true;
                if(!que.empty()) que.push(guard);
                continue;
            }
            if(nextLevel) {
                result.push_back(curr->val);
                nextLevel = false;
            }
            if(curr->right) que.push(curr->right);
            if(curr->left) que.push(curr->left);
        }
        return result;
    }
    
    int main() {
    	TreeNode *root = new TreeNode(1);
    	root->left = new TreeNode(2);
    	root->right = new TreeNode(3);
    	root->left->right = new TreeNode(5);
    	//root->right->left = new TreeNode(4);
    	
    	vector<int> result = rightSideView(root);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }