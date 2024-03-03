#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define STRSIZE 50
#define SIZE 20

//�ܿ��
typedef struct Student {
	char name[STRSIZE];
	int number;
	struct std* link;
} std;

void freeNode(std* list) {
	std* pa = list;
	while (pa) {
		list = list->link;
		free(pa);
		pa = list;
	}
}

void Nodef() {
	std* list = NULL, * p = NULL, * prev = NULL;
	char buffer[STRSIZE];
	int number;

	while (1) {
		printf("name : ");
		//scanf("%s", &buffer);
		gets_s(buffer, STRSIZE); //gets_s�� ���ͱ��� �Է¹���
		if (buffer[0] == 0) break;
		p = (std*)malloc(sizeof(std));
		strcpy(p->name, buffer);
		printf("number : ");
		//scanf("%d", &p->name);
		gets_s(buffer, STRSIZE);
		number = stoi(buffer);
		p->number = number;

		p->link = NULL;
		if (!list) list = p;
		else prev->link = p;
		prev = p;
	}

	p = list;
	while (p) {
		print("[%s %d] ->", p->name, p->number);
		p = p->link;
	}
	printf("NULL\n");
}

void filef() {
	std c;
	int count;
	double number[SIZE];
	FILE* fp1, * fp2; // * fp

	printf("count : ");
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("number : ");
		scanf("%lf", &number[i]);
	}

	//a�� �迭�̸� ��ü������ �ּҸ� ��Ÿ���⿡ �׳� a, �迭 �ƴϸ� &�� �ٿ��� &a�� ��
	if ((fopen("count.dat", "wb")) == NULL) printf("e\n");
	fwrite(&count, sizeof(int), 1, fp1);

	if ((fopen("number.dat", "wb")) == NULL) printf("e\n");
	fwrite(number, sizeof(double), count, fp2);

	if ((fopen("count.dat", "rb")) == NULL) printf("e\n");
	fread(&count, sizeof(int), 1, fp1);
	if ((fopen("number.dat", "wb")) == NULL) printf("e\n");
	fread(number, sizeof(double), count, fp2);
	//fread(number, sizeof(double), SIZE, fp2);

	//struct
	//fwrite(&c, sizeof(std), 1, fp)

	fclose(fp1);
	fclose(fp2);
}

void sPrintf() {
	char buffer[STRSIZE];
	int x, y, result;
	result = x + y;
	sprintf(buffer, "%d + %d = %d\n", x, y, +result);
	printf(buffer);
}

void sScanf() {
	char instring[STRSIZE];
	char name[STRSIZE];
	int number;
	
	printf("input str : ");
	scanf("%s", &instring);
	
	sscanf(instring, "%s, %d", name, number); //instring�� ���ںκ��� name��, �����κ��� number�� ����
	printf("%s ", name);
	printf("%d\n", number);
}

void atoF() {
	char a = "100", b = "12.93";
	int i;
	double f;

	i = atoi(a); //���ڿ��� ������
	f = atof(b); //���ڿ��� �Ǽ���

	printf("%d, %lf\n", i, f);
}

void chf() {
	int ch;
	while ((ch = _getch()) != "\r") { //���� ����������
		_putch('*');
	}
	while ((ch = _getche()) != 'q') { //ch = ���;��� Ű���� �״�� �Է�, che = ch�� ���� �߰�, � Ű�� �������� �˷���
		_putch(ch);
	}
	while ((ch = getch()) != 'q') {
		_putch(ch);
	}
	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}
}

void putf() {
	char name = "atem", code = "high";

	putchar('\n');
	puts(name);
	puts(code);
}

void repeatLogic() {
	char str[STRSIZE];
	scanf("%s", &str);
	int n = strlen(str); //strlen = ���� ���� ��
	int count = 0;

	for (int i = 0; i < n/2; i++) {
		if (str[n - i - 1] == str[i]) {
			printf("ȸ���Դϴ�\n");
			count = 1;
			break;
		}
	}
	if (count == 0) printf("ȸ���� �ƴմϴ�.\n");
}

void passwordLogic() {
	char pw[STRSIZE];
	char a[STRSIZE];
	int ch;
	int n = 0;

	if ((ch = getch()) != '\r') {
		_putch('*');
		a[n] == ch;
		n++;
	}

	a[n] = '\0';
	printf("\n");
	if (strcmp(a, pw) == 0) printf("good\n");
	else printf("bad\n");
}

int main() {
	int ch;
	while ((ch = _getch()) != '\r') {
		_putch('*');
	}
	return 0;
}