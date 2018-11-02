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

int findDontDestroy(int value){
	int middle= (Elements-1)/2;
	int last=Elements-1;
	int start=0;
	int compares=1;
		bool found=false;
		while(!found){
			if(arrStore[middle]==value){
				found=true;
			}
			else{
				if(value>arrStore[middle]){
					compares++;
					start=middle;
					middle=(start+last)/2;
				}
				else if(value<arrStore[middle]){
					compares++;
					last=middle;
					middle=(start+last)/2;
				}
			}
		}
return compares;


}



};
int main() {
	Data myObject;
	myObject.add(1);
	myObject.add(5);
	myObject.add(8);
	myObject.add(10);
	myObject.add(12);
	myObject.add(14);
	myObject.add(18);
	myObject.add(20);
	myObject.add(33);
	myObject.add(41);
	cout<<myObject.findDontDestroy(12)<<endl;



	return 0;
}
