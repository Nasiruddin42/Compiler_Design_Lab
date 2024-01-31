#include<bits/stdc++.h>
using namespace std ;

int main(){
    string input ;
    getline(cin, input) ;
    int wordcnt = 0, letcnt = 0, digcnt = 0, othercnt = 0 ;
    vector<char> letter, digit, others ;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ' '){
            wordcnt++ ;
        }
        else if(tolower(input[i]) >= 'a' && tolower(input[i]) <= 'z'){
            letcnt++ ;
            letter.push_back(input[i]) ;
        }
        else if(isdigit(input[i])){
            digcnt++ ;
            digit.push_back(input[i]) ;
        }
        else{
            othercnt++ ;
            others.push_back(input[i]) ;
        }
    }
    cout << ++wordcnt << endl;
    cout << letcnt << " : " ;
    for(int i = 0; i < letter.size();i++){
        cout << letter[i] << " " ;
    }
    cout << endl ;
    cout << digcnt << " : " ;
    for(int i = 0; i < digit.size(); i++){
        cout << digit[i] << " " ;
    }
    cout << endl ;
    cout << othercnt << " : " ;
    for(int i = 0; i < others.size(); i++){
        cout << others[i] << " " ;
    }
    cout << endl;
}