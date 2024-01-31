#include<bits/stdc++.h>
using namespace std ;

char singleQuote = '\'' ;
char doubleQuote = '\"' ;

vector<string> keywords = {"true","false","do","while","for","if","else","auto","or","and","break","continue","int","float","double","bool","void","char","auto","switch","unsigned","string","const","long"} ;

vector<string> all_operator = {"+", "-", "*", "/", "^", "|", "++", "--", "+=", "-=", "=", "==", ">", "<", ">=", "<=", "%", "%=", "&&", "&"} ;

void sort_keywords_operator(){
    sort(keywords.begin(), keywords.end()) ;
    sort(all_operator.begin(), all_operator.end()) ;
}
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
    words.push_back(word) ;
    return words ;
}

bool isConstant(string str){
    bool isConstant = false ;
    if(str[0] == singleQuote && str[str.size()-1] == singleQuote && str.size() == 3){
       return true ;
    }
    else if(str[0] == doubleQuote && str[str.size()-1] == doubleQuote){
        return true ;
    }
    else if(isdigit(str[0])){
        isConstant = true ;
        int pointCount = 0 ;
        for(int i = 1; i < str.size(); i++){
            if(str[i] == '.'){
                pointCount++ ;
            }
            if(!isdigit(str[i])){
                isConstant = false ;
                break; 
            }
        }
        if(isConstant && pointCount <= 1){
            return true ;
        }
        else{
            return false ;
        }
    }
    return false ;
}
bool isKeyword(string str){
    if(binary_search(keywords.begin(), keywords.end(), str)){
        return true ;
    }
    else return false ;
}
bool isOperator(string str){
    if(binary_search(all_operator.begin(), all_operator.end(), str)){
        return true ;
    }
    else return false ;
}
bool isIdentifier(string str){
    bool identifier = false ;
    if(isalpha(str[0]) || str[0] == '_'){
        identifier = true ;
        for(int i = 1; i < str.size(); i++){
            if(!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_'){
                identifier = false ;
                break;
            }
        }
    }
    if(identifier) return true ;
    else return false ;
}

int main(){
    sort_keywords_operator() ;

    string input ;
    getline(cin, input) ;

    vector<string>words = separateWord(input) ;
    for(int i = 0; i < words.size(); i++){
        cout << "Scanned : " << words[i] << endl;
        if(isConstant(words[i])){
            cout << "Constant" << endl ;
        }
        else if(isKeyword(words[i])){
            cout << "Keyword" << endl ;
        }
        else if(isOperator(words[i])){
            cout << "Operator" << endl ;
        }
        else if(isIdentifier(words[i])){
            cout << "Identifier" << endl ;
        }
        else{
            cout << "Invalid" << endl ;
        }
    }
}