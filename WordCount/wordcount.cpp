#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("输入错误命令行，结束执行\n");
		return 0;
	}
	int i = 0, flag = 0;
	char a[100], n;
	FILE* fp;
	errno_t err= fopen_s(&fp,argv[2], "r+");
	if (fp == NULL) {//保证文件打开成功 
		printf("文件打开失败");
		return -1;
	}
	while (!feof(fp)) {//检测文件结束符 
		fscanf_s(fp, "%c", &n);//从文件中读取字符放入数组中 
		a[i] = n;
		i++;
	}
	rewind(fp);
	if (strcmp(argv[1], "-c") == 0) {//统计字符数 
		flag = 0;
		if (a[0] != NULL) {
			for (i = 0; a[i] != NULL; i++) {
				if (a[i] == 9 || a[i] == 10 || (a[i] > 31 && a[i] < 127)) {
					flag++;
				}
			}
			printf("字符数：%d\n", flag - 1);
		}
		else {
			printf("字符数：0\n");
		}
	}
	else if (strcmp(argv[1], "-w") == 0) {//统计单词数 
		flag = 0;
		if (a[0] != NULL) {
			for (i = 0; i < 100; i++) {
				if (a[i] == 32 || a[i] == 44) {
					flag++;
				}
			}
			printf("单词数: %d\n", flag + 1);
		}
		else {
			printf("单词数: 0");
		}
	}
	fclose(fp);
	system("pause");
	return 0;
}