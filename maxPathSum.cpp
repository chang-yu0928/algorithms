int maxPathSum(TreeNode* root) {
        int left = maxPathSum(root->left);
        int right = maxPathSum(root->right);
        int mid = maxPath(root->left) + maxPath(root->right);
        if(left > right) {
            return max(left, mid + root->val);
        } else {
            return max(right, mid + root->val);
        }
    }
    
    int maxPath(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        } else {
            int left = -1, right = -1;
            if(root->left != NULL) {
                left = maxPath(root->left);
            }
            if(root->right != NULL) {
                right = maxPath(root->right);
            }
            if(root->val > 0) {
                if(left + val > val) {
                    return max(left+val, right+val);
                } else {
                    return max(val, right+val);
                }
            } else {
                if(left > val) {
                    return max(left, right);
                } else {
                    return max(val, right);
                }
            }
        }
    }