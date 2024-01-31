#include<bits/stdc++.h>
using namespace std ;

int precedence(char ch){
    switch (ch)
    {
    case '^':
        return 3 ;
    case '*':
    case '/':
        return 2 ;
    case '+':
    case '-':
        return 1 ;
    default : 
        return 0 ;
    }
}

string infixtoPostfix(string infix){
    string postfix = "" ;
    stack<char> stk ;
    for(auto ch : infix){
        if(ch >= tolower('a') && ch <= tolower('z')){
           postfix += ch ;
        }
        else if(ch == '('){
            stk.push(ch) ;
        }
        else if(ch == ')'){
            while (stk.top() != '(')
            {
                postfix += stk.top() ;
                stk.pop() ;
            }
            stk.pop() ;
        }
        else if(ch != ' '){
            while(!stk.empty() && precedence(ch) <= precedence(stk.top())){
                postfix += stk.top() ;
                stk.pop() ;
            }
            stk.push(ch) ;
        }
    }
    while(!stk.empty()){
        postfix += stk.top() ;
        stk.pop() ;
    }
    return postfix ;
}

string Postfix(string infix){
    string postfix = "" , temp = "" ;
    stack<string> st ;
    for(char ch : infix){
        if(ch != ' ') temp += ch ;
        else{
            if(temp == "then"){
                temp = "" ;
                continue;
            }
            else if(temp == "if"){
                st.push(temp) ;
            }
            else if(temp == "else"){
                // while(st.top() == "else"){
                //     postfix += "?" ;
                //     st.pop() ;
                //     st.pop() ; 
                // }
                st.push(temp) ;
            }
            else{
                postfix += infixtoPostfix(temp) ;

                while(!st.empty() && st.top() == "else"){
                    postfix += "?" ;
                    st.pop() ;
                    st.pop() ;
                }
            }
            temp = "" ;
        }
    }
    while (!st.empty())
    {
        //postfix += infixtoPostfix(temp) ;
        postfix += "?";
        st.pop();
        st.pop();
    }
    return postfix ;
}

int main(){
    string infix ;
    getline(cin, infix) ;

    cout << Postfix(infix) << endl ;
}