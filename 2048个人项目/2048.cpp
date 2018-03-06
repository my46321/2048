#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include<time.h>
#include<stdio.h>
#pragma comment(lib,"Winmm.lib")


void background();
void background1();
void background2();
void background3();
void start();
void movemusic();
int ini();
void end();
void control(int []);
void control1(int []);
void control2(int[]);
int score=0;//��¼����
int q=0;//�ж���Ϸ�Ƿ����
int judge=0;//�ж���Ϸģʽ

void main()
{

	int cnt=0;
	int judgemode;
	char num1[100],num2[100];
	int s[16]={0};
	int x,y;//��¼��ʼ2�������λ��
	initgraph(640,480);
	srand( (unsigned)time(NULL));//
	background();
	background1(); //��ʼ���� 
	start();
	
	x=ini();
	y=ini();
	while (x==y)
		x=ini();

	judgemode = rand() % 2;

	s[x]=s[y]=2;
	setfont(60,0,"����");
	settextcolor(RGB(244,164,96));
	if (judge==0)
	{sprintf(num1,"%d",s[x]);
	sprintf(num2,"%d",s[y]);
	outtextxy(80+(x%4)*100,80+(x/4)*100,num1);
	outtextxy(80+(y%4)*100,80+(y/4)*100,num2);//��ʼ��2���������Ϊ2
	}
	else
	{
	setfont(60, 0, "�����п�");
	if(judgemode==1)
	    outtextxy(80+(x%4)*100,80+(x/4)*100,"H"),
	    outtextxy(80+(y%4)*100,80+(y/4)*100,"H");
	else
		outtextxy(80 + (x % 4) * 100, 80 + (x / 4) * 100, "��"),
		outtextxy(80 + (y % 4) * 100, 80 + (y / 4) * 100, "��");
	}



	
	do
	{
	cnt=0;
	if (judge==0)
	    control(s);
	else
	{
		if (judgemode == 1)
			control1(s);
		else
			control2(s);
	}
	for (int i=0;i<16;i++)
	{
		if (s[i]!=0)
			cnt++;
	}
	if (cnt==16)
	{q++;
	 end();
	}
	}while(q==0);//�ƶ�����

}


void movemusic()
{
    mciSendString("stop music", NULL, 0, NULL);
	mciSendString("close music", NULL, 0, NULL);
	mciSendString("open 3.wav alias music", NULL, 0, NULL);
	mciSendString("play music", NULL, 0, NULL);//��������
}


void start()
{
	MOUSEMSG m;
	while (true)
	{
		float H=255;
		float S=99;
		float L=71;
		m = GetMouseMsg();
		if (m.x>250 && m.x<410 && m.y>300&&m.y<340)
		{
			settextcolor(RGB(H, S, L));
			setfont(40,0,"�����п�"); 
		    outtextxy(250,300, "Ȥζģʽ");
			if (m.uMsg==WM_LBUTTONDOWN)
			{
			mciSendString("stop mymusic", NULL, 0, NULL);
	        mciSendString("close mymusic", NULL, 0, NULL);//�رձ�������
			background2();
			judge++;
			break;}
		}
		else
		{
			settextcolor(WHITE);
			setfont(40,0,"�����п�"); 
		    outtextxy(250,300, "Ȥζģʽ");
		}
		if (m.x>250 && m.x<410 && m.y>250&&m.y<290)
		{
			settextcolor(RGB(H, S, L));
			setfont(40,0,"�����п�"); 
		    outtextxy(250,250, "��ʼ��Ϸ");
			if (m.uMsg==WM_LBUTTONDOWN)
			{
			mciSendString("stop mymusic", NULL, 0, NULL);
	        mciSendString("close mymusic", NULL, 0, NULL);//�رձ�������
			background2();
			break;}
		}
		else
		{
			settextcolor(WHITE);
			setfont(40,0,"�����п�"); 
		    outtextxy(250,250, "��ʼ��Ϸ");
		}
		if (m.x>250 && m.x<410 && m.y>350&&m.y<390)
		{
			settextcolor(RGB(H, S, L));
			setfont(40,0,"�����п�"); 
		    outtextxy(250,350, "����˵��");
			if (m.uMsg==WM_LBUTTONDOWN)
			{background3();
			Sleep(3000);
			mciSendString("stop mymusic", NULL, 0, NULL);
	        mciSendString("close mymusic", NULL, 0, NULL);//�رձ�������
			background2();
			break;
			}
		}
		else
		{
			settextcolor(WHITE);
			setfont(40,0,"�����п�"); 
		    outtextxy(250,350, "����˵��");
		}
		if (m.x>250 && m.x<410 && m.y>400&&m.y<440)
		{
			settextcolor(RGB(H, S, L));
			setfont(40,0,"�����п�"); 
		    outtextxy(250,400, "�˳���Ϸ");
			if (m.uMsg==WM_LBUTTONDOWN)
			{closegraph();
			break;}
		}
		else
		{
			settextcolor(WHITE);
			setfont(40,0,"�����п�"); 
		    outtextxy(250,400, "�˳���Ϸ");
		}
	}
}


void background()
{
loadimage(NULL, "C:\\Users\\meng\\Desktop\\2048\\2048\\8.jpg",640,480);
Sleep(3000);
}


void background1()
{


	setbkmode(TRANSPARENT);	
	setfont(40,0,"�����п�"); 
	outtextxy(520,440, "by MY");

}


void background2()
{
	cleardevice();
	loadimage(NULL, "C:\\Users\\meng\\Desktop\\2048\\2048\\10.jpg",660,510);
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	for(int i=0;i<=4;i++)
	{line(50+100*i,50,50+100*i,450);}
	for(int j=0;j<=4;j++)
	{line(50,50+100*j,450,50+100*j);}
	for(int x=0;x<=30;x++)
	{line(0,x,640,x);}
	settextcolor(RGB(244,164,96));
	setfont(40,0,"�����п�");
	outtextxy(460, 150, "q:������Ϸ");
	outtextxy(460, 200, "w:����");
	outtextxy(460, 250, "s:����");
	outtextxy(460, 300, "a:����");
	outtextxy(460, 350, "d:����");
	outtextxy(460,100,"����:");
}


void background3()
{
	cleardevice();
	loadimage(NULL, "C:\\Users\\meng\\Desktop\\2048\\2048\\10.jpg",660,510);
    settextcolor(RGB(255,160,122));
	outtextxy(240,100, "w:����");
	outtextxy(240,150, "s:����");
	outtextxy(240,200, "a:����");
	outtextxy(240,250, "d:����");
	outtextxy(240,300, "q:�˳���Ϸ");
	outtextxy(240,350, "2s���Զ�������Ϸ");

}


int ini()
{
	int a;
	srand( (unsigned)time(NULL));
	a=rand()%16;
	return a;
}//��ʼ��λ��


void control(int *s)
{
	int p[16]={0};
	int y=0;
	int  i,j,x;
	char out3[16][100];
	int t;
	char c;
	int num[4][4];
	for (i=0;i<4;++i)
	{
		for (j=0;j<4;j++)
		{
			num[i][j]=s[4*i+j];
		}
	}
	setfont(50,0,"�����п�");
	char sco[100];
	sprintf(sco,"%d",score);
	outtextxy(550,100,sco);
	score+=10;
	c=getch();
	movemusic();
    switch(c)
	{
	case 'a':
		for (i=0;i<4;i++)
		{
		 for(x=0;x<3;x++)
		 {
		 for(j=2;j>=0;j--)
		 {
			if (num[i][j]==0)
			{
			t=num[i][j+1];
			num[i][j+1]=num[i][j];
			num[i][j]=t;
			}
		 }
		 }
		}
		for(i=0;i<4;i++)
		{
						for(j=0;j<3;j++)
							if(num[i][j]==num[i][j+1])
							{
								if(num[i][j]!=0)
									score+=12;
								num[i][j]=num[i][j+1]+num[i][j];
								num[i][j+1]=0;						
							}
		}
		for (i=0;i<4;i++)
		{
		for(x=0;x<3;x++)
		{
		for(j=2;j>=0;j--)
		{
			if (num[i][j]==0)
			{
			t=num[i][j+1];
			num[i][j+1]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{        
					    setfont(50,0,"����");
						sprintf(out3[i],"%d",s[i]);
						outtextxy(80+(i%4)*100,80+(i/4)*100,out3[i]);	 
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
	    setfont(50,0,"����");
		sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,out3[j]);
		break;

    case 'd':
	    for (i=0;i<4;i++)
		{
		for(x=0;x<3;x++)
		{
		for(j=1;j<=3;j++)
		{
			if (num[i][j]==0)
			{
			t=num[i][j-1];
			num[i][j-1]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for(i=0;i<4;i++)
		{
						for(j=0;j<3;j++)
							if(num[i][j]==num[i][j+1])
							{
								num[i][j]=num[i][j+1]+num[i][j];
								num[i][j+1]=0;
								if(num[i][j]!=0)
									score+=12;
							}
		}
		for (i=0;i<4;i++)
		{
		for(x=0;x<3;x++)
		{
		for(j=1;j<=3;j++)
		{
			if (num[i][j]==0)
			{
			t=num[i][j-1];
			num[i][j-1]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{
						setfont(50,0,"����");
						sprintf(out3[i],"%d",s[i]);
						outtextxy(80+(i%4)*100,80+(i/4)*100,out3[i]);	 
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
		setfont(50,0,"����");
		sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,out3[j]);
		break;
	
	case 'w':
		for (j=0;j<=3;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=0;i<3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i+1][j];
			num[i+1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for(j=0;j<4;j++)
		{
						for(i=0;i<4;i++)
							if(num[i][j]==num[i+1][j])
							{
								num[i][j]=num[i+1][j]+num[i][j];
								num[i+1][j]=0;
								if(num[i][j]!=0)
									score+=12;
							}
		}
	    for (j=0;j<4;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=0;i<3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i+1][j];
			num[i+1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{
						setfont(50,0,"����");
						sprintf(out3[i],"%d",s[i]);
						outtextxy(80+(i%4)*100,80+(i/4)*100,out3[i]);	 
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
		setfont(50,0,"����");
		sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,out3[j]);
		break;
	
	case 's':
		for (j=0;j<4;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=1;i<=3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i-1][j];
			num[i-1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for(j=0;j<4;j++)
		{
						for(i=0;i<4;i++)
							if(num[i][j]==num[i+1][j])
							{
								num[i][j]=num[i+1][j]+num[i][j];
								num[i+1][j]=0;
								if(num[i][j]!=0)
									score+=12;
							}
		}
        for (j=0;j<4;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=1;i<=3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i-1][j];
			num[i-1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{
						setfont(50,0,"����");
						sprintf(out3[i],"%d",s[i]);
						outtextxy(80+(i%4)*100,80+(i/4)*100,out3[i]);	 
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
        setfont(50,0,"����"); 	
		sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,out3[j]);
		break;

	case 'q':
		q++;
		end();
		break;

	default:
		break;
	}

	
}

void control1(int *s)
{
	int p[16]={0};
	int y=0;
	int  i,j,x;
	int t;
	char c;
	int num[4][4];
	for (i=0;i<4;++i)
	{
		for (j=0;j<4;j++)
		{
			num[i][j]=s[4*i+j];
		}
	}
	setfont(50,0,"�����п�");
	char sco[100];
	sprintf(sco,"%d",score);
	outtextxy(550,100,sco);
	score+=10;
	c=getch();
	movemusic();
    switch(c)
	{
	case 'a':
		for (i=0;i<4;i++)
		{
		 for(x=0;x<3;x++)
		 {
		 for(j=2;j>=0;j--)
		 {
			if (num[i][j]==0)
			{
			t=num[i][j+1];
			num[i][j+1]=num[i][j];
			num[i][j]=t;
			}
		 }
		 }
		}
		for(i=0;i<4;i++)
		{
						for(j=0;j<3;j++)
							if(num[i][j]==num[i][j+1])
							{
								if(num[i][j]!=0)
									score+=12;
								num[i][j]=num[i][j+1]+num[i][j];
								num[i][j+1]=0;						
							}
		}
		for (i=0;i<4;i++)
		{
		for(x=0;x<3;x++)
		{
		for(j=2;j>=0;j--)
		{
			if (num[i][j]==0)
			{
			t=num[i][j+1];
			num[i][j+1]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{        
					    setfont(50,0,"�����п�");
						//sprintf(out3[i],"%d",s[i]);
						if (s[i]==2)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"H");
						if (s[i]==4)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"He");
						if (s[i]==8)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Li");
						if (s[i]==16)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Be");
						if (s[i]==32)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"B");
						if (s[i]==64)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"C");
						if (s[i]==128)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"N");
						if (s[i]==256)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"O");
						if (s[i]==512)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"F");
						if (s[i]==1024)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Ne");
						if (s[i]==2048)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Na");
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,"H");
		break;

    case 'd':
	    for (i=0;i<4;i++)
		{
		for(x=0;x<3;x++)
		{
		for(j=1;j<=3;j++)
		{
			if (num[i][j]==0)
			{
			t=num[i][j-1];
			num[i][j-1]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for(i=0;i<4;i++)
		{
						for(j=0;j<3;j++)
							if(num[i][j]==num[i][j+1])
							{
								num[i][j]=num[i][j+1]+num[i][j];
								num[i][j+1]=0;
								if(num[i][j]!=0)
									score+=12;
							}
		}
		for (i=0;i<4;i++)
		{
		for(x=0;x<3;x++)
		{
		for(j=1;j<=3;j++)
		{
			if (num[i][j]==0)
			{
			t=num[i][j-1];
			num[i][j-1]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{
						setfont(50,0,"�����п�");
						//sprintf(out3[i],"%d",s[i]);
						if (s[i]==2)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"H");
						if (s[i]==4)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"He");
						if (s[i]==8)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Li");
						if (s[i]==16)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Be");
						if (s[i]==32)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"B");
						if (s[i]==64)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"C");
						if (s[i]==128)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"N");
						if (s[i]==256)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"O");
						if (s[i]==512)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"F");
						if (s[i]==1024)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Ne");
						if (s[i]==2048)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Na");
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,"H");
		break;
	
	case 'w':
		for (j=0;j<=3;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=0;i<3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i+1][j];
			num[i+1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for(j=0;j<4;j++)
		{
						for(i=0;i<4;i++)
							if(num[i][j]==num[i+1][j])
							{
								num[i][j]=num[i+1][j]+num[i][j];
								num[i+1][j]=0;
								if(num[i][j]!=0)
									score+=12;
							}
		}
	    for (j=0;j<4;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=0;i<3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i+1][j];
			num[i+1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{
						setfont(50,0,"�����п�");
						//sprintf(out3[i],"%d",s[i]);
							if (s[i]==2)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"H");
						if (s[i]==4)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"He");
						if (s[i]==8)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Li");
						if (s[i]==16)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Be");
						if (s[i]==32)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"B");
						if (s[i]==64)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"C");
						if (s[i]==128)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"N");
						if (s[i]==256)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"O");
						if (s[i]==512)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"F");
						if (s[i]==1024)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Ne");
						if (s[i]==2048)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Na");	 
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,"H");
		break;
	
	case 's':
		for (j=0;j<4;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=1;i<=3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i-1][j];
			num[i-1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for(j=0;j<4;j++)
		{
						for(i=0;i<4;i++)
							if(num[i][j]==num[i+1][j])
							{
								num[i][j]=num[i+1][j]+num[i][j];
								num[i+1][j]=0;
								if(num[i][j]!=0)
									score+=12;
							}
		}
        for (j=0;j<4;j++)
		{
		for(x=0;x<3;x++)
		{
		for(i=1;i<=3;i++)
		{
			if (num[i][j]==0)
			{
			t=num[i-1][j];
			num[i-1][j]=num[i][j];
			num[i][j]=t;
			}
		}
		}
		}
		for (i=0;i<4;++i)
		{
		for (j=0;j<4;j++)
		{
			s[4*i+j]=num[i][j];
		}
		}
		background2();
		for(i=0;i<16;i++)
			{
				if(s[i]!=0)
				{
						setfont(50,0,"�����п�");
						//sprintf(out3[i],"%d",s[i]);
						if (s[i]==2)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"H");
						if (s[i]==4)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"He");
						if (s[i]==8)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Li");
						if (s[i]==16)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Be");
						if (s[i]==32)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"B");
						if (s[i]==64)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"C");
						if (s[i]==128)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"N");
						if (s[i]==256)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"O");
						if (s[i]==512)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"F");
						if (s[i]==1024)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Ne");
						if (s[i]==2048)
						   outtextxy(80+(i%4)*100,80+(i/4)*100,"Na");	 
				}
			}
		for(i=0;i<16;i++)
		{
			if (s[i]==0)
				p[y++]=i;	
		}
		x=rand()%y;
		j=p[x];
		s[j]=2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80+(j%4)*100,80+(j/4)*100,"H");
		break;

	case 'q':
		q++;
		end();
		break;

	default:
		break;
	}

	
}

void control2(int *s)
{
	int p[16] = { 0 };
	int y = 0;
	int  i, j, x;
	int t;
	char c;
	int num[4][4];
	for (i = 0; i<4; ++i)
	{
		for (j = 0; j<4; j++)
		{
			num[i][j] = s[4 * i + j];
		}
	}
	setfont(50, 0, "�����п�");
	char sco[100];
	sprintf(sco, "%d", score);
	outtextxy(550, 100, sco);
	score += 10;
	c = getch();
	movemusic();
	switch (c)
	{
	case 'a':
		for (i = 0; i<4; i++)
		{
			for (x = 0; x<3; x++)
			{
				for (j = 2; j >= 0; j--)
				{
					if (num[i][j] == 0)
					{
						t = num[i][j + 1];
						num[i][j + 1] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (i = 0; i<4; i++)
		{
			for (j = 0; j<3; j++)
				if (num[i][j] == num[i][j + 1])
				{
					if (num[i][j] != 0)
						score += 12;
					num[i][j] = num[i][j + 1] + num[i][j];
					num[i][j + 1] = 0;
				}
		}
		for (i = 0; i<4; i++)
		{
			for (x = 0; x<3; x++)
			{
				for (j = 2; j >= 0; j--)
				{
					if (num[i][j] == 0)
					{
						t = num[i][j + 1];
						num[i][j + 1] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (i = 0; i<4; ++i)
		{
			for (j = 0; j<4; j++)
			{
				s[4 * i + j] = num[i][j];
			}
		}
		background2();
		for (i = 0; i<16; i++)
		{
			if (s[i] != 0)
			{
				setfont(50, 0, "�����п�");
				//sprintf(out3[i],"%d",s[i]);
				if (s[i] == 2)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 4)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 8)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 16)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 32)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 64)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 128)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 256)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 512)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 1024)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "Ԫ");
				if (s[i] == 2048)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
			}
		}
		for (i = 0; i<16; i++)
		{
			if (s[i] == 0)
				p[y++] = i;
		}
		x = rand() % y;
		j = p[x];
		s[j] = 2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80 + (j % 4) * 100, 80 + (j / 4) * 100, "��");
		break;

	case 'd':
		for (i = 0; i<4; i++)
		{
			for (x = 0; x<3; x++)
			{
				for (j = 1; j <= 3; j++)
				{
					if (num[i][j] == 0)
					{
						t = num[i][j - 1];
						num[i][j - 1] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (i = 0; i<4; i++)
		{
			for (j = 0; j<3; j++)
				if (num[i][j] == num[i][j + 1])
				{
					num[i][j] = num[i][j + 1] + num[i][j];
					num[i][j + 1] = 0;
					if (num[i][j] != 0)
						score += 12;
				}
		}
		for (i = 0; i<4; i++)
		{
			for (x = 0; x<3; x++)
			{
				for (j = 1; j <= 3; j++)
				{
					if (num[i][j] == 0)
					{
						t = num[i][j - 1];
						num[i][j - 1] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (i = 0; i<4; ++i)
		{
			for (j = 0; j<4; j++)
			{
				s[4 * i + j] = num[i][j];
			}
		}
		background2();
		for (i = 0; i<16; i++)
		{
			if (s[i] != 0)
			{
				setfont(50, 0, "�����п�");
				//sprintf(out3[i],"%d",s[i]);
				if (s[i] == 2)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 4)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 8)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 16)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 32)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 64)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 128)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 256)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 512)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 1024)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "Ԫ");
				if (s[i] == 2048)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
			}
		}
		for (i = 0; i<16; i++)
		{
			if (s[i] == 0)
				p[y++] = i;
		}
		x = rand() % y;
		j = p[x];
		s[j] = 2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80 + (j % 4) * 100, 80 + (j / 4) * 100, "��");
		break;

	case 'w':
		for (j = 0; j <= 3; j++)
		{
			for (x = 0; x<3; x++)
			{
				for (i = 0; i<3; i++)
				{
					if (num[i][j] == 0)
					{
						t = num[i + 1][j];
						num[i + 1][j] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (j = 0; j<4; j++)
		{
			for (i = 0; i<4; i++)
				if (num[i][j] == num[i + 1][j])
				{
					num[i][j] = num[i + 1][j] + num[i][j];
					num[i + 1][j] = 0;
					if (num[i][j] != 0)
						score += 12;
				}
		}
		for (j = 0; j<4; j++)
		{
			for (x = 0; x<3; x++)
			{
				for (i = 0; i<3; i++)
				{
					if (num[i][j] == 0)
					{
						t = num[i + 1][j];
						num[i + 1][j] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (i = 0; i<4; ++i)
		{
			for (j = 0; j<4; j++)
			{
				s[4 * i + j] = num[i][j];
			}
		}
		background2();
		for (i = 0; i<16; i++)
		{
			if (s[i] != 0)
			{
				setfont(50, 0, "�����п�");
				//sprintf(out3[i],"%d",s[i]);
				if (s[i] == 2)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 4)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 8)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 16)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 32)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 64)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 128)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 256)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 512)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 1024)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "Ԫ");
				if (s[i] == 2048)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
			}
		}
		for (i = 0; i<16; i++)
		{
			if (s[i] == 0)
				p[y++] = i;
		}
		x = rand() % y;
		j = p[x];
		s[j] = 2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80 + (j % 4) * 100, 80 + (j / 4) * 100, "��");
		break;

	case 's':
		for (j = 0; j<4; j++)
		{
			for (x = 0; x<3; x++)
			{
				for (i = 1; i <= 3; i++)
				{
					if (num[i][j] == 0)
					{
						t = num[i - 1][j];
						num[i - 1][j] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (j = 0; j<4; j++)
		{
			for (i = 0; i<4; i++)
				if (num[i][j] == num[i + 1][j])
				{
					num[i][j] = num[i + 1][j] + num[i][j];
					num[i + 1][j] = 0;
					if (num[i][j] != 0)
						score += 12;
				}
		}
		for (j = 0; j<4; j++)
		{
			for (x = 0; x<3; x++)
			{
				for (i = 1; i <= 3; i++)
				{
					if (num[i][j] == 0)
					{
						t = num[i - 1][j];
						num[i - 1][j] = num[i][j];
						num[i][j] = t;
					}
				}
			}
		}
		for (i = 0; i<4; ++i)
		{
			for (j = 0; j<4; j++)
			{
				s[4 * i + j] = num[i][j];
			}
		}
		background2();
		for (i = 0; i<16; i++)
		{
			if (s[i] != 0)
			{
				setfont(50, 0, "�����п�");
				//sprintf(out3[i],"%d",s[i]);
				if (s[i] == 2)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 4)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 8)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 16)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 32)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 64)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 128)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 256)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 512)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
				if (s[i] == 1024)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "Ԫ");
				if (s[i] == 2048)
					outtextxy(80 + (i % 4) * 100, 80 + (i / 4) * 100, "��");
			}
		}
		for (i = 0; i<16; i++)
		{
			if (s[i] == 0)
				p[y++] = i;
		}
		x = rand() % y;
		j = p[x];
		s[j] = 2;
		//sprintf(out3[j],"%d",s[j]);
		outtextxy(80 + (j % 4) * 100, 80 + (j / 4) * 100, "��");
		break;

	case 'q':
		q++;
		end();
		break;

	default:
		break;
	}


}

void end()
{
    cleardevice();
	loadimage(NULL, "C:\\Users\\meng\\Desktop\\2048\\2048\\2.jpg", 640,510);
	settextcolor(WHITE);
	setfont(100,0,"�����п�"); 
	char sco[100];
	sprintf(sco,"%d",score-10);
	outtextxy(150,150, "����");
	outtextxy(350,150,sco);
	Sleep(6000);
}//��������