#include<stdio.h>


int main(){
	int hammingCode[7];
	printf("Enter 4 digit data word:\n");
	scanf("%d %d %d %d",&hammingCode[2],&hammingCode[4],&hammingCode[5],&hammingCode[6]);
	
	hammingCode[0]=hammingCode[2]^hammingCode[4]^hammingCode[6];
	hammingCode[1]=hammingCode[2]^hammingCode[5]^hammingCode[6];
	hammingCode[3]=hammingCode[4]^hammingCode[5]^hammingCode[6];

	
	printf("The Hamming code word at sender:\n");
	for(int i=0;i<7;i++)
		printf("%d",hammingCode[i]);
	printf("\n");
	
	
	printf("Enter the corrupted bit: ");
	int bit;
	scanf("%d",&bit);
	bit--; //0 indexed
	hammingCode[bit] = !hammingCode[bit];
	printf("\n");
	printf("Received hamming code :\n");
	for(int i=0;i<7;i++)
		printf("%d",hammingCode[i]);
	printf("\n\n");
		
	int p0 = hammingCode[2]^hammingCode[4]^hammingCode[6];
	int p1 = hammingCode[2]^hammingCode[5]^hammingCode[6];
	int p3 = hammingCode[4]^hammingCode[5]^hammingCode[6];

	int corrupted_bit = (p0^hammingCode[0])*1 + (p1^hammingCode[1])*2 + (p3^hammingCode[3])*4;
	
	printf("bit corrupted: %d\n\n",corrupted_bit);
	corrupted_bit--;
	printf("Therefore,\n");
	hammingCode[corrupted_bit]= !hammingCode[corrupted_bit];
	
	printf("The correct hamming code is: ");
	for(int i=0;i<7;i++)	
		printf("%d",hammingCode[i]);
	printf("\nThe correct data word is: ");
	printf("%d%d%d%d",hammingCode[2],hammingCode[4],hammingCode[5],hammingCode[6]);
	
	return 0;
}

//Sample output
//Enter 4 digit data word:
//1 0 1 1
//The Hamming code word at sender:
//0110011
//Enter the corrupted bit: 3
//
//Received hamming code :
//0100011
//
//bit corrupted: 3
//
//Therefore,
//The correct hamming code is: 0110011
//The correct data word is: 1011
