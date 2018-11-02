#include <iostream>

using namespace::std;
class Data{
private:
struct Node{
	int data;
	Node* next;
};
Node* first;
Node* temp;
Node* last;
int Elements;
int arrStore[100];
public:
Data(){
	Elements=0;
}
void add(int a){
	if (Elements==0){
		temp=new Node;
		first=temp;
		first->data=a;
		first->next=NULL;
		last=first;
		arrStore[Elements]=a;
		Elements++;
	}
	else{
		temp=first;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp=new Node;
		last->next=temp;
		last=last->next;
		last->data=a;
		arrStore[Elements]=a;
		Elements++;
	}
}

int remove(){
	if(Elements==1){
		Elements--;
		return first->data;
	}
	else if(Elements>1){
		temp=first;
		first=first->next;
		Elements--;
		return temp->data;
	}
}
int getValue(int index){
	/*if(index==0){
		return first->data;
	}
	else{
		temp=first;
		for(int i=0;i<index;i++){
			temp=temp->next;
		}
		return temp->data;
	}*/
	return arrStore[index];
}





};
int main() {
	Data myObject;
	myObject.add(1);
	myObject.add(9);
	myObject.add(4);
	myObject.add(5);
	myObject.add(10);
	myObject.add(0);
	cout<<myObject.getValue(3)<<endl;

	return 0;
}
