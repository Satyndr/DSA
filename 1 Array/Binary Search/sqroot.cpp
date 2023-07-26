//print the square root of number ,, if not perfect sqaure , print the closest one
//used long long int for maximum interger values
#include <iostream>
using namespace std;

long long int sqroot_integer(int n){
    int s = 0, e = n-1;
    long long int mid = s + (e-s)/2;
    int ans=-1;

    while (s<=e){
        if ( mid*mid > n){
            e = mid-1;
        }
        else if( mid*mid < n) {
            ans = mid;
            s= mid + 1;
        }
        else if (mid*mid==n){
            return mid;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

double sqroot_precesion(int number, int digits, int tempSol){

    double factor = 1;
    double ans = tempSol;

    for (double i=0 ; i<digits ; i++){
        factor = factor/10;
        for(double j=ans; j*j<number ; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int number;
    cout<<"Enter number to find the Sqare root of: ";
    cin>>number;

    cout<<sqroot_integer(number)<<endl;
    cout<<sqroot_precesion(number,3,sqroot_integer(number));

    return 0;
}