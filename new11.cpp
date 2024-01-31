#include<bits/stdc++.h>
using namespace std ;

vector<string> Tree(10, "               ") ;

bool isOp(char ch){
    return (ch == '+' or ch == '-' or ch == '*' or ch == '\\') ;
}

void SyntaxTree(string str){
   int row = 0, col = 2 ;
   for(int i = 0; i < str.size(); i++){
    if(isOp(str[i])){
        Tree[row][col] = str[i] ;
        Tree[row+1][col-1] = '/' ;
        Tree[row+1][col+1] = '\\' ;
        Tree[row+2][col-2] = str[i-1] ;
        row += 2 ;
        col += 2 ;
    }
    Tree[row][col] = str.back() ;
   }
}

int main(){
    string expression ;
    cin >> expression ;
    
    SyntaxTree(expression) ;
    cout << "Syntax tree : " << endl;
    for(auto it : Tree){
        cout << it << endl;
    }
}