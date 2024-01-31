#include<bits/stdc++.h>
using namespace std ;

string space = "       " ;

int main(){
    int n;
    cout << "Enter the Productions rules: " << endl;
    cin >> n ;
    cin.ignore() ;
    string productionLeft[n], productionRight[n] ;

    for(int i = 0; i < n; i++){
        string productionRule ;
        getline(cin, productionRule) ;
        bool flag = true ;
        for(int j = 0; j < productionRule.size(); j++){
            if(productionRule[j] == ' '){
                continue;
            }
            if(productionRule[j] == '='){
                flag = false ;
                continue;
            }
            if(flag){
                productionLeft[i].push_back(productionRule[j]) ;
            }
            else{
                productionRight[i].push_back(productionRule[j]) ;
            }

        }
    }
    map<string, string> grammar ;
    cout << "Grammar : " << endl;
    for(int i = 0; i < n; i++){
        cout << productionLeft[i] << "->" << productionRight[i] << endl ;
        grammar[productionRight[i]] = productionLeft[i] ;
    }
    string input ;
    getline(cin, input) ;
    input += '$' ;
    cout << "stack      " << "input   " << "  comment   " << endl;
    cout << "______________________________________" << endl ;
    string stk = "" ;
    while(input.front() != '$'){
        stk += input[0] ;
        input = input.substr(1) ;
        //cout <<"$" << stk << space << input << space << "shift" << endl ;
        cout << "$" << setw(10) << left << stk << setw(10) << left << input << setw(10) << left << "shift" << endl;

        while (true)
        {
            bool flag = false ;
            for(int i = 0; i < stk.size(); i++){
                string tempStk = stk.substr(i) ;
                auto it = grammar.find(tempStk) ;
                if(it != grammar.end()){
                    flag = true ;
                }

                if(flag){
                   string comment = "Reduced " + tempStk + "-> " + grammar[tempStk] ;
                   stk = stk.substr(0, i) + grammar[tempStk] ;
                   //cout << "$" + stk << space << input << space << comment << endl;
                   cout << "$" << setw(10) << left << stk << setw(10) << left << input << setw(10) << left << comment << endl;
                   break; 
                }
            }
            if(!flag){
                break;
            }
        }
    }
    if(stk == productionLeft[0]){
        cout << "Accepted" << endl ;
    }
    else{
        cout <<"Rejected" << endl;
    }
    
    
}