//add two numbers present in the vector
//arr1 = 1,2,3,4
//arr2 =   1,1,1
//sum  = 1,3,4,5

//-----------------this code is not working---------------------

#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseVector(vector<int> vect){
    int s= 0;
    int e = vect.size()-1;

    while(s<=e){
        swap(vect[s++], vect[e--]);
    }
    return vect;
}

vector<int> printVector(vector<int> v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

//function for adding
vector<int> addNumber(vector<int> arr1, vector<int> arr2, vector<int> ans){
    int n2 = arr1.size();
    int n1 = arr2.size();

    int i=n1-1;//arr1
    int j=n2-1;//arr2
    int carry =0 ;

    while(i>=0 && j>=0){
        int val1 = arr1[i--];
        int val2 = arr2[j--];

        int sum = val1+val2+carry;
        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum); 
       
    }

    //first case
    while(i>0){
        int sum = arr1[i--] +carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    //second case
    while(j>0){
        int sum = arr1[j--] +carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    reverseVector(ans);
    
}

int main() {

    vector<int> vec1{1,2,3,4};
    vector<int> vec2{1,1,1};
    vector<int> sum;

    cout<<"First Vector: ";
    printVector(vec1);
    cout<<"Second Vector: ";
    printVector(vec2);

    addNumber(vec1, vec2, sum);

    cout<<"Sum Vector: ";
    printVector(sum);

    return 0;
}