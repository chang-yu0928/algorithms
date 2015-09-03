#include <iostream>
#include <vector>

using namespace std;

	struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int n): val(n), left(NULL), right(NULL) {}
    };
    void insertTree(TreeNode *root, int n) {
        if(root == NULL) {
            root = new TreeNode(n);
        } else {
            if(n < root->val) {
                if(root->left != NULL)
                    insertTree(root->left, n);
                else
                    root->left = new TreeNode(n);
            } else {
                if(root->right != NULL)
                    insertTree(root->right, n);
                else
                    root->right = new TreeNode(n);
            }
        }
    }
    TreeNode *deleteTree(TreeNode *root) {
    	if(root->left == NULL && root->right == NULL) {
    		delete root;
    		return NULL;
    	} else if(root->left == NULL) {
    		TreeNode *tmp = root->right;
    		delete root;
    		return tmp;
    	} else if(root->right == NULL) {
    		TreeNode *tmp = root->left;
    		delete root;
    		return tmp;
    	} else {
    		root->val = root->right->val;
    		root->right = deleteTree(root->right);
    		return root;
    	}
    }
    TreeNode *deleteTree(TreeNode *root, int n) {
    	if(root == NULL)
    		return NULL;
    	if(root->val < n) {
    		root->right = deleteTree(root->right, n);
    		return root;
    	} else if(root->val > n) {
    		root->left = deleteTree(root->left, n);
    		return root;
    	} else {
    		return deleteTree(root);
    	}
    }
    bool searchTree(TreeNode *root, int n, int m) {
    	if(root == NULL) {
    		return false;
    	}
        if(abs(root->val - n) <= m) {
            return true;
        } else {
            if(root->val < n) {
                return searchTree(root->right, n, m);
            } else {
                return searchTree(root->left, n, m);
            }
        }
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() == 0) {
            return false;
        }
        TreeNode *root = new TreeNode(nums[0]);
        for(int i = 1;i < nums.size();i ++) {
            if(i > k) {
                root = deleteTree(root, nums[i - k - 1]);
            }
            if(searchTree(root, nums[i], t)) {
                return true;
            }
            insertTree(root, nums[i]);
        }
        return false;
    }
    
int main() {
	vector<int> input;
	input.push_back(0);
	input.push_back(10);
	input.push_back(22);
	input.push_back(15);
	input.push_back(0);
	input.push_back(5);
	input.push_back(22);
	input.push_back(12);
	input.push_back(1);
	input.push_back(5);
	cout<<containsNearbyAlmostDuplicate(input, 3, 3)<<endl;
	return 0;
}