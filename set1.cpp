#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    set<int> s;
    //unordered_set<int> s; 
    s.insert(5); 
    s.insert(1); 
    s.insert(6); 
    s.insert(3); 
    s.insert(7); 
    s.insert(2); 
  
    cout << "Elements of set in sorted order: \n"; 
    int i=0;
    set<int>::iterator itr; 
    for(itr=s.begin();itr!=s.end();itr++)
    {	if(*itr==5){
    	continue;
	}
    	cout<<*itr;
    	
	}
    return 0; 
} 
