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

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int> > result;
        vector<int> part;
        
        if(root == NULL) return result;
        
        bool flag = false;
        TreeNode *dummy = new TreeNode(-1);
        q.push(root);
        q.push(dummy);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == dummy){
                if(flag){
                    reverse(part.begin(), part.end());
                }
                result.push_back(part);
                flag = !flag;
                part.clear();
                if(!q.empty()) q.push(dummy);
            }else{
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                part.push_back(temp->val);
            }
        }
        return result;
    }
    
int main(){
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int> > result = zigzagLevelOrder(root);
	for(int i = 0;i < result.size();i ++){
		for(int j = 0;j < result[i].size();j ++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}