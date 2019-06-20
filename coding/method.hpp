#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//逆波兰表达式求值，主要问题：应用棧存取数据，string 转化成 char 类型函数 s.c_str(), char转int 类型那 atio(),char 转string函数
int evalRPN(const std::vector<string> s){
	stack<int> number;
	for(int i = 0; i< s.size(); ++i){
		string s1 = s[i];
		if(s1 == "+" || s1 == "-" || s1 == "*" || s1 == "/" ){
			int a = number.top();
			number.pop();
			int b = number.top();
			number.pop();
			int c ;
			if(s1 == "+")
				c = b+a;
			else if(s1 == "-")
				c = b-a;
			else if(s1 == "*")
				c = b*a;
			else
				c = b/a;
			number.push(c);
		}
		else{
			int d = atoi(s1.c_str());
			number.push(d);
		}
	}
	int result = number.top();
	return result;
}

//大小写字母转换，对应大小写字母之间相差32  A-Z: 对应的值  65-90  a-z：97-122
//string 应用下标访问得到的是什么类型？ char的引用类型
void ChangeLetters(string &s){
	for (int i = 0; i < s.size(); ++i){
		char s1 = s[i];
		if (s1>=65&&s1<=90){
			s1+=32;
		}else{
			s1-=32;
		}
		s[i] = s1;
	}
}

//有效的括号
bool method20(string s){
	stack<char> data;
	int n = s.size();
	if(n==0)
		return true;
	if(n==1)
		return false;
	for(int i = 0; i<n;++i){
		cout<<"s1:"<<s[i]<<endl;
		char s1 = s[i];
		if(s1=='{' || s1=='(' || s1==']'){
			data.push(s1);
		}else{
			if(data.empty())
				return false;
			char s2 = data.top();
			data.pop();
			cout<<"s2:"<<s2<<endl;
			if((s2 == '{' && s1=='}')||(s2 == '[' && s1==']')||(s2 == '('&& s1==')')){
					continue;
				}
			else
				return false;
		}
	}
	if(!data.empty())
		return false;
	return true;
}
