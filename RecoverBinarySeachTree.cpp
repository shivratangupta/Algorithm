void correctBST(TreeNode* root, TreeNode* first, TreeNode* temp, TreeNode* last, TreeNode* prev){
	if(root == NULL)
		return;

	corectBST(root->left, first, temp, last, prev);

	if(prev != NULL && prev->val > root->val){
		if(first == NULL){
			first = prev;
			temp = root;
		}

		else
			last = root;
	}

	prev = root;

	correctBST(root->right, first, temp, last, prev);
}

void recoverTree(TreeNode* root){
	TreeNode *first, *last, *temp, *prev;
	first = NULL;
	last = NULL;
	temp = NULL;
	prev = NULL;

	correctBST(root, first, temp, last, prev);

	if(first != NULL && last != NULL){
		int temp1;
		temp1 = first->val;
		first->val = last->val;
		last->val = temp1;
	}

	else if(first != NULL && temp != NULL){
		int temp1;
		temp1 = first->val;
		first->val = temp->val;
		temp->val = temp1;
	}
}