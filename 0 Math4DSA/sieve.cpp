//sieve of eratothenes
//return number of prime in range

#include<iostream>

using namespace std;

int checkPrime(int num ){

    bool prime[num+1] = {true};
    int count=0;

    prime[0] = prime[1] = false;

    for(int i=2;i<num;i++){
        if(prime[i]){
            count++;
            for(int j=2*i;j<=num;j++){
                prime[j]=false;
            }
        }
    }
    return count;

}

int main(){

    int num = 100;
    int prime = checkPrime(num);
    cout<<"Number of prime numbers in range is: "<<prime<<endl;

    return 0;
}
