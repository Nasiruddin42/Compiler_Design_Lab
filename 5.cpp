#include<bits/stdc++.h>
using namespace std ;

bool isFloatVariable(string str){
    bool mark = false ;
    if((tolower(str[0]) >= 'a' && tolower(str[0]) <= 'h') || (tolower(str[0]) >= 'o' && tolower(str[0]) <= 'z')){
        mark = true ;
    }
    bool restmark =  false ;
    for(int i = 1; i < str.size(); i++){
         if(isalpha(str[i]) || isdigit(str[i])){
            restmark = true ;
         }
    }
    if(mark || (mark && restmark)){
        return true ;
    }
    else return false ;
}
bool isFloatNumber(string str){
    bool mark = false ;
    if((str[0] == '0' && str[1] == '.') && isdigit(str[2]) && isdigit(str[3]) && str.size() == 4){
        mark = true ;
    }

    bool mark1 = true ;
    if(str[0] >= '1' && str[0] <= '9'){
        mark1 = true ;
    }
    else mark1 = false ;
    
    bool restmark1 = true ;
    for(int i = 1 ; i < str.size(); i++){
        if(str[i] == '.') break;
        if(!isdigit(str[i])){
            restmark1 = false ;
            return false ;
        }
    }
    if((str[str.size()-3] == '.') && isdigit(str[str.size()-1]) && isdigit(str[str.size()-2])){
       restmark1 = true ;
    }
    else{
        restmark1 = false ;
    }



    if(mark || (mark1 && restmark1)){
        return true ;
    }
    else return false ; 
}

bool isDoubleNumber(string str){

    for(int i = 0; i < str.size(); i++){
        if(!isdigit(str[i]) && str[i] != '.'){
            return false ;
        }
    }
    
    bool mark = true ;
    int sz = str.size() ;
    if(sz <= 4){
        mark = false ;
    }
    if((sz >= 5) && (str[0] == '0' && str[1] == '0') || (str[0] == '0' && str[1] == '1')){
        mark = false ;
    }
    int digitAfterDot = 0, getDot = 0 ;
    for(int i = 0; i < sz; i++){
        if(str[i] == '.'){
            getDot +=1 ;
            continue;
        }
        if(getDot){
            digitAfterDot++ ;
        }
    }
    if(digitAfterDot != 3 || getDot > 1){
        mark = false ;
    }
    return mark ;
}

int main(){
    string input ;
    cin >> input ;

    if(isFloatVariable(input)){
        cout << "Float variable" << endl ;
    }
    else if(isFloatNumber(input)){
        cout << "Float Number" << endl ;
    }
    else if(isDoubleNumber(input)){
        cout << "Double number" << endl ;
    }
    else{
        cout << "Invalid" << endl ;
    }
}