#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> g1;
	int j=0;
	for(j=0;j<5;j++)
	{
		g1.push_back(j);
	}
	for(j=0;j<g1.size();j++)
	{	if(g1[j]==4){
		g1[j]=99;
	}
	
		cout<<g1[j];
	}
	cout<<g1.size()<<endl;
}
