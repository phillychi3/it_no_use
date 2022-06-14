#include <iostream>
#include <ctime>
using namespace std;

int scA(int *A,int key){
	int status = -1;
	for(int i=0;i<9;i++){
	    if(A[i]==key){
			status=key;
	    	break;
	    }
	}
	return status;
}

int scB(int *A,int key){

  int right=8;
  int left = 0;
  int status = -1;
  
	while(right>=left){
		int mid = int((left + right) / 2);
		if(A[mid]==key){
			status=key;
			break;
		}
		else if(key>A[mid]){
			left = mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return status;
}

int scC(int *A,int key){
	int status = -1;
	int right=8;
	int left = 0;
	while(right>=left){
		int mid = (key-A[left])*(right-left)/(A[right]-A[left])+left;
		if(A[mid]==key){
			status=key;
			break;
		}
		else if(key>A[mid]){
			left = mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return status;
}

int main() {
	int A[9]={10,20,30,40,50,60,70,80,90};
	int key =30;

	int scar=scA(A,key);
	if(scar!=-1){
		cout<<"Afind:"<<scar<<endl;
	}else{
		cout<<"notfind"<<endl;
	}
	int scbr=scB(A,key);
	if(scbr!=-1){
		cout<<"Bfind:"<<scbr<<endl;
	}else{
		cout<<"notfind"<<endl;
	}
	int sccr=scC(A,key);
	if(sccr!=-1){
		cout<<"Cfind:"<<sccr<<endl;
	}else{
		cout<<"notfind"<<endl;
	}
}
