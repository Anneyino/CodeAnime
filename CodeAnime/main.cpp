#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
const int MAX = 3000;
char pic[MAX][20000];
void cls()
{
	COORD x = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void delay(float x)
{
	float toTime = x + 1.0*clock() / CLOCKS_PER_SEC;
	while (1.0*clock() / CLOCKS_PER_SEC<toTime)
	{
		continue;
	}
}

/*

控制台要调下字体，软件运行后右击cmd的标题，选属性-字体-大小-14，字体我设的是黑体,其他的效果可能不太好
然后按任意键开始执行

txt文件可以简单地用 ascii generator2 这个工具生成
*/
int main()
{
	system("mode con cols=60 lines=20");
	printf("press any key to start\n");
	getchar();
	system("mode con cols=213 lines=47");
	char asc;
	int index, temp, num;
	FILE *file;
	int a[4] = { 1000,100,10,1 };

	printf("loading...\n");
	for (int i = 0; i <= MAX; i++)
	{
		index = 0;
		temp = i;
		char name[100] = { "pic\\ASCII-" };
		//这个是路径，不改的话 pic文件夹 要放在main.cpp所在的文件夹
		char sub[] = { "0" };
		for (int j = 0; j < 4; j++)
		{
			sub[0] = temp / a[j] + '0';
			strcat(name, sub);
			temp = temp % a[j];
		}
		strcat(name, ".txt");
		file = fopen(name, "r");
		if (file == NULL) {
			num = i;
			printf("load completely\n");
			break;
		}
		while ((asc = fgetc(file)) != EOF)
		{
			pic[i][index] = asc;
			index++;
		}
		fclose(file);
	}
	delay(0.8);
	system("color F0");
	delay(0.3);
	cls();
	for (int i = 0; i <num; i++)
	{
		cls();
		printf("%s\n", pic[i]);
		printf("%d", i);
		delay(1.0 / 22.5);
	}
	return 0;
}