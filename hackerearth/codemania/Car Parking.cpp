#include <iostream>
using namespace std;
////---B--S-D- - S - -
////012345678910111213
int main()
{
string str;
cin>>str;
int n=str.size();
int count=0;
for(int i=0;i<n;i++){
	int f1=-1,f2=-1,f3=-1,f4=-1;

		if(str[i]=='-'){
			if(i+1<n){

			f1=0;
			if( str[i+1]!='B' && str[i+1]!='S')
			f1=1;
			}

			if(i+2<n){

				f2=0;
				if(str[i+2]!='B' ){
					f2=1;

				}
			}
			if(i-1>=0){
				f3=0;
						if(  str[i-1]!='S'){
							f3=1;
						}
			}


			if((f1==1 || f1==-1) && (f2==1 || f2==-1) && (f3==1 || f3==-1) ){
			count++;
			//cout<<i<<endl;
			}
			}

		}
		cout<<count<<endl;
}

