#include<iostream>
#define ll long long
using namespace std;

int main(){
	ll super = 1, female, male;
	int N = 0;
	cin>>N;
	while(N != -1){
		female = 0;
		male = 0;
		ll tempFemale;
		for(int i = 0; i < N; i++){
			tempFemale = female;
			female = male;
			male = super + tempFemale + male;
		}
		//cout<<super<<" "<<male<<" "<<female<<endl;
		ll total = super + male + female;
		cout<<male<<" "<<total<<endl;
		cin>>N;
	}
}