#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool function1_0(std::vector<std::vector<int> > s, int target){
	for(int i=0;i<s.size();++i){
		int left = 0, right = s[i].size()-1;
		while(left<=right){
			int mid = (left+right)/2;
			if(s[i][mid] == target)
				return true;
			else if(s[i][mid]>target){
				right = mid-1;
			}else{
				left = mid+1;
			}
		}
	}
	return false;
}
bool function1_1(std::vector<std::vector<int> > s, int target){
	int m = s.size()-1, n = s[0].size()-1;
	int i = m, j=0;
	while(i>=0 && j<=n){
		if (s[i][j] == target)
		{
			return true;
		}
		else if(s[i][j]>target)
			i--;
		else
			j++;
	}
	return false;

}
int main(){
	std::vector<int> s1 = {1,2,3,4,5,6};
	std::vector<int> s2 = {2,3,4,5,6,7};
	std::vector<int> s3 = {3,4,5,6,7,8};
	std::vector<std::vector<int> > s;
	s.push_back(s1);
	s.push_back(s2);
	s.push_back(s3);
	int target = 4;
	bool flag = function1_1(s,target);
	cout<<flag<<endl;
}
