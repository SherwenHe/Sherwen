//进制转换 
#include<stdio.h>

//字符转数字 
int char2num(char ch)
{
	if(ch >= '0' && ch <= '9')
		return ch - '0';
	else
		return ch - 'a' + 10;
}

//数字转字符 
char num2char(int num)
{
	if(num >=0 && num <= 9)
		return num + '0';
	else
		return num - 10 + 'a';
}

// 转化为目标进制 
long source2decimal(char tmp[],int source)
{
	int len = 0;
	int num = 0;
	for(;tmp[len] != '\0';len++)
	{
		num = num * source;
		num += char2num(tmp[len]);
	}
	return num;
	
}

//取余存放在数组 
int decimal2obj(char tmp[],long decimal,int obj)
{
	int len = 0;
	int rem;
	
	while(decimal)
	{
		rem = decimal % obj;
		tmp[len++] = num2char(rem);
		decimal = decimal / obj;  
	}
	tmp[len] = '\0';
	
	return len;
}

void output(char tmp[],int len)
{
	int i;
	for(i = len-1 ;i >= 0;i--)
		printf("%c",tmp[i]);
	printf("\n");
}


int main()
{
	char tmp[100];
	int source;
	int obj;
	int flag = 1;
	int dec_num;
	int len;
	while(flag)
	{
		printf("Input a number:");//输入一个数
		scanf("%s",tmp); 
               
		printf("Input source:") ;//输入源进制
		scanf("%d",&source);

		printf("Input object:");//输入目标进制        
		scanf("%d",&obj);
		
		dec_num = source2decimal(tmp,source);//将源进制转化为十进制
		len = decimal2obj(tmp,dec_num,obj);//将十进制转化为目标进制
		output(tmp,len);//输出目标进制
		
		printf("Continue?1/0:");
		scanf("%d",&flag);
		
	}
	
	return 0;
}
