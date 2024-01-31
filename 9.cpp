#include<bits/stdc++.h>
using namespace std ;

vector<string> pn = {"Sagor", "Selim", "Salma", "Nipu"} ;
vector<string> p = {"he", "she", "i", "we", "you", "they"} ;
vector<string> v = {"read", "eat", "take", "run", "write"} ;
vector<string> n ={"book", "cow", "dog", "home", "grass", "rice", "mango"} ;

vector<string> separateWord(string str){
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
    if(word.size() > 0) words.push_back(word) ;
    return words ;
}
bool checkForP(string str){
    for(int i = 0; i < p.size(); i++){
        if(p[i] == str){
            return true ;
        }
    }
    return false ;
}
bool checkForPN(string str){
    for(int i = 0; i < pn.size(); i++){
        if(pn[i] == str){
            return true ;
        }
    }
    return false ;
}
bool checkForV(string str){
    for(int i = 0; i < v. size(); i++){
        if(v[i] == str){
            return true ;
        }
    }
    return false ;
}
bool checkForN(string str){
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

    vector<string> words = separateWord(input) ;

    cout << words.size() << endl ;
    if(words.size() < 2 && words.size() > 3){
        cout << "Invalid Sentence" << endl ;
    }
    else{
        bool mark = false ;
        if(checkForP(words[0]) || checkForPN(words[0])){
            if(words.size() == 2){
                if(checkForV(words[1])){
                    mark = true ;
                }
                else mark = false ;
            }
            else{
                if(checkForV(words[1]) && checkForN(words[2])){
                    mark = true ;
                }
                else mark = false ;
            }
        }
        if(mark){
            cout << "Valid Sentence" << endl ;
        }
        else{
            cout << "Invalid Sentence" << endl ;
        }
    }

}