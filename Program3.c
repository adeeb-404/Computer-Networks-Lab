//Question: Simulate the working of sliding window protocol for flow control in computer networks. (Using a C program)
#include<stdio.h>

void goBackN(int packets[],int size,int n){
	printf("Go Back N Protocol\n");
	int i=0,prev=0;
	while(i<n){
		if(i%size==0){
			//next window
			printf("\n---------------------------------------------------\n");
			printf("\n");
			prev = i;
		}
		
		if(packets[i]==-1){
			//corrected packet denoted by 100
			printf(" Error occurred");
			packets[i]=100;
			i=prev;
			printf("\n");
		}
		else{
			printf("%d ",packets[i]);
			i++;
		}
	}
}

void selectiveRepeat(int packets[],int size,int n){
	printf("\n\nSelective Repeat protocol\n\n");
	int i=0;
	while(i<n){
		if(i%size==0)
			printf("\n-----------------------------------------------------------\n");
		
		if(packets[i]!=-1)
			printf("%d ",packets[i]);
		else
			printf("(Error occurred) 100 ");
		i++;
	}
}

int main(){
	
	int n,size;
	printf("Enter the number of packets to be sent\n");
	scanf("%d",&n);
	int packets[n];
	printf("Enter the packets (enter -1 to denote error)\n");
	for(int i=0;i<n;i++)
		scanf("%d",&packets[i]);
		
	
	
	
	printf("Enter window size\n");
	scanf("%d",&size);
	
	printf("\n\n");
	
	selectiveRepeat(packets,size,n);
	goBackN(packets,size,n);
	
	
	return 0;
}

//Sample input
//9
//1 2 -1 4 -1 6 7 -1 -1
//3