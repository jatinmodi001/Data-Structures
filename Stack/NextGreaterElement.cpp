// Question : https://practice.geeksforgeeks.org/problems/next-larger-element/0

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<long long int> arr(n), ans(n,-1);
        stack<long long int> st;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(arr[i]);
                continue;
            }
            
            while(!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(arr[i]);
            
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}