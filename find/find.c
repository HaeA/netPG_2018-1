#include <stdio.h>
#include <string.h>
#include "./KISA_SHA256.h"

#define len 50 //�Է� �����ͺ��� �۾����� ������. ��ö�� 10���̳��� ��� �ּ� 40���� ������ ��.

typedef unsigned char BYTE;
typedef unsigned int UNIT;

FILE * pw;

int main() {

	//BYTE p[len]; //�򹮾�ȣ
	BYTE e[len]; //��ȣȭ�� ��ȣ
	//BYTE ip[len]; //ip�ּ� �޾ƿͼ� �򹮾�ȣ�� ��ġ��
	BYTE cm[len]; //��ȣ �񱳿�

	char p[len];
	char ip[len];

	UNIT p_len = 0; //�� ����
	BYTE db[len]; //����� ��ȣ �ҷ�����

	int cmp = -1;

	memset(p, 0x00, sizeof(p));
	memset(e, 0x00, sizeof(e));
	memset(ip, 0x00, sizeof(ip));
	memset(db, 0x00, sizeof(db));

	pw = fopen("pass.bin", "ab");

	printf("ip: ");
	scanf("%200s", ip); //ip�޾ƿ���

	printf("password: ");
	scanf("%200s", p); //���� ���� ���� ����. 200byte = ��ö�� 200��, ���� 50��(char: 1byte, int: 4byte)

	strcat(ip, p);
	
	p_len = strlen((char*) ip);
	
	SHA256_Encrpyt((BYTE*)ip, p_len, e);

	fread(&db, sizeof(db), len, pw);
	printf("%s", db);

	//sprintf(cm, "%02X", e);


	/*
	while(!feof(pw)) {
		fread(&db, sizeof(db), len, pw);
		printf("%s", db);
		
	}*/

	fclose(pw);
	return 0;
}
