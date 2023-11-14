#include<bits/stdc++.h>
using namespace std ;

bool isCharacterVariable(string str){
    int sz = str.size() ;
    bool mark = false ;
    if(str[0] == 'c' && str[1] == 'h' && str[2] == '_' && (isdigit(str[3]) || isalpha(str[3]))){
        mark = true ;
    }
    for(int i = 4; i < sz; i++){
        if(isalpha(str[i]) && isdigit(str[i])){
            mark = true ;
        }
        else{
            mark = false ;
            break;
        }
    }
    return mark ;
}
bool isBinaryVariable(string str){
    int sz = str.size() ;
    bool mark = false ;
    if(str[0] == 'b' && str[1] == 'n' && str[2] == '_' && (isdigit(str[3]) || isalpha(str[3]))){
        mark = true ;
    }
    for(int i = 4; i < sz; i++){
        if(isalpha(str[i]) && isdigit(str[i])){
            mark = true ;
        }
        else{
            mark = false ;
            break;
        }
    }
    return mark ;
}
bool isBinaryNumber(string str){
    int sz = str.size() ;
    if(sz < 2 || str[0] != '0'){
        return false ;
    }
    if(str[1] != '0' && str[1] != '1'){
        return false ;
    }
    bool mark = true ;
    for(int i = 2; i < sz; i++){
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
}