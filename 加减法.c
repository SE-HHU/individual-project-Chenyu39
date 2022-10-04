#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int answer(int a,char f,int b)   //计算运算符为一个时题目的结果
{
	int c;
	if(f=='+')
	c=a+b;
	if(f=='-')
	c=a-b;
	return c;
}
int answer1(int a,char f,int b,char f1,int c)  //计算运算符为两个时题目的结果
{
	int c1;
	if((f=='+')&&(f1=='+'))
		c1=a+b+c;
	else if((f=='+')&&(f1=='-'))
		c1=a+b-c;
	else if((f=='-')&&(f1=='+'))
		c1=a-b+c;
	else if((f=='-')&&(f1=='-'))
		c1=a-b-c;
	return c1;
}
void  check(int *x,int e,int x2)  //检查随机出来的数是否重复
	{
		while(1)
		{ 
		int flag=0,m;
		for(m=0;m<e;m++)
		{
			if(x[m]==x2)
			{
				flag=1;break;
			}
		}
			if(flag==0)
			{
				x[e]=x2;
				break;
			}
			x2=rand()%99+1;
		}
	}

int main()
{ 
	
	FILE*fp1,*fp2;
	int i,n=0,j,s,s1,x0,y0,z0,h;
	int x[500],y[500],z[500],jieguo[500];
	char ysf,ysf1;
	printf("请输入题目数量（1-500）：");     
	scanf("%d",&n);                               //键盘输入数字控制题目数量，在1-500范围内
	if(n<=0)
		{printf("题目量过小，不能偷懒哦，请重新输入");
	scanf("%d",&n);}
	if(n>499)
		{printf("题目量过大，请重新输入");
	scanf("%d",&n);}
	if((fp1=fopen("d:\\Exercises.txt","w+"))==NULL)
	{
		printf("can't open this file.\n");
	    exit(0);
	}
	if((fp2=fopen("d:\\Answers.txt","w+"))==NULL)
	{
		printf("can't open this file.\n");
	    exit(0);
	}
	srand(time(0));
	
	for(i=0;i<n;i++)        //随机题目中的数字
	{
		s=rand()%2;
		s1=rand()%2;
		x0=rand()%99+1;
		y0=rand()%99+1;
		z0=rand()%99+1;
		if(s==0)          //随机题目中运算符的个数
			ysf='+';
		else
			ysf='-';
		if(s1==0)
			ysf1='+';
		else
			ysf1='-';
		x[i]=x0;
		y[i]=y0;
		z[i]=z0;
	
		if(i>0)
		{
			check(x,i,x0);    //检查随机出来的数字是否重复
			check(y,i,y0);
			check(z,i,z0);
		}
		h=rand()%2;
		if(h==0)                               //随机运算符个数，h==0时运算符为1，否则运算符为2
		{jieguo[i]=answer(x[i],ysf,y[i]);
		printf("四则运算题目%d:%d%c%d=\n",i+1,x[i],ysf,y[i]);
    fprintf(fp1,"四则运算题目%d:%d%c%d=\n",i+1,x[i],ysf,y[i]);    //运算符为1个时，将题目，答案分别写入文件Exercises.txt和Answers.txt中
    fprintf(fp2,"四则运算题目%d:%d%c%d=%d\n",i+1,x[i],ysf,y[i],jieguo[i]);
		}
		else
		{	jieguo[i]=answer1(x[i],ysf,y[i],ysf1,z[i]);
		printf("四则运算题目%d:%d%c%d%c%d=\n",i+1,x[i],ysf,y[i],ysf1,z[i]);
    fprintf(fp1,"四则运算题目%d:%d%c%d%c%d=\n",i+1,x[i],ysf,y[i],ysf1,z[i]);     //运算符为2个时，将题目，答案分别写入文件Exercises.txt和Answers.txt中 
	fprintf(fp2,"四则运算题目%d:%d%c%d%c%d=%d\n",i+1,x[i],ysf,y[i],ysf1,z[i],jieguo[i]);
	    }
	}
		
	if(fclose(fp1))
	{
		printf("can't close the file\n");
		exit(0);
	}
	if(fclose(fp2))
	{
		printf("can't close the file\n");
		exit(0);
	}

return 0;
}


