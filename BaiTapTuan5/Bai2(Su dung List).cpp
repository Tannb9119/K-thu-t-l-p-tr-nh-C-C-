#include<iostream>
using namespace std;

struct Node{
	float data;
	Node * next;
};

struct List{
	Node* firstnode; 
};

void List_Init(List* list){
	list->firstnode = 0;
}

void List_add(List* list, float data){
	Node* node = new Node;
	node->data = data;
	node->next = list->firstnode;
	list->firstnode = node;
}

int List_Length(List* list){
	Node* node = list->firstnode;
	int i = 0;
	while(node != 0){
		i++;
		node = node->next;
	}
	return i;
}

void List_Display(List* list){
	Node* node = list->firstnode;
	int i = List_Length(list);
	cout << "Do dai list: " << i <<endl;
	if(i == 0)
		cout << "\nList rong \r\n";
	else
		while(node != 0){
			cout <<"\nDia chi cua node: " << i << "\t" << node;
			cout <<"\nnode->data: \t\t" << node->data;
			cout <<"\nNode->next: \t\t" << node->next << endl;
			node = node->next;
			i--;
		}
	cout << endl;
}

void xoaNode(List* list, int pos){
	Node* node = list->firstnode;
	int i = List_Length(list);
	if(i == pos){
		node = node->next;
		list->firstnode = node;
	}
	else{
		while(i != pos + 1){
			node = node->next;
			i--;
		}
		Node* node1 = node->next;
		node->next = node1->next;
		delete node1;
	}
}

void chenNode(List* list, int pos , int data){
	Node* node = list->firstnode;
	int i = List_Length(list);
	Node* node1 = new Node;
	node1->data = data;
	while(i != pos){
		node = node->next;
		i--;
	}
	node1->next = node->next;
	node->next = node1;
}

int main(){
	List list1;
	List_Init(&list1);
	float data;
	char check;
	do{
		cout << "Nhap data: ";
		cin >> data;
		cin.ignore();
		List_add(&list1, data);
		cout << "Ban co muon nhap tiep(c/k)";
		check = getchar();
	}while(check == 'c' || check == 'C');
	List_Display(&list1);
	int pos;
	do{
	cout <<"\nNhap vi tri node muon xoa:";
	cin >> pos;
	}while(pos > List_Length(&list1) || pos <= 0);// nhap vi tri xoa thoa man 0 < pos <= List_Length(hien tai) 
	xoaNode(&list1, pos);
	cout <<"\nList sau khi xoa:\n";
	List_Display(&list1);
	do{
		cout <<"\nNhap vi tri node muon chen:";
		cin >> pos;
	}while(pos > List_Length(&list1) || pos <= 0);// nhap vi tri chen thoa man 0 < pos <= List_Length(hien tai)
	cout <<"Nhap data: ";
	cin >> data;
	chenNode(&list1, pos, data);
	cout <<"\nList sau khi chen:\n";
	List_Display(&list1);
	return 0;
}
