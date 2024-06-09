//Chuyen doi so thap phan sang he nhi phan Stack
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
	int n;
	cout << "Nhap so can chuyen sang he nhi phan: ";
	cin >> n;
	stack<int> st;
	while(n != 0){
		st.push(n%2);
		n /= 2;
	}
	while(!st.empty()){
		cout <<st.top();
		st.pop();
	}
	return 0;
}


//in chuoi nguoc lai
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	stringstream ss(s); //1 lp of C++ cho phep thao tac tren chuoi 
	string token; //dai dien cho tung tu duoc trich xuat tu chuoi
	stack<string> st;
	while(ss >> token){
		st.push(token);
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	
}

//ktra ky tu
#include <bits/stdc++.h>
#include <stack>
using namespace std;

void solve(){
    string s;
    cin >> s;
    stack<char> st;
    for(char x : s){
        if(x == '('){
            st.push(x);
        } else {
            if(st.empty()){
                cout << "INVALID\n";
                return;
            } else {
                st.pop();
            }
        }
    }
    if(st.empty()){
        cout << "VALID\n";
    } else {
        cout << "INVALID\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

