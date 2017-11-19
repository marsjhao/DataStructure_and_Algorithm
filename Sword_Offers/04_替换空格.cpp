//04_Ìæ»»¿Õ¸ñ
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