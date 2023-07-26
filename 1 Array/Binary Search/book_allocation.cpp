/*book allocation program 
suppose a array containing pages of books like{10,20,30,40}
we have to distribute books to m=2 students
conditions-
-every book must be given
-each student shouid get at least one book
-book allocation should be in contigious manner
*/

#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int studentCout = 1;
    int pageSum = 0;

    for(int i=0;i<n;i++){
        if( pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCout++;
            if( studentCout > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int search(int arr[],int n,int m){
    int s= 0;
    int sum =0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){

    int arr1[5]={10,20,30,40};//array of books
    
    cout<<search(arr1,5,2);//let us assume 2 students

    return 0;
}