/*
*作者：李集
*时间：有点忘了。好像是两个月前的某天（今天是2014-11-29）。
*程序内容：实现简单万年历查询
*注：代码是以前写的，现在看来比较幼稚，但不想改动了，留着自己重温时提醒自己，
*    顺便看看过去的自己。
*^_^
*/


#include<stdio.h>

//判断是否是闰年
int runnian(int year)
{
	int flag = 0;
	if((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0))
		flag = 1;
	return flag;
}

//判断一年有多少天
int tianshu(int year)
{
	int day;
	if(runnian(year))
	{
		day = 366;
	}
	else
	{
		day = 365;
	}
	return day;
}

//判断这个月一号距离1900年1月1日有多少天
int juli(int year, int month)
{
	int num = 0;
	int n = year - 1900;
	int i;

	for(i = 1; i <= n; i++)
	{
		num += tianshu(1900 + i);
	}
	
	switch(month)
	{
		case 1: break;
		case 2: num += 31; break;
		case 3: num += 59; break;
		case 4: num += 90; break;
		case 5: num += 120; break;
		case 6: num += 151; break;
		case 7: num += 181; break;
		case 8: num += 212; break;
		case 9: num += 243; break;
		case 10: num += 273; break;
		case 11: num += 304; break;
		case 12: num += 334; break;
		default: break;
	}
	if(runnian(year) && (month > 2))
		return num + 1;
	else
		return num;
}
//判断这一年该月的第一天是星期几
int xingqi(int year, int month)
{
	
	int a[7] ={0, 1, 2, 3, 4, 5, 6};
	

	int num;
	num = juli(year, month);

	int i = num % 7;

	return a[i + 1];
}

//输出开头
void kaitou()
{
	printf("\n-------------------------- 万年历 ----------------------------\n\n");

}

//输出表格
void biaoge(int year, int month)
{
	printf("日\t一\t二\t三\t四\t五\t六\t\n\n");
	int day = juli(year, month + 1) - (juli(year, month));
	
	int i;
	int xingqishu;
	xingqishu = xingqi(year, month);

	int count = 0;
	int j;
	for(j = 0; j < xingqishu; j++)
	{
		printf(" \t");
		count++;
		if(count % 7 == 0)
			printf("\n");
	}
//	i = j;  不能用i继承j的值。

	int num = 0;   //不能从1开始。
	for(i = 0; i < day; i++)
	{
		printf("%d\t", ++num);
		count++;
		if(count % 7 == 0)
			printf("\n");
	}
	printf("\n\n");
//	printf("\n%d月份有%d天。\n", month, day);
}


int main()
{
	kaitou();

	int year;
	printf("请输入年份：");
	scanf("%d", &year);
	
/*	
	int flag;
	flag = runnian(year);

	if(flag == 1)
		printf("是闰年。\n");
	else
		printf("不是闰年\n");
	
	int day;
	day = tianshu(year);

	printf("%d年有%d天。\n", year, day);
	
	int num;
*/
	int month;
	
	printf("请输入月份：");
	scanf("%d", &month);
	printf("\n");
/*
	num = juli(year, month);
	printf("%d年%d月距离1900年1月1日有%d天。\n", year, month, num);

	int i;
	i = xingqi(year, month);
	printf("%d年%d月第一天是星期%d。\n", year, month, i);
*/	
	biaoge(year,month);

	return 0;

}

	

