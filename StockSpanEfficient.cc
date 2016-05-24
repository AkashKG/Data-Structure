// a linear time solution for stock span problem
#include <iostream>
#include <stack>
#include<cstring>
using namespace std;

// A utility function to print elements of array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
}

// A stack based efficient method to calculate stock span values
void calculateSpan(int price[], int n, int S[])
{
   // Create a stack and push index of first element to it
   stack<int> st, t;
   st.push(0);

   // Span value of first element is always 1
   S[0] = 1;

   // Calculate span values for rest of the elements
   for (int i = 1; i < n; i++)
   {
      // Pop elements from stack while stack is not empty and top of
      // stack is smaller than price[i]
      cout<<endl;
      printArray(price,n);
      cout<<endl;
      printArray(S,n);
      cout<<endl;
      t=st;
      while(!t.empty()){
        cout<<t.top()<<" ";
        t.pop();
      }
      cout<<endl;
      while (!st.empty() && price[st.top()] <= price[i]){
         cout<<"\nPopping "<<st.top();
         st.pop();
      }

      // If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack
      S[i] = (st.empty())? (i + 1) : (i - st.top());
        cout<<"\nS["<<i<<"] = "<<S[i];
      // Push this element to stack
      cout<<"\nPushing "<<i<<" to the stack.";
      st.push(i);
   }
}


// Driver program to test above function
int main()
{
    int price[] = {90, 70, 50, 30, 10, 60, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
    memset(S,0,sizeof(S));
    // Fill the span values in array S[]
    calculateSpan(price, n, S);

    // print the calculated span values
    printArray(S, n);

    return 0;
}
