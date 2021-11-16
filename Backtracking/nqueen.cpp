/*
   Solution by-Raman Mehta
   
  The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each
  other. ... The expected output is a binary matrix which has 1s for the blocks where queens are placed. 
  For example, following is the output matrix for above 4 queen solution.
  
  */

#include<bits/stdc++.h>
using namespace  std;
int n;
string s[6]={
    "....",
    "....",
    "....",
    "....",
    "....",
    "...."
};
int vcol[6],d1[20],d2[20];
bool possible(int row,int col){
   return (vcol[col]==0)&&(d1[row+col]==0)&&(d2[n+row-col]==0);
}
void f(int row){

    //base case
    if(row==n){
       for(int i=0;i<n;i++)
           cout<<s[i]<<endl;
       
       cout<<endl<<endl;
       return;
    }

    //iterate over choices
    for(int col=0;col<n;col++){
        if(possible(row,col)){
              //do some task 
              s[row][col]='Q';
              vcol[col]=1;
              d1[row+col]=1;
              d2[n+row-col]=1;

              //call next function
              f(row+1);

              //undo some task
              s[row][col]='.';
              vcol[col]=0;
              d1[row+col]=0;
              d2[n+row-col]=0;

        }
    }

}

int main(){
   cin>>n;
   f(0);
   return 0;
}
