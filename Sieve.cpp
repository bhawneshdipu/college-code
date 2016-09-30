#include<bits/stdc++.h>
using namespace std;
vector <int> sieve(int N) {
    vector <int> ans;
    bool isPrime[N+1];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
                ans.push_back(i);
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }
    for(int i=ans[ans.size()-1]+1;i<N;i++){

        if(isPrime[i]==true)
            ans.push_back(i);
    }
    return ans;
}
int main(){
    vector <int> v=sieve(100000);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;;

    }

}

