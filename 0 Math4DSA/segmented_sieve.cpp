//Segmented sieve 
//optimized variation of sieve for very large size

#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//code of simple sieve 
void sieve(long long num , vector<long long> arr){

    vector<bool> prime(num+1,true);

    for(long long i=2;i<=num;i++){
        if(prime[i]){
            arr.push_back(i);
            for(long long j=i*i;j<=num;j++){
                prime[j]=false;
            }
        }
    }
}

//code of segmented sieve
long long segmented_sieve(long long low,long long high){
    long long count;
    vector<long long>primeNumbers ;
    
    //1. generate all prime from 0 to sqrt of high
    long long sq = floor(sqrt(high))+1;
    sieve(sq,primeNumbers);

    //crete a new array initializing all true
    vector<bool> isPrime(high-low+1,true);
    
    for(long long i:primeNumbers){
        long long sm= (low/i)*i;
        if(sm<low){
            sm+=i;
        }
        for(long long j=sm;j<=high;j+=i){
            isPrime[j-low]=false;
        }
    }
    for(long long i=low;i<=high;i++){
        if(isPrime[i-low]==true){
            count++;
        }
    }
    return count;
}


//__main__
int main(){

    long long low=2, high= 10000000000;

    long long prime = segmented_sieve(low,high);

    cout<<prime<<endl;    

    return 0;
}