#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	int n;
	cin>>n;
	cin.ignore();
	string str;
	cin>>str;
	int flagv=0;
	int flagn=0;
	int countv=0;
	int countn=0;
	vector <int> w;
	vector <int> m;
	for(int i=0;i<n;i++){
		if(str[i]=='v' || str[i]=='w')
			flagv=1;
		while(i<n && (str[i]=='v' || str[i]=='w')){
			if(str[i]=='v'){			
			countv++;
			i++;
			}else if(str[i]=='w'){
			countv+=2;
			i++;
			}
			flagv=0;
		}
		cout<<"count v:"<<countv<<endl;
		w.push_back(countv);
		countv=0;	
	}
	/*	if(str[i]=='n' || str[i]=='m')
			flagn=1;
		while(i<n && (str[i]=='n' || str[i]=='m')){
			if(str[i]=='n'){			
			countn++;
			i++;
			}else if(str[i]=='m'){
			countn+=2;
			i++;
			}
		}
		cout<<"countn:"<<countn<<endl;
		m.push_back(countn);
		countn=0;
	}
	
	*/
	int ans1=0;
	int ans2=0;
	int ans3=0;
	int ans4=0;
	while(!w.empty()){
		int temp=w.back();
		if(temp%2==0)
		ans1+=(temp/2);
		else
		ans1+=((temp/2)+1);
		ans3+=temp;
	w.pop_back();
	}
/*	while(!m.empty()){
		int temp=m.back();
		if(temp%2==0)
		ans2+=(temp/2);
		else
		ans2+=((temp/2)+1);
		ans4+=temp;
	m.pop_back();
	}
*/
	int mx=0;
	int mn=0;
	int others=0;
	for(int i=0;i<n;i++){
		if(str[i]!='v' && str[i]!='w' )//&& str[i]!='n' && str[i]!='m')
			others++;
	}
	mx=others+ans3+ans4;
	mn=others+ans1+ans2;
			cout<<mn<<" "<<mx<<endl;
}
