#inlcude<iostream>
using namespace std;

class TreeNode{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
     TreeNode(int val){
         this->val = val;
     }
}

int size(TreeNode *root){
    return root == nullptr ? 0 : size(root->left) + size(root->right) + 1;
}

int height(TreeNode *root){
    return root == nullptr ? -1 : max(height(root->left), height(root->right)) + 1;
}

int maximum(TreeNode *root){
    return root == nullptr ? -(int)1e9 : max(root->val,(max(maximum(root->left),maximum(root.right)));
}

int minimum(TreeNode *root){
    return root == nullptr ? -(int)1e9 : min(root->val,(min(minimum(root->left),minimum(root.right)));
}
bool find(TreeNode *root, int data){
    if(root == nullptr){
        return false;
    }
    if(root->val == data){
        return true;
    }
    return find(root->left) || find(root.right);
}

bool rootToNodePath(TreeNode *root, int data,vector<TreeNode>& ans){
    if(root == nullptr){
        return false;
    }
    if(root.val == data){
        ans.push_back(root);
        return true;
    }
    bool res = rootToNodePath(root->left,data,ans) || rootToNodePath(root->right, data,ans);
    if(res){
        ans.push_back(root);
    }
    return res;
}

vector<TreeNode *> rootToNode(TreeNode *root, int data){
    if(root == nullptr){
        return {};
    }
    if(root->val == data){
        return {root};
    }

    vector<TreeNode *> left = rootToNode(root->left, data);
    if(left.size() != 0){
        left.push_back(root);
        return left;
    }

    vector<TreeNode *> right = rootToNode(root->right,data);
    if(right.size() != 0){
        right.push_back(root);
        return right;
    }
    return {};
}
void rootToLeafAllPath(TreeNode *root, vector<TreeNode *>& smallAns, vector<vector<TreeNode *>>&ans){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        smallAns.push_back(root);
        ans.push_back(smallAns);
        smallAns.pop_back(root); 
    }
    smallAns.push_back(root);
    rootToLeafAllPath(root.left,smallAns,ans);
    rootToLeafAllPath(root.right,smallAns,ans);
    smallAns.pop_back(root);

}

void exactlyOneChild(TreeNode *root, vector<TreeNode *>ans){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    ir(root->left == nullptr || root->right == nullptr){
        ans.push_back(root);
        return;
    }

    exactlyOneChild(root->left,ans);
    exactlyOneChild(root->right, ans);

}

int countExactlyOneChild(TreeNode *root){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return 0;
    }

    int countSingleChildLeft = countExactlyOneChild(root->left);
    int countSingleChildright = countExactlyOneChild(root->right);

    int ans = countSingleChildLeft + countSingleChildright;
    if(root->left == null || root->right == null){
        ans++;
    }
    return ans;
}

int main(){

}