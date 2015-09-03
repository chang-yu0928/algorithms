#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

	vector<vector<int> > levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> que;
        vector<vector<int> > result;
        vector<int> part;
        TreeNode *guard = new TreeNode(0);
        if(root) {
            que.push(root);
            que.push(guard);
        }
        while(!que.empty()) {
            TreeNode *curr= que.front();
            if(curr == guard) {
                result.insert(result.begin(), part);
                part.clear();
                que.pop();
                if(!que.empty()) {
                    que.push(guard);
                }
                continue;
            }
            if(!curr->left && !curr->right) {
                part.push_back(curr->val);
                que.pop();
                continue;
            }
            if(curr->left) {
                que.push(curr->left);
                curr->left = NULL;
            }
            if(curr->right) {
                que.push(curr->right);
                curr->right = NULL;
            }
        }
        return result;
    }
    
    int main() {
    	TreeNode *root = new TreeNode(1);
    	root->right = new TreeNode(2);
    	root->right->left = new TreeNode(3);
    	
    	vector<vector<int> > result = levelOrderBottom(root);
    	for(int i = 0;i < result.size();i ++) {
            for(int j = 0;j < result[i].size();j ++) {
    		  cout<<result[i][j]<<" ";
            }
            cout<<endl;
    	}
    	return 0;
    }