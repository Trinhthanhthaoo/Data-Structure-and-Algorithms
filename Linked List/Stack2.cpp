#include <bits/stdc++.h>
#include <stack>
using namespace std;
//LIFO : last in first out
//push
//pop
//top
//size
//emty
//O(1)
int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	cout << st.size() << endl;
	st.pop();
	st.pop();
	if(st.empty()){
		cout << "Empty!";
	}
	return 0;
}
