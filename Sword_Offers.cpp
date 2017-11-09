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
