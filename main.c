#include <stdio.h>
#include <string.h>
#include "./KISA_SHA256.h"

#define len 50 //�Է� �����ͺ��� �۾����� ������. ��ö�� 10���̳��� ��� �ּ� 40���� ������ ��.

typedef unsigned char BYTE;
typedef unsigned int UNIT;

FILE * pw;


int main() {

	pw = fopen("pass.bin", "ab");

	BYTE p[len]; // �� ��ȣ
	BYTE e[len]; //��ȣȭȯ ��ȣ
	BYTE ip[len]; //ip�ּ� �޾ƿͼ� �� ��ȣ�� ��ġ��

	UNIT p_len = 0; //�� ����
	int i = 0;

	memset(p, 0x00, sizeof(p));
	memset(e, 0x00, sizeof(e));
	memset(ip, 0x00, sizeof(ip));

	
	printf("ip: ");
	scanf("%200s", ip); //ip�޾ƿ���

	printf("password: ");
	scanf("%200s", p); //���� ���� ���� ����. 200byte = ��ö�� 200��, ���� 50��(char: 1byte, int: 4byte)

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



		

	
