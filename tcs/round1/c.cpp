#include<bits/stdc++.h>
using namespace std;
vector <bool> sieve(int N) {
    vector <int> ans;
    vector <bool> isPrime(N+1);
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
                ans.push_back(i);
             for(int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }
    for(int i=ans[ans.size()-1]+1;i<N;i++){

        if(isPrime[i]==true)
            ans.push_back(i);
    }
    return isPrime;
}

int main(){
    long long int n;
    cin>>n;
    vector <bool> v=sieve(n);
    int ans=0;
    long long int sum=5;
    for(int i=5;i<v.size();i++){

        if(sum<=n and v[sum]==true and v[i]==true){
            ans++;
            //cout<<"sum---------->"<<sum<<endl;
        }
        if(v[i]==true){
            sum+=i;
            //cout<<"added-->"<<i<<endl;
            v[sum]==false;
        }
    }
    cout<<ans<<endl;
    return 0;
}
