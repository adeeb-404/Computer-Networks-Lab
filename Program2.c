//Question: Given a valid IPV4 address, separate the Network and Host ID part and determine the class of the given IPV4 address.

#include<stdio.h>

int isInRange(int a,int b,int c){
    return c>=a && c<=b;
}

int dottedToDecimal(char dotted[16]){
	int i=0,decimal_ip=0;
	int octet_value=0;
	while(dotted[i]!='\0'){
		if(dotted[i]>='0'&&dotted[i]<='9'){
			octet_value = octet_value *10 + (dotted[i]-'0');
		}
		else if(dotted[i]=='.'){
			decimal_ip = (decimal_ip<<8)|octet_value;
			octet_value =0;
		}
		else{
			printf("Invalid character\n");
			return 1;
		}
		i++;
	}
	decimal_ip = (decimal_ip<<8)|octet_value; //last block
	return decimal_ip;
}

int main(){

    int ip_addrs;
	int network_addrs=ip_addrs,host_addrs=-1;
    char dotted_ip_addrs[16];
    char ip_class;
    printf("Enter the valid IP address in dotted decimal format: ");
    scanf("%15s",dotted_ip_addrs);
    
    ip_addrs = dottedToDecimal(dotted_ip_addrs);

    int first_octet = (ip_addrs>>24) & 0xFF;
    if(isInRange(1,126,first_octet)){
        ip_class='A';
        network_addrs= ip_addrs & 0xFFFFFF00;
        host_addrs= ip_addrs & 0x000000FF;
    }
    else if(isInRange(127,191,first_octet)){
        ip_class = 'B';
        network_addrs=(ip_addrs & 0xFFFF0000);
        host_addrs = ip_addrs & 0x0000FFFF;
    }
    else if(isInRange(192,223,first_octet)) {
        ip_class = 'C';
        network_addrs = ip_addrs & 0xFF000000;
        host_addrs = ip_addrs & 0x00FFFFFF;
    }
    else if(isInRange(224,239,first_octet)){
        ip_class ='D';
    }
    else if(isInRange(240,255,first_octet)){
        ip_class='E';
    }
    else{
        printf("Invalid Address\n");
        return 1;
    }


    printf("\nThe given IPv4 address (%d.%d.%d.%d) belongs to class %c",(ip_addrs >> 24) & 0xFF, (ip_addrs >> 16) & 0xFF, (ip_addrs >> 8) & 0xFF, ip_addrs & 0xFF,ip_class);
    if(host_addrs!=-1){
    printf("\nNetwork address is : %d.%d.%d.%d ",(network_addrs >> 24) & 0xFF, (network_addrs >> 16) & 0xFF, (network_addrs >> 8) & 0xFF, network_addrs & 0xFF);
    printf("\nThe host address is  : %d.%d.%d.%d \n",(host_addrs >> 24) & 0xFF, (host_addrs >> 16) & 0xFF, (host_addrs >> 8) & 0xFF, host_addrs & 0xFF);    	
	}
	else{
		printf("\nNetwork address is : %s",dotted_ip_addrs);
		printf("\nHost address does not exist for class %c\n",ip_class);
	}


    return 0;
}


//Enter the valid IP address in dotted decimal format: 192.168.13.6
//
//The given IPv4 address (192.168.13.6) belongs to class C
//Network address is : 192.0.0.0
//The host address is  : 0.168.13.6
