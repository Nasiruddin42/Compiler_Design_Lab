#include<bits/stdc++.h>
using namespace std ;

map<char, vector<string>> grammar ;
map<char, set<char>> First ;
map<char, bool > hasEps ;

void InputGrammar(){
    char variable, x ;
    string rule ;
    while (cin >> variable >> x >> x >> rule)
    {
        grammar[variable].push_back(rule) ;
    }

    cout << "Given Grammar : " << endl ;
    for(auto it : grammar){
        for(auto it1 : it.second){
            cout << it.first << "->" << it1 << endl ;
        }
    } 
}
void computeFirst(){
    for(auto g : grammar){
        for(auto x : g.second){
            if(x[0] >= 'A' && x[0] <= 'Z'){
                continue;
            }
            else{
                First[g.first].insert(x[0]) ;
            }
        }
    }
int variable = grammar.size() ;
for(int i = 1; i <= variable; i++){
    for(auto g : grammar){
        for(string x : g.second){
            for(int j = 0; j < x.size(); j++){
                if(x[j] >= 'A' && x[j] <= 'Z'){
                    bool eps = false ;
                    for(auto f : First[x[j]]){
                        if(f == '@'){
                           eps = true ;
                        }
                        First[g.first].insert(f) ;
                    }
                    if(!eps) break;
                    else{
                        if( j < x.size()-1){
                            First[g.first].erase('@') ;
                        }
                        else{
                            hasEps[g.first] = true ;
                        }
                    }

                }
                else{
                    First[g.first].insert(x[j]) ;
                    break;
                }
            }
        }
        for(auto it : hasEps){
            if(it.second){
                First[g.first].insert('@') ;
            }
        }  
    }
}

    cout << "\nFirst : " << endl; 
    for(auto it : First){
        cout << it.first << "-> " ; 
        for(auto it1 : it.second){
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << endl ;
}

int main(){
    InputGrammar() ;
    computeFirst() ;
}