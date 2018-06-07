#include <stdio.h>
#include <string.h>
#include "./KISA_SHA256.h"

#define len 50 //�Է� �����ͺ��� �۾����� ������. ��ö�� 10���̳��� ��� �ּ� 40���� ������ ��.

typedef unsigned char BYTE;
typedef unsigned int UNIT;

FILE * pw;

int main() {

	BYTE p[len]; //�򹮾�ȣ
	BYTE e[len]; //��ȣȭ�� ��ȣ
	BYTE ip[len]; //ip�ּ� �޾ƿͼ� �򹮾�ȣ�� ��ġ��
	BYTE cm[len]; //��ȣ �񱳿�

	UNIT p_len = 0; //�� ����
	BYTE db[len]; //����� ��ȣ �ҷ�����

	int cmp = -1;

	memset(p, 0x00, sizeof(p));
	memset(e, 0x00, sizeof(e));
	memset(ip, 0x00, sizeof(ip));
	memset(db, 0x00, sizeof(db));

	pw = fopen("pass.txt", "r");

	printf("ip: ");
	scanf("%200s", ip); //ip�޾ƿ���

	printf("password: ");
	scanf("%200s", p); //���� ���� ���� ����. 200byte = ��ö�� 200��, ���� 50��(char: 1byte, int: 4byte)

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
