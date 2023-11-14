#include<bits/stdc++.h>
using namespace std;

int main(){
    string input = "Md. Tareq Zaman, Part-3, 2011" ;
    int wordcnt = 0, lettercnt = 0, digitcnt = 0, otherscnt = 0;
    vector<char> digit, letter, others ;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ' '){
            wordcnt++ ;
        }
        else if(tolower(input[i]) >= 'a' && tolower(input[i]) <= 'z'){
            lettercnt++ ;
            letter.push_back(input[i]) ;
        } 
        else if(isdigit(input[i])){
            digitcnt++ ;
            digit.push_back(input[i]) ;
        }
        else{
            otherscnt++ ;
            others.push_back(input[i]) ;
        }
    }
    cout << ++wordcnt << endl ;
    cout << lettercnt << " : " ;
    for(int i = 0; i < letter.size(); i++){
        cout << letter[i] << " " ;
    }
    cout << endl ;
    cout << digitcnt << " : " ;
    for(int i = 0; i < digit.size(); i++){
        cout << digit[i] << " " ;
    }
    cout << endl ;
    cout << otherscnt << " : " ;
    for(int i = 0; i < others.size(); i++){
        cout << others[i] << " " ;
    }
    cout << endl;


    return 0 ;
}