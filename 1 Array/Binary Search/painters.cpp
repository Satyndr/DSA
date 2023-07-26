/*there are n=2 painters and 5,5,5,5 painting boards
one painting board take one unit time to paint
find the minimum time
painter can paint in only continiuous manner */

#include <iostream>
using namespace std;

int isPossible(int arr[],int n, int k, int mid){
    int paintingCount = 1;
    int paintingSum= 0;

    for(int i=0;i<n;i++){
        if ( paintingSum + arr[i] <= mid){
            paintingSum += arr[i];
        }
        else{
            paintingCount++;
            if(paintingCount>k || arr[i] > mid){
                return false;
            }
            paintingSum = arr[i];
        }
    }
    return true;
}

int paint(int arr[],int n,int k){
    int s=0;
    int sum =0;

    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int e= sum;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(isPossible(arr,n,k,mid)){
            ans = mid;
            e = mid -1;
        }
        else{
            s= mid +1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {

    int arr1[4]={5,5,5,5};
    int painter = 2;

    cout<<paint(arr1, 4, painter);

    return 0;
}