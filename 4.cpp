#include<bits/stdc++.h>
using namespace std ;

bool isVariable(string s){
    bool mark = true ;
    if((tolower(s[0]) >= 'i') && (tolower(s[0] <= 'n'))){
        mark = true ;
    }
    else{
        mark = false ;
    }
    for(int i = 1; i < s[i]; i++){
        if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'){
            continue;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            continue;
        }
        else{
            mark = false ;
        }
    }
    return mark ;

}
bool isInt(string s){
    bool mark = true ;
    if(s[0] >= '1' && s[0] <= '9'){
        mark = true ;
    }
    else mark = false ;
    for(int i = 1; s[i]; i++){
        if(isdigit(s[i])){
            continue;
        }
        else{
            mark = false ;
            break;
        }
    }
    return mark;
}

int main(){
    string word ;
    cin >> word ;

    if(isVariable(word)){
       cout << "Integer variable" << endl ;
    }
    else if(isInt(word) && word.size() <= 4){
        cout << "ShortInt number" << endl ;
    }
    else if(isInt(word)){
        cout << "LongInt" << endl ;
    }
    else{
        cout << "Invalid" << endl;
    }
}