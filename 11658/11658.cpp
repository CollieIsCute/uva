#include <iostream>
#include <string>
using namespace std;

bool isSmaller(int a[2], int b[2]){
	if(a[0] == b[0])
		return a[1] < b[1];
	return a[0]<b[0];
}

class Node{
public:
	int interger;
	int point;
}

int main(){
	int num, index;
	while (cin >> num && cin >> index && num && index){
		int min;
		string tempStock[num+1];
		Node stock;
		for(int i = 1; i <= num; i++){
			cin>>stock[i];
			twoPart[i][0] = stock[i].substr(0,2);
			twoPart[i][1] = stock[i].substr(3, 2);
		}
		
	}
}