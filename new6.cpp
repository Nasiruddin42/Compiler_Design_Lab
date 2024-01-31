#include<bits/stdc++.h>
using namespace  std ;

bool isCharacterVariable(string str){
    bool mark = true ;
    if(str[0] == 'c' && str[1] == 'h' && str[2] == '_' && (isdigit(str[3]) || isalpha(str[3]))){
        for(int i = 4; i < str.size(); i++){
            if(isdigit(str[i]) || isalpha(str[i])){
                mark = true ;
            }
            else{
                mark = false ;
            }
        }
        return mark ;
    }
    return false ; 
}
bool isBinaryVariable(string str){
    bool mark = true ;
    if(str[0] == 'b' && str[1] == 'n' && str[2] == '_' && (isdigit(str[3]) || isalpha(str[3]))){
        for(int i = 4; i < str.size(); i++){
            if(isdigit(str[i]) || isalpha(str[i])){
                mark = true ;
            }
            else{
                mark = false ;
            }
        }
        return mark ;
    }
    return false ;
}
bool isBinaryNumber(string str){
    bool mark = true ;
    if(str[0] != '0' && str.size() < 2){
        mark = false ;
    }
    if(str[1] != '0' && str[1] != '1'){
        mark = false ;
    }
    for(int i = 2; i < str.size(); i++){
        if(str[i] != '0' && str[i] != '1'){
            mark = false ;
            break;
        }
    }
    return mark ;
}


int main(){
    string input ;
    cin >> input ;
    if(isCharacterVariable(input)){
        cout << "Character Variable" << endl ;
    }
    else if(isBinaryVariable(input)){
        cout << "Binary Variable" << endl ;
    }
    else if(isBinaryNumber(input)){
        cout << "Binary Number" << endl ;
    }
    else {
        cout << "Invalid Number" << endl ;
    }
}