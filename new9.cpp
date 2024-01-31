#include<bits/stdc++.h>
using namespace std ;

vector<string> pn = {"Sagor", "Selim", "Salma", "Nipu"} ;
vector<string> p = {"he", "she", "i", "we", "you", "they"} ;
vector<string> v = {"read", "eat", "take", "run", "write"} ;
vector<string> n ={"book", "cow", "dog", "home", "grass", "rice", "mango"} ;

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
bool isPN(string str){
    for(int i = 0; i < pn.size(); i++){
        if(pn[i] == str){
           return true ;
        }
    }
    return false ;
}
bool isP(string str){
    for(int i = 0; i < p.size(); i++){
        if(p[i] == str){
           return true ;
        }
    }
    return false ;
}
bool isV(string str){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == str){
           return true ;
        }
    }
    return false ;
}
bool isN(string str){
    for(int i = 0; i < n.size(); i++){
        if(n[i] == str){
           return true ;
        }
    }
    return false ;
}

int main(){
    string input ;
    getline(cin, input) ;

    vector<string> words = wordSeparate(input) ;

    if(words.size() < 2 && words.size() > 3){
        cout << "Invalid" << endl ;
    }
    else{
        bool mark = false ;
        if(isPN(words[0]) || isP(words[0])){
            if(words.size() == 2){
                if(isV(words[1])){
                    mark = true;
                }
                else{
                    mark = false;
                }
            }
            else{
                if(isV(words[1]) && isN(words[2])){
                    mark = true ;
                }
                else{
                    mark = false ;
                }
            }
        }
        if(mark){
            cout << "Valid Sentence" << endl;
        }
        else{
            cout << "Invalid Sentence" << endl ;
        }
    }
}