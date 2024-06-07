#include <iostream>
using namespace std;

struct Node{
	int data; //size 8 byte
	Node *next; //size 8 byte
};

typedef struct Node* node;

//Cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode (int x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = NULL ; //nullptr
	return tmp;
	}
//Kiem tra rong
bool empty (node a){
	 return a == NULL;
	}
// Dem bao nhieu phan tu
int Size(node a){
    int cnt = 0;
    while(a != NULL){
	    ++cnt;
	    a = a-> next;
	}
	return cnt;
}
// Them 1 phan tu vao dau danh sach lien ket
void insertFirst(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL){
		a = tmp;
	}else{
		tmp -> next = a;
		a = tmp;
	}
}
// Them 1 phan tu vao cuoi danh sach lien ket
void insertLast(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL){
	   a = tmp;
	}else{
		node p = a;
		while(p -> next != NULL){
			p = p -> next;
		}
		p -> next = tmp;
	}
}
// Them phan tu o giua
void insertMiddle(node &a, int x, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri chen khong hop le ! \n";
	} 
	if(n == 1){
		insertFirst (a, x); return;
	}else if(n == pos + 1){
		insertLast(a,x); return;
	}
	node p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p -> next;
	}
	node tmp = makeNode(x);
	tmp -> next = p -> next;
	p -> next = tmp;
}

//xoa phan tu o dau
void deleteFirst(node &a){
	if(a == NULL){
	return;
	}
	a = a -> next;
}
//xoa phan tu cuoi
void deleteLast(node &a){
    if(a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau -> next != NULL){
    	truoc = sau;
    	sau = sau -> next;
	}
    if(truoc == NULL){
    	a = NULL ;
	}else{
		truoc -> next = NULL;
	}
}
//Xoa o giua
void deleteMiddle(node &a, int pos ){
	if(pos <= 0 || pos > Size(a)) return;
	node truoc = NULL , sau = a;
	for(int i = 1; i < pos ; i++){
		truoc = sau ;
		sau = sau -> next;
	}
	if(truoc == NULL){
		a = a -> next;
	}
}
void in(node a){
	cout << "-------------\n";
	while(a != NULL){
		cout << a -> data << " ";
		a = a -> next;
	}
}
void sapxep(node &a){
  for(node p = a; p -> next = NULL; p = p -> next){
  	node min = p;
  	for(node q = p -> next ; q != NULL; q = q -> next){
  		if(q -> data  < min -> data){
  			min = q;
		  }
	  }
	  int tmp = min -> data;
	  min -> data = p -> data;
	  p -> data = tmp;
  }
}
int main(){
  node head = NULL;
  while(1){
  	cout << "---------------MENU----------------\n";
  	cout << "1. chen phan tu vao dau danh sach \n";
  	cout << "2. chen phan tu vao cuoi danh sach \n";
  	cout << "3. chen phan tu vao giua danh sach \n";
  	cout << "4. xoa phan tu vao dau danh sach \n";
  	cout << "5. xoa phan tu vao cuoi danh sach \n";
  	cout << "6. xoa phan tu vao giua danh sach \n";
  	cout << "7. duyet danh sach lien ket\n";
  	cout << "8. sap xep danh sach lien ket\n";

  	cout << "--------------------------------------\n";
  	cout << "Nhap lua chon";
  	int lc;
  	cin >> lc;
  	if(lc == 1){
  		int x;
  		cout << "nhap gia tri can chen";
  		cin >> x;
  		insertFirst(head,x);
    }
    else if(lc == 2){
    	int x;
    	cout << "Nhap gia tri can chen";
    	cin >> x;
    	insertLast(head, x);
	}else if(lc == 3){
		int x;
		cout << "Nhap gia tri can chen";
	    cin >> x;
		cout << "Nhap vi tri can chen";
		int pos;
		cin >> pos;
		insertMiddle(head,x, pos);
	}
	else if(lc == 4){
		deleteFirst(head);
	}else if(lc == 5){
		deleteLast(head);
	}else if(lc == 6){
		int pos ;
		cout << "Nhap vi tri can xoa";
		cin >> pos;
		deleteMiddle(head, pos );
	}
  }
  return 0;
}
