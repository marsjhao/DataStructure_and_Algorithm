//1. ��ά�����еĲ���
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

//2. �滻�ո�
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

//3. ��β��ͷ��ӡ����
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

//�㷨1���ǵݹ��㷨
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
//����Git

//4. �ؽ�������
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
		//�������ڵ㣬���ڵ�϶���ǰ������ĵ�һ����
		TreeNode* root = new TreeNode(pre[0]);
		//�ҵ�����������ڵ�����λ��,����ڱ���gen��
		int gen = 0;
		for (int i = 0; i < inlen; i++) {
			if (in[i] == pre[0]) {
				gen = i;
				break;
			}
		}
		//����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�,����������㣬�Զ������ڵ���й鲢
		for (int i = 0; i < gen; i++) {
			left_in.push_back(in[i]);
			left_pre.push_back(pre[i + 1]);//ǰ���һ��Ϊ���ڵ�
		}
		for (int i = gen + 1; i < inlen; i++) {
			right_in.push_back(in[i]);
			right_pre.push_back(pre[i]);
		}
		//��shell�����˼�����ƣ�ȡ��ǰ�������������ڵ���ߺ��ұߵ�����
		//�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
		root->left = reConstructBinaryTree(left_pre, left_in);
		root->right = reConstructBinaryTree(right_pre, right_in);
		return root;
	}
};