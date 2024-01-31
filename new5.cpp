#include<bits/stdc++.h>
using namespace std ;

vector<string> wordSeparate(string str){
   vector<string> words ;
   string word = "" ;
   for(int i = 0; i < str.size(); i++){
     if(str[i] == ' '){
        words.push_back(word) ;
        word = "" ;
     }
     else{
        word += str[i] ;
     }
   }
   words.push_back(word) ;
   return words ;
}
bool isFloatVariable(string str){
    bool mark = true ;
    if((tolower(str[0]) >= 'a' && tolower(str[0]) <= 'h') || (tolower(str[0]) >= 'o' && tolower(str[0]) <= 'z')){
        mark = true ;
    }
    else{
        mark = false ;
        return mark ;
    }
    for(int i  = 1; i < str.size(); i++){
        if(isalpha(str[i]) || isdigit(str[i])){
            continue;
        }
        else{
            mark = false ;
        }
    }
    return mark ;
}
bool isFloatNumber(string str){
    bool mark = true ;
    int sz = str.size() ;
    if(str[0] == '0' && str[1] == '.' && isdigit(str[2]) && isdigit(str[3]) && sz == 4){
        mark = true ;
    }
    else{
        mark = false ;
    }
    bool mark1 = false ;
    if(str[0] >= '1' && str[0] <= '9'){
        mark1 = true ;
    }
    bool mark2 = false ;
    for(int i = 1; i < sz-3; i++){
        if(isdigit(str[i])){
            mark2 = true ;
        }
        else{
            mark2 = false ;
            return false ;
        }
    }
    if(str[sz-3] == '.' && isdigit(str[sz-2]) && isdigit(str[sz-1])){
        mark2 = true ;
    }
    if(mark || (mark1 && mark2)){
        return true ;
    }
    else{
        return false ;
    }
}

bool isDoubleNumber(string str){
    bool mark = true ;

    int cnt = 0 , sz = str.size() ;
    for(int i = 0; i < sz; i++){
        if(!isdigit(str[i]) && str[i] != '.'){
            return false ;
        }
    }
    if(str[0] == '0' && str[1] == '.'){
        for(int i = 2; i < str.size(); i++){
            if(isdigit(str[i])) cnt++ ;
            else{
                return false ;
            }
        }
        if(cnt >= 3){
            mark = true;
        }
        else{
            mark = false ;
        }
    }
    int dotcnt = 0, digitAfterDot = 0 ;
    if(str[0] >= '1' && str[0] <= '9'){
        for(int i = 1; i < sz; i++){
            if(str[i] == '.'){
                dotcnt++ ;
                continue; 
            }
            if(dotcnt){
                digitAfterDot++ ;
            }
        }
        if(digitAfterDot >= 3 && dotcnt == 1){
            mark = true ;
        }
        else{
            mark = false ;
        }
    }
    return mark ;
}

int main(){
    string input ;
    getline(cin, input) ;

    vector<string> words = wordSeparate(input) ;
    for(auto it : words){
        if(isFloatVariable(it)){
            cout << "Float Variable" << endl ;
        }
        else if(isFloatNumber(it)){
            cout << "Float Number" << endl ;
        }
        else if(isDoubleNumber(it)){
            cout << "Double Number" << endl ;
        }
        else{
            cout << "Invalid number" << endl ;
        }
    }
    
}