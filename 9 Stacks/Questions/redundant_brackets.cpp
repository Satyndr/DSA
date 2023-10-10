#include <bits/stdc++.h> 
#include <stack>
#include <string>

using namespace std;

bool findRedundantBrackets(string &s)
{

    stack<char> st;

    for(int i=0 ; i<s.length() ; i++){
        char ch = s[i];

        if( ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{

            if( ch==')' ){
                bool isRedundant = true;
                
                while( st.top() != '(' ){
                    char top = st.top();
                    if( top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){

    string S = "((a/b))";

    if( findRedundantBrackets(S) ){
        cout<<"This has redundant Brackets. "<<endl;
    }
    else{
        cout<<"No redundant Brackets." <<endl;
    }

    return 0;
}

