#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<"\t";

    cout<<"\n\n";
    
    vector<int> ::iterator it;
    for(it=v.begin();it!=v.end();it++)
    cout<<*it<<"\t";

    cout<<"\n\n";

    for(auto element:v)
    cout<<element<<"\t";

    cout<<"\n\n";

    v.pop_back();

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<"\t";

    cout<<"\n\n";

    vector<int> v2 (3,50); 

    for(int i=0;i<v.size();i++)
    cout<<v2[i]<<"\t";

    cout<<"\n\n";

    swap(v,v2);

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<"\t";

    cout<<"\n\n";
}