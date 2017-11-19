//05_��β��ͷ��ӡ����
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