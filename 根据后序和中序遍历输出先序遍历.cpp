#include <iostream>  
#include <vector>  
using namespace std;
vector<int> post, in, pre;
int k = 0;
void GetPre(int root, int start, int end) {
	if (start > end) return;
	int i = start;
	while (i < end && in[i] != post[root]) i++;
	//pre[k++] =  post[root] ;  
	pre.push_back(post[root]);
	GetPre(root - 1 - end + i, start, i - 1);
	GetPre(root - 1, i + 1, end);
}
int main() {
	int N;
	cin >> N;
	post.resize(N);
	in.resize(N);
	//pre.resize(N);指定大小的vector不能使用push_back   
	for (int i = 0; i < N; i++)
		cin >> post[i];
	for (int i = 0; i < N; i++)
		cin >> in[i];
	GetPre(N - 1, 0, N - 1);
	cout << "Preorder: " << pre[0];
	for (int i = 1; i < N; i++)
		cout << " " << pre[i];
	return 0;
}