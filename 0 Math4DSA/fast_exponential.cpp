//fast exponential algorithm
//using iteration method

#include<iostream>

using namespace std;

//fast exp
int exp(int x, int n){
    int ans = 1;
    while(n>0){
        if(n&1){
            ans = ans *x;
        }
        x= x*x;
        n = n>>1;
    }
    return ans;
}

int main(){

    int a=2,b=3;

    //let us assume to find a^b
    int ans = exp(a,b);
    cout<<ans<<endl;

    return 0;
}