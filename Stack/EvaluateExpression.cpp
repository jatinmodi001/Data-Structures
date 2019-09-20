// interview bit solution for ques refer : https://www.interviewbit.com/problems/evaluate-expression/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int evalRPN(vector<string> arr) 
{

/*	in this case we use stack,we push the elements until any 
	operator comes when any operator comes then pop the top 2 
	elements and calculate result then push them into end	*/
	
    stack<int>st;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]=="/")				
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b/a);
        }
        else if(arr[i]=="*")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b*a);
        }
        else if(arr[i]=="+")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b+a);
        }
        else if(arr[i]=="-")
        {
            int a =st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b-a);
        }
        else
        {
            st.push(stoi(arr[i]));
        }
    }
    return st.top();
}

int main()
{
	int n;
	cin>>n;
	vector<string> vec;
	for(int i=0;i<n;i++)
	{
		string a;
		cin>>a;
		vec.push_back(a);
	}
	
	cout<<evalRPN(vec);				// prints the expression result
	
	return 0;
}


