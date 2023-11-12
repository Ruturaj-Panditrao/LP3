// Fibonacci Series using Iteration and Recursion
// Iteration :
// Time Complexity = O(N)
// Space Complexity : O(1)
// Recursion :
// Time Complexity : O(1.618^N)
// Space Complexity : O(N) due to Auxilliary Stack Space
// Time Complexity is derived using Binet's Formula
// Time Complexity = 1/root(5)*[(1+root(5)/2)^n-(1-root(5)/2)^n]

#include <iostream>
using namespace std;

int rsteps = 0;

int recursive_fibonacci(int n)
{
    rsteps++;
    if(n<=0) return 0;
    if(n==0 || n==1) return n;
    return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

void iterative_fibonacci(int n)
{
    int isteps = 0;
    int prev1 = 0;
    int prev2 = 1;
    int curr = 0;
for(int i=2; i<=n; i++)
    {
        isteps++;
        curr = prev1+prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    cout<<curr<<endl;
    cout<<"Number of Steps : "<<isteps<<endl;
}

int main()
{
    int n; 
    cout<<"Enter n to Calculate nth Fibonacci Number : ";
    cin>>n;

    cout<<"The value of "<<n<<"th Fibonacci Number is : "<<endl;
    cout<<"Recursive Approach : "<<recursive_fibonacci(n)<<endl;
    cout<<"Number of Steps : "<<rsteps<<"\n"<<endl;

    cout<<"Iterative Approach : ";
    iterative_fibonacci(n);   
}
