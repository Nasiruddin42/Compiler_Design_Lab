#include<bits/stdc++.h>
using namespace std ;

bool isOperator(string str){
    int sz = str.size() - 1 ;
    if(str[0] == '+' or str[0] == '-' or str[0] == '*' or str[0] =='/'){
        return false ;
    }
    if(str[sz] == '+' or str[sz] == '-' or str[sz] == '*' or str[sz] =='/'){
        return false ;
    }
    for(int i = 1 ; i < sz-1; i++){
        if(str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/' or str[i] == '(' or str[i] == ')'){
            if(str[i+1] == '+' or str[i+1] == '-' or str[i+1] == '*' or str[i+1] == '/' or str[i+1] == '(' or str[i+1] ==')'){
                return false ;
            }
        }
    }
    return true ;
}
int cnt = 0 ;
bool isBracket(string str){
    stack<char> brakets ;
    for(int i = 0 ; i < str.size(); i++){
        if(str[i] == '('){
            brakets.push('(') ;
        }
        if(str[i] == ')'){
            if(brakets.size()){
                brakets.pop() ;
            }
            else{
                return false ;
            }
        }
    }
    if(brakets.size() == 0){
        return true ;
    }
    else{
        return false ;
    }
}

int main(){
    string syntax ;
    cin >> syntax ;

    if(isOperator(syntax) && isBracket(syntax)){
        cout << "Valid" << endl ;
    }
    else{
        cout << "Invalid" << endl ;
    }
}