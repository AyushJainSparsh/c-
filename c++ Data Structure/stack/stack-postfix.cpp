#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
using namespace std;
int prefix( string s )
{
    stack<int> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int c2=st.top();
            st.pop();
            int c1=st.top();
            st.pop();

            switch(s[i])
            {
                case '+' :
                st.push(c1+c2);
                break;
                case '-' :
                st.push(c1-c2);
                break;
                case '*' :
                st.push(c1*c2);
                break;
                case '/' :
                st.push(c1/c2);
                break;
                case '^' :
                st.push(pow(c1,c2));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s="46+2/5*7+";
    cout<<"46+2/5*7+  =  "<<prefix(s)<<endl;
    return 0;
}