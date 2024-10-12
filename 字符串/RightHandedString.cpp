// 版本一
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n=2;
	string s="abcdefg";
//	cin >> n;
//	cin >> s;
//	int len = s.size(); //获取长度

	reverse(s.begin(), s.end()); // 整体反转
	reverse(s.begin(), s.begin() + n); // 先反转前一段，长度n
	reverse(s.begin() + n, s.end()); // 再反转后一段

	cout << s << endl;

}
//
//// 版本二
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	int n;
//	string s;
//	cin >> n;
//	cin >> s;
//	int len = s.size(); //获取长度
//	reverse(s.begin(), s.begin() + len - n); // 先反转前一段，长度len-n ，注意这里是和版本一的区别
//	reverse(s.begin() + len - n, s.end()); // 再反转后一段
//	reverse(s.begin(), s.end()); // 整体反转
//	cout << s << endl;
//
//}
