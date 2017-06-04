#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct TreeNode{
	char val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(char c):val(c),left(NULL),right(NULL){}
};
TreeNode *  root;
char pre[100], in[100];
void postorder(TreeNode * root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%c",root->val);
	}
}
void conTree(TreeNode * &root, char * pre, char * in, int len){
	if(len <= 0){
		root = NULL;
		return;
	}else{
		root = new TreeNode(*pre);
		int pos = find(in, in + len, *pre) - in;
		conTree(root->left, pre + 1, in, pos);
		conTree(root->right, pre + pos + 1, in + pos + 1, len - (pos + 1));
	}
}
int main(){
	while(scanf("%s%s",pre,in) != EOF){
		int len = strlen(pre);
		conTree(root, pre, in, len);
		postorder(root);
		printf("\n");
	}
	return 0;
}
