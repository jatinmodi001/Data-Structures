#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &A) 
{
    stack<int> s;
    int max_area = 0;
    int area_with_top=0;
    int i = 0;
    int tp;
    while( i < A.size() )
    {
        if(s.empty() || A[i]>=A[s.top()])
        {
          s.push(i++);
        }
        else
        {
            tp = s.top();
            s.pop();
            
            area_with_top = A[tp] * (s.empty() ? i : i - s.top() - 1 );		
            
            /* if after poping, the stack becomes empty then find area of that, otherwise find distance		*/
            
            if( max_area < area_with_top)
	            max_area = area_with_top;
        }
    }
    
/*	this is the for the last element	*/
    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        area_with_top = A[tp] * ( s.empty() ? i : i - s.top() - 1 );
        
        if( max_area < area_with_top )
            max_area = area_with_top;
    }
    return max_area;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin>>vec[i];
	}
	
	cout << largestRectangleArea(vec);
	
	return 0;
	
}

