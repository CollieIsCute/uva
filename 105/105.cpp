#include <iostream>
using namespace std;

const int MAXHEIGHT = 10010;

int main(){
	int roadHeight [MAXHEIGHT] = {};
	int L,H,R;
	while(cin>>L>>H>>R){
		for(int i = L; i < R; i++){
			roadHeight[i] = max(roadHeight[i], H);
		}
	}
	int now = -1;
	for(int i = 1; i < MAXHEIGHT; i++){
		if(roadHeight[i] != now){
			if(i != 1){
				cout<<" ";
			}
			now = roadHeight[i];
			cout<<i<<" "<<now;
		}
	}
	cout<<endl;
}