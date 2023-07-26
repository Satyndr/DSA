//remove spaces from a sentance and add @40 in it

#include <iostream>
#include <string>

using namespace std;

string removeSpace(string str){

    int len = str.length();

    for(int i=0;i<len;i++){
        if(str[i] = ' '){
            str.erase(i+1,i+2);
        }
        cout<<str<<endl;
    }
    return str;

}

/*
string removeSpace(string str){

    int len = str.length();
    string temp;
    int j=0;
    for(int i=0;i<len;i++){
        if(str[i] != ' '){
            temp.push_back(str[i]);
        }
        else{
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
    }
    return temp;
}
*/


int main() {
    string str;
    cout<<"Enter a Sentance: ";

    getline(cin,str);

    string str2 = removeSpace(str);

    cout<<"After removing spaces: "<<str2<<endl;
}