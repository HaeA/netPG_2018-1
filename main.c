#include <stdio.h>
#include <string.h>
#include "./KISA_SHA256.h"

#define len 50 //입력 데이터보다 작아지면 에러남. 영철자 10개이내의 경우 최소 40으로 지정할 것.

typedef unsigned char BYTE;
typedef unsigned int UNIT;

FILE * pw;


int main() {

	pw = fopen("pass.bin", "ab");

	BYTE p[len]; // 평문 암호
	BYTE e[len]; //암호화환 암호
	BYTE ip[len]; //ip주소 받아와서 평문 암호랑 합치기

	UNIT p_len = 0; //평문 길이
	int i = 0;

	memset(p, 0x00, sizeof(p));
	memset(e, 0x00, sizeof(e));
	memset(ip, 0x00, sizeof(ip));

	
	printf("ip: ");
	scanf("%200s", ip); //ip받아오기

	printf("password: ");
	scanf("%200s", p); //보안 위해 길이 지정. 200byte = 영철자 200개, 숫자 50개(char: 1byte, int: 4byte)

	strcat(ip, p);
	
	p_len = strlen((char*) ip);
	
	SHA256_Encrpyt(ip, p_len, e);
	
	fwrite(&e, sizeof(e), len, pw);
	
	/*
	for(i = 0; i < len; i++) {
		printf("%02X", e[i]);
		fprintf(pw, "%02X", e[i]);
	}*/


	fprintf(pw, "\n");
	printf("\n\n");

	fclose(pw);
	//system("pause");
	return 0;
}



		

	
