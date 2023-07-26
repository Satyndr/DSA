//reverse the words of a string
//My name is Love -> yM eman si evoL


// this is not working


#include <iostream>
#include <string>

using namespace std;

void reverseString(string& str)
{
    int n = str.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void reverse (string sentance){
    int size = sentance.length();

    string finalSentance;

    while(size != finalSentance.length()){
        string word = "";
        cout<<finalSentance.length();

        int i = finalSentance.length()-1;
        for(i;i<size;i++){
            word.push_back(sentance[i]);
            if(sentance[i]==' ' || sentance[i]=='\0'){
                break;
            }
        }
        reverseString(word);
        cout<<word<<endl;
        finalSentance = finalSentance + " " + word;
    }
}

int main(){
    
    string word = "My name is Love";
    cout<<word<<endl;

    reverse(word);

    cout<<word<<endl;
}