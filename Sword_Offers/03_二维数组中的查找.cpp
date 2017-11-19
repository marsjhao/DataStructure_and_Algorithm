//03_二维数组中的查找
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