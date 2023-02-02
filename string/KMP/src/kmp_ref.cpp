#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/*递归求解next数组*/
void get_next_arr_2(const string& ss, vector<int>& next)
{
	next[0] = -1; // next[0]定义为-1
	next[1] = 0; // next[1]肯定是0
	int k;
	for (int j = 2; j < ss.size(); ++j) {
		k = next[j - 1];
		if (k == -1) {
			next[j] = 0;
			continue;
		} else {
			while ((ss[j-1] != ss[k]) && (k != -1)) {k = next[k];}
			next[j] = (ss[j - 1] == ss[k]) ? (k + 1) : 0;
		}
	}
}

/*暴力求解next数组*/
void get_next_arr(const string& ss, vector<int>& next)
{
	// next[i]的求解方法是，找到从ss[0]~ss[i-1]的公共最长匹配前缀和后缀的长度
	next[0] = -1; // next[0]定义为-1
	next[1] = 0; // next[1]肯定是0
	// 只要待匹配串还没到底，都要求相应位的next[i]值
	for (int i = 2;i < ss.size(); ++i) {
		int max_len = i - 1; // 最长长度为i-1
		int len,j;
		for (len = max_len; len >= 1; --len) { // 从最长的情况开始搜索
			for (j = 0; j < len; ++j) {
				if(ss[j] != ss[j + i - len]) // 只要有任何一位不对应相等，那么当前len就不成立，试探下一个len 
					break;
			}
			// 如果上一个循环是正常退出，即都对应相等了，那就把当前的len赋给next[i],并不再往下试探了
			if(j == len) {
				next[i] = len;
				break;
			}
		}
		if (len < 1) // 如果len=1的情况都不成立，那next[i]肯定是0了
		next[i] = 0;
	}
}

int KMP_match(const string& ms, const string& ss)
{
	// 先求待匹配串的next集合
    vector<int>next(ss.size());
	get_next_arr_2(ss, next);
	for_each(next.begin(),next.end(),[](int val){
		cout<<val<<" ";
	});cout<<endl;
	// 再开始匹配，匹配时，在搜索串中的下标不回溯，在待匹配串中的下标根据下标j和对应的next[j]进行回溯
	int i = 0, j = 0;
	while ((i < ms.size()) && (j < ss.size())) {
		if (ms[i] == ss[j]) { // 如果匹配，继续往下搜索
			++i;
			++j;
		} else { // 否则的话，更新索引j
			j = next[j];
			// 注意处理一下-1的情况
			if (j == -1) {
				++i;
				++j;
			}
		}		
	}

	return (j == ss.size()) ? (i - ss.size()) : -1; // 如果匹配到了最后，那就是匹配成功，返回串首的下标
}

int main()
{
	string ms = "abcdabbcdabcdabd";
	string ss = "abcdabd";
	cout<<KMP_match(ms,ss);

	return 0;
}