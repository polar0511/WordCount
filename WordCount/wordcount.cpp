#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("������������У�����ִ��\n");
		return 0;
	}
	int i = 0, flag = 0;
	char a[100], n;
	FILE* fp;
	errno_t err= fopen_s(&fp,argv[2], "r+");
	if (fp == NULL) {//��֤�ļ��򿪳ɹ� 
		printf("�ļ���ʧ��");
		return -1;
	}
	while (!feof(fp)) {//����ļ������� 
		fscanf_s(fp, "%c", &n);//���ļ��ж�ȡ�ַ����������� 
		a[i] = n;
		i++;
	}
	rewind(fp);
	if (strcmp(argv[1], "-c") == 0) {//ͳ���ַ��� 
		flag = 0;
		if (a[0] != NULL) {
			for (i = 0; a[i] != NULL; i++) {
				if (a[i] == 9 || a[i] == 10 || (a[i] > 31 && a[i] < 127)) {
					flag++;
				}
			}
			printf("�ַ�����%d\n", flag - 1);
		}
		else {
			printf("�ַ�����0\n");
		}
	}
	else if (strcmp(argv[1], "-w") == 0) {//ͳ�Ƶ����� 
		flag = 0;
		if (a[0] != NULL) {
			for (i = 0; i < 100; i++) {
				if (a[i] == 32 || a[i] == 44) {
					flag++;
				}
			}
			printf("������: %d\n", flag + 1);
		}
		else {
			printf("������: 0");
		}
	}
	fclose(fp);
	system("pause");
	return 0;
}