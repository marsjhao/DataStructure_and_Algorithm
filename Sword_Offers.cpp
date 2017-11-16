//1. 二维数组中的查找
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		bool iffound = false;
		int nb_rows = array.size();
		int nb_columns = array[0].size();
		int row = 0, column = nb_columns - 1;
		if (nb_rows > 0 && nb_columns > 0) {
			while (row < nb_rows && column >= 0) {
				if (array[row][column] == target) {
					iffound = true;
					break;
				}
				else if (array[row][column]>target) --column;
				else ++row;
			}
		}
		return iffound;
	}
};

//2. 替换空格
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0) return;
		int len_str = 0;
		int nb_Blank = 0;
		char *p1 = str;
		while (*p1 != '\0') {
			++length;
			if (*p1 == ' ') ++nb_Blank;
			++p1;
		}
		int len_str_new = len_str + 2 * nb_Blank;
		if (len_str_new > length) return;
		char *p2 = p1 + 2 * nb_Blank;
		while (p1 >= str && p1 < p2) {
			if (*p1 == ' ') {
				*(p2--) = '0';
				*(p2--) = '2';
				*(p2--) = '%';
			}
			else
				*(p2--) = *p1;
			--p1;
		}
	}
};

//3. 从尾到头打印链表
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

//算法1：非递归算法
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		std::stack<ListNode*> pnodes;

		ListNode* temp = head;
		while (temp != NULL) {
			pnodes.push(temp);
			temp = temp->next;
		}

		while (!pnodes.empty()) {
			temp = pnodes.top();
			result.push_back(temp->val);
			pnodes.pop();
		}
		return result;
	}
};
//测试Git

//4. 重建二叉树
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		int inlen = in.size();
		if (inlen == 0) return NULL;
		vector<int> left_pre, right_pre, left_in, right_in;
		//创建根节点，根节点肯定是前序遍历的第一个数
		TreeNode* root = new TreeNode(pre[0]);
		//找到中序遍历根节点所在位置,存放于变量gen中
		int gen = 0;
		for (int i = 0; i < inlen; i++) {
			if (in[i] == pre[0]) {
				gen = i;
				break;
			}
		}
		//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边,利用上述这点，对二叉树节点进行归并
		for (int i = 0; i < gen; i++) {
			left_in.push_back(in[i]);
			left_pre.push_back(pre[i + 1]);//前序第一个为根节点
		}
		for (int i = gen + 1; i < inlen; i++) {
			right_in.push_back(in[i]);
			right_pre.push_back(pre[i]);
		}
		//和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
		//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
		root->left = reConstructBinaryTree(left_pre, left_in);
		root->right = reConstructBinaryTree(right_pre, right_in);
		return root;
	}
};