#include<algorithm>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int precidence(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}

string infixToPostfix(string s)
{
    string r="";
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
        r=r+s[i];
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                r=r+st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else
        {
            while(!st.empty() && precidence(st.top())>precidence(s[i]))
            {
                r=r+st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        r=r+st.top();
        st.pop();
    }
    return r;
}

int main()
{
    string s="(a-b/c)*(a/k-l)";
    string rev="";
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==')')
        rev+='(';
        else if(s[i]=='(')
        rev+=')';
        else
        rev+=s[i];
    }
    rev=infixToPostfix(rev);
    reverse(rev.begin(),rev.end());
    cout<<"(a-b/c)*(a/k-l)  = "<<rev<<endl;
    return 0;
}
//(a-b/c)*(a/k-l)  = *-a/bc-/akl