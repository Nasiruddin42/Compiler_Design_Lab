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
        else{
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

int main(){
    string infix ;
    cin >> infix ;
    cout << infixtoPostfix(infix) << endl ;
    return 0 ;
}