#include<iostream>
#include<stack>

using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;

    for(int i=0 ; i<s.length() ; i++){

        char element = s[i];

        if( element == '(' || element =='{' || element=='[' ){
            st.push(element);
        }

        else{

            if (!st.empty()) {

              char top = st.top();
              if ((top == '(' && element == ')') ||
                  (top == '{' && element == '}') ||
                  (top == '[' && element == ']')) {
                st.pop();
              } 
              else {
                return false;
              }

            } 
            else {
              return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string name = "([[{{[[][]{{()[({})()]}}]}}]({})[]()])()({}(()))[[{}]][]()(())[[[]][({{}}{})([([(([]))]()[{[({()()})[[][{}]]]()[([{}([]{})()]{}{[[]()]})]}(){}])]){([])()}[]]]({})[[]{()}()]({[[{}({}[])[(){}{}{}[]({}{{}{[]}()[](())})]]]})";
    
    if(isValidParenthesis){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}