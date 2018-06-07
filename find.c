#include <stdio.h>
#include <string.h>
#include "./KISA_SHA256.h"

#define len 50 //입력 데이터보다 작아지면 에러남. 영철자 10개이내의 경우 최소 40으로 지정할 것.

typedef unsigned char BYTE;
typedef unsigned int UNIT;

FILE * pw;

int main() {

	BYTE p[len]; //평문암호
	BYTE e[len]; //암호화한 암호
	BYTE ip[len]; //ip주소 받아와서 평문암호랑 합치기
	BYTE cm[len]; //암호 비교용

	UNIT p_len = 0; //평문 길이
	BYTE db[len]; //저장된 암호 불러오기

	int cmp = -1;

	memset(p, 0x00, sizeof(p));
	memset(e, 0x00, sizeof(e));
	memset(ip, 0x00, sizeof(ip));
	memset(db, 0x00, sizeof(db));

	pw = fopen("pass.txt", "r");

	printf("ip: ");
	scanf("%200s", ip); //ip받아오기

	printf("password: ");
	scanf("%200s", p); //보안 위해 길이 지정. 200byte = 영철자 200개, 숫자 50개(char: 1byte, int: 4byte)

	strcat(ip, p);
	
	p_len = strlen((char*) ip);
	
	SHA256_Encrpyt(ip, p_len, e);

	sprintf(cm, "%02X", e);

	while(!feof(pw)) {
		fscanf(pw, "%s", db);
		if(strcmp(db, cm) == 0) {
			printf("password: %s\n", db);
			printf("find password\n");
			break;
		}
	}

	fclose(pw);
	return 0;
}
