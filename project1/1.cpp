#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int numbers[100];
int size;
struct Node
{
	int data;
	int dlink;
	Node *next;
};
void input(){
	string input;
	cin >> input;
	vector<string> a;
	vector<string> b;
	vector<string> output;
	string t[100];
	string temp;
	a.reserve(50);
	int x = 0;
	int w = 0;
	int count = 0;
	while (w <= input.length()){
		if (input[w] != ';'){
			temp = temp + input[w];
			w++;
		}
		else{
			w++;
			a.push_back(temp);
			count++;
			temp = "";
		}
	}
	temp = "";
	string temp2 = "";
	int j = 0;
	int z = 0;
	for (int q = 0; q < count; q++){
		temp2 = a[q];
		int j = 0;
		while (j <= temp2.length()){
			if (temp2[j] != ','){
				temp = temp + temp2[j];
			}
			else{
				b.push_back(temp);
				temp = "";
			}
			if (j + 1 > temp2.length()){
				b.push_back(temp);
				temp = "";
			}
			j++;

		}
		temp2 = "";
	}
	for (int i = 0; i < b.size(); ++i){
		t[i] = b[i];
	}
	int tempp = 0;
	for (int i = 0; i < b.size(); ++i){
		t[i] = b[i];
	}
	 size = b.size();
	int o = 0;
	int final;
	//cout << "numbers:" << endl;
	while (o < size){
		numbers[o] = atoi(t[o].c_str());
	//	cout << numbers[o] << endl;
		o++;
	}
}
void addtolist(){
	cout << "numbers:" << endl;
	for (int i = 0; i < size; i++){
		cout << numbers[i] << endl;
	}
	Node *head=new Node;
	head->data = numbers[0];
	head->dlink = numbers[1];
	head->next = NULL;
	printf("%d,", head->data);
	printf("%d;", head->dlink);
	for (int i = 2; i < size; i+=2){
		Node *cur = new Node;
		cur->data = numbers[i];
		cur->dlink = numbers[i + 1];
		head->next = cur;
		head = head->next;

		if (cur->dlink < numbers[i-1]){
			cur->next = NULL;
			cur->dlink =NULL;
			cur->data = NULL;
			printf("%d,", cur->data);
			printf("%d;", cur->dlink);
			break;

		}
		printf("%d,", cur->data);
		printf("%d;", cur->dlink);
	}
}
int main(){
	input();
	addtolist();

	getchar();
	getchar();
	return 0;
}