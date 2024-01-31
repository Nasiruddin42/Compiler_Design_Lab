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
            if(isalpha(str[i])){
                word += str[i] ;
            }
        }
    }
    words.push_back(word) ;
    return words ;
}

int main(){
    string input ;
    getline(cin, input) ;
    vector<string> words = wordSeparate(input) ;

    int vowcnt = 0, conscnt = 0 ;
    vector<char> vowels, consonants ;
    for(int i = 0 ; i < input.size(); i++){
        if(isalpha(input[i])){
            if(tolower(input[i]) == 'a' || tolower(input[i]) == 'e' || tolower(input[i]) == 'i' || tolower(input[i]) == 'o' || tolower(input[i]) == 'u') {
                vowcnt++ ;
                vowels.push_back(input[i]) ;
            }
            else{
                conscnt++ ;
                consonants.push_back(input[i]) ;
            }
        }
    }
    cout << vowcnt << " : " ;
    for(int i = 0; i < vowels.size(); i++){
        cout << vowels[i] << " " ;
    }
    cout << endl ;
    cout << conscnt << " : " ;
    for(int i = 0; i < consonants.size(); i++){
        cout << consonants[i] << " " ;
    }
    cout << endl ;
    set<char> st = {'a','e', 'i', 'o', 'u'} ;
    vector<string> vow, cons ;
    for(int i = 0 ; i < words.size(); i++){
        if((st.find(words[i][0]) != st.end())){
           vow.push_back(words[i]) ;
        }
        else{
            cons.push_back(words[i]) ;
        }
    }
    cout << "Vowels : " ;
    for(int i = 0; i < vow.size(); i++){
        cout << vow[i] << " " ;
    }
    cout << endl ;
    cout << "Consonants : " ;
    for(int i = 0; i < cons.size(); i++){
        cout << cons[i] << " " ;
    }
    cout << endl ;

}