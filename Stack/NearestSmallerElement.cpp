// Interview bit solution, for ques refer : https://www.interviewbit.com/problems/nearest-smaller-element/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int>prevSmaller(vector<int> &A) 
{
    stack<int> st;
    st.push(-1);			// firsly push smaller number as mention in ques as -1
    vector<int> g;
    for(int i=0;i<A.size();i++)
    {
        while(A[i]<=st.top())		// checks the top of stack of larger the pop until smaller comes
        {
            st.pop();
        }
        g.push_back(st.top());		// push the smaller element into another vector
        st.push(A[i]);				// now again push the ith element to stack because it can act as smaller of another element;
    }
    return g;			// return result vector
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	
	vector<int> res = prevSmaller(vec);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	
	return 0;
}
