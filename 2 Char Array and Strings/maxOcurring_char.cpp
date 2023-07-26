#include <iostream>

using namespace std;

char maxCharOccuring(string s){

    int arr[26] = {0};

    for(int i=0; i<s.length();i++){
        char ch = s[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z'){
            number = ch - 'a';
        }
        else {
            number = ch - 'A';
        }

        arr[number]++;
    }

    int max = -1, index = 0;
    for(int i =0;i<26;i++){
        if(max<arr[i]){
            index= i;
            max = arr[i];
        }
    }

    char ans = 'a'+index;

    return ans;    

}

int main() {

    string sen;
    cin>>sen;

    char ans = maxCharOccuring(sen);

    cout<<"Max Occuring is : "<<ans<<endl;

    return 0;
}