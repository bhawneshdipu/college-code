#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
class Object{
public:
	string s;
	int n;
	bool b;
};
int main(){
	int n;
	printf("Enter Length of Vector\n");
	scanf("%d",&n);
	vector <int> vi; // vector of integers
	
	vector <string> vs;// vector of strings
	
	vector < vector < int > > vvi;//vector of (vector of integers) 
	
	vector < Object > vo; // vector of object

	for(int i=0;i<n;i++){
		int a;
		printf("enter integer \n");
		scanf("%d",&a);
		vi.push_back(a);
	}
	
	for(int i=0;i<n;i++){
		string a;
		printf("enter string \n");
		cin>>a;
		vs.push_back(a);
	}
	
		for(int i=0;i<n;i++){
			 vector <int> a;int m;
			printf("enter length of vector\n");
			scanf("%d",&m);
			for(int j=0;j<m;j++){
			int tt;
			printf("enter integer \n");
			scanf("%d",&tt);
			a.push_back(tt);
			}
		vvi.push_back(a);
		}
	
		for(int i=0;i<n;i++){
			Object a;
			printf("enter string number boolean \n");
			cin>>a.s>>a.n>>a.b;
			vo.push_back(a);
		}
	
		
vector <int> :: iterator  it;
vector <string> :: iterator is;
vector < vector <int> >  :: iterator iit;
vector <Object> :: iterator ot;

	for(it=vi.begin();it!=vi.end();++it){
		cout<<*it<<endl;
	}
	for(is=vs.begin();is!=vs.end();++is){
		cout<<*is<<endl;
	}
	for(iit=vvi.begin();iit!=vvi.end();++iit){
		vector <int> v=*iit;
		for(it=v.begin();it!=v.end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
	
	for(ot=vo.begin();ot!=vo.end();ot++){
		Object o=*ot; 
		cout<<o.s<<" "<<o.n<<" "<<o.b<<endl;
	}
	
		
		
	
}
