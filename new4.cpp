#include<bits/stdc++.h>
using namespace std ;

int cnt = 0 ;
vector<string> wordSeparate(string str){
    vector<string> words ;
    string word = "" ;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            words.push_back(word) ;
            word = "" ;
        }
        else{
             if(isdigit(str[i]) || isalpha(str[i])){
                word += str[i] ;
             }
        }
    }
    words.push_back(word) ;
    return words ;
}

bool isVariable(string str){
    bool mark = true ;
    if(tolower(str[0]) >= 'i' && tolower(str[0]) <= 'n'){
        mark = true ;
    }
    else{
        mark = false ;
    }
    for(int i = 1; i < str.size(); i++){
        if(isalpha(str[i]) || isdigit(str[i])){
            continue;
        }
        else{
            mark = false ;
        }
    }
    return mark ;
}

bool isInt(string str){
    bool mark = true ;
    if(isdigit(str[0]) && str[0] != '0'){
        mark = true ;
        cnt++ ;
    }
    else{
        mark = false ;
        return mark ;
    }
    for(int i = 1; i < str.size(); i++){
        if(isdigit(str[i])){
            mark = true ;
            cnt++ ;
        }
        else{
            mark = false ;
            break; 
        }
    }
    return mark ;
}

int main(){
    string input ;
    getline(cin , input) ;
    vector<string> words = wordSeparate(input) ;
    for(int i = 0; i < words.size(); i++){
    if(isVariable(words[i])){
        cout << "Integer Variable" << endl ;
    }
    else if(isInt(words[i]) && cnt <= 4){
        cout << "ShortInt number" << endl ;
    }
    else if(isInt(words[i])){
        cout << "LongInt number" << endl ;
    }
    else{
        cout << "Invalid input" << endl ;
    }
    }
}