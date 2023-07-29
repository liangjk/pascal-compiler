#include"code.h"
#include<cstdlib>
#include<cstdio>
#include<vector>

int base(int l,int*s,int b)
{
if(l==0)return b;
return base(l-1,s,s[b]);
}

void interpret() 
{
    int p, b, t;
    instruction i;  //instruction （指令）的类型定义（包括三个域f,l,a），请自行加入到头文件中，供其他文件共享
    int*s=new int[STACKSIZE];//stacksize：数据栈大小，需自己定义
	extern instruction code[CODESIZE];
	
	std::vector<int> tmp;

    printf("start pl0\n");
    t=3; b=1;  //t：数据栈顶指针；b：基地址；
    p=0;	// 指令指针
    s[1]=0; s[2]=0; s[3]=0;
    do {
        i=code[p++];//code为指令存放数组，其定义请自行加入到头文件中，供其他文件共享
		int pos;
        switch (i.f) 
        {
        case LIT:
			if(i.l)
				{
				*((double*)(s+t+1))=i.d;
				t=t+2;
				}
			else
				{
				t=t+1;
				s[t]=i.a;
				}
            break;
        case OPR: 
            switch(i.a) 
            {
                case 0:
                    t=b-1;
                    p=s[t+3];
                    b=s[t+2];
                    break;
                case 1: 
					if(i.l)
						*((double*)(s+t-1))=-*((double*)(s+t-1));
					else
						s[t]=-s[t];
                    break;
                case 2: 
					if(i.l)
						{
						t=t-2;
						*((double*)(s+t-1))+=*((double*)(s+t+1));
						}
					else
						{
						t=t-1;
						s[t]=s[t] + s[t+1];
						}
                    break;
                case 3:
					if(i.l)
						{
						t=t-2;
						*((double*)(s+t-1))-=*((double*)(s+t+1));
						}
					else
						{
						t=t-1;
						s[t]=s[t] - s[t+1];
						}
                    break;
                case 4: 
					if(i.l)
						{
						t=t-2;
						*((double*)(s+t-1))*=*((double*)(s+t+1));
						}
					else
						{
						t=t-1;
						s[t]=s[t] * s[t+1];
						}
                    break;
                case 5:
					if(i.l)
						{
						t=t-2;
						*((double*)(s+t-1))/=*((double*)(s+t+1));
						}
					else
						{
						t=t-1;
						s[t]=s[t] / s[t+1];
						}
                    break;
                case 6: 
                    s[t]=(s[t] % 2 == 1);
                    break;
                case 8: 
					if(i.l)
						{
						s[t-3]=(*((double*)(s+t-3))==*((double*)(s+t-1)));
						t-=3;
						}
					else
						{
						t=t-1;
						s[t]=(s[t] == s[t+1]);
						}
                    break;
                case 9:
					if(i.l)
						{
						s[t-3]=(*((double*)(s+t-3))!=*((double*)(s+t-1)));
						t-=3;
						}
					else
						{
						t=t-1;
						s[t]=(s[t] != s[t+1]);
						}
                    break;
                case 10:
					if(i.l)
						{
						s[t-3]=(*((double*)(s+t-3))<*((double*)(s+t-1)));
						t-=3;
						}
					else
						{
						t=t-1;
						s[t]=(s[t]<s[t+1]);
						}
                    break;
                case 11: 
					if(i.l)
						{
						s[t-3]=(*((double*)(s+t-3))>=*((double*)(s+t-1)));
						t-=3;
						}
					else
						{
						t=t-1;
						s[t]=(s[t]>=s[t+1]);
						}
                    break;
                case 12: 
					if(i.l)
						{
						s[t-3]=(*((double*)(s+t-3))>*((double*)(s+t-1)));
						t-=3;
						}
					else
						{
						t=t-1;
						s[t]=(s[t]>s[t+1]);
						}
                    break;
                case 13:
					if(i.l)
						{
						s[t-3]=(*((double*)(s+t-3))<=*((double*)(s+t-1)));
						t-=3;
						}
					else
						{
						t=t-1;
						s[t]=(s[t]<=s[t+1]);
						}
                    break;
                case 14:
					if(i.l==0)
						{
						printf("%d", s[t]);
						t=t-1;
						}
					if(i.l==1)
						{
						printf("%f",*((double*)(s+t-1)));
						t=t-2;
						}
					if(i.l==2)
						{
						printf("%c", s[t]);
						t=t-1;
						}
					if(i.l==3)
						{
						printf("%s", s[t]?"True":"False");
						t=t-1;
						}
                    break;
                case 15: 
                    printf("\n");
                    break;
                case 16:
					if(i.l)
						{
						scanf("%lf", (double*)(s+t+1));
						t=t+2;
						}
					else
						{
						t=t+1;
						scanf("%d", &s[t]);
						}
                    break;
				case 17:
					if(i.l)
						{
						t=t-1;
						s[t]=s[t]||s[t+1];
						}
					else
						{
						t=t-1;
						s[t]=s[t]|s[t+1];
						}
					break;
				case 18:
					if(i.l)
						{
						t=t-1;
						s[t]=(s[t]!=0)^(s[t+1]!=0);
						}
					else
						{
						t=t-1;
						s[t]=s[t]^s[t+1];
						}
					break;
				case 19:
					t=t-1;
					s[t]=s[t]%s[t+1];
					break;
				case 20:
					if(i.l)
						{
						t=t-1;
						s[t]=s[t]&&s[t+1];
						}
					else
						{
						t=t-1;
						s[t]=s[t]&s[t+1];
						}
					break;		
				case 21:
					if(i.l)
						s[t]=!s[t];
					else
						s[t]=~s[t];
					break;
				case 22:
					s[t]=(s[t-1]!=s[t]);
					break;
				case 23:
					t=t-1;
					if(i.l)
						t=t-1;
					break;
				default:
					printf("Undefined OPR code\n");
            }
		    break;
        case LOD:
			if(i.a>=0)
				{
				t=t+1;
				s[t]=s[base(i.l, s, b)+i.a+3];
				}
			else
				s[t]=s[base(i.l, s, b)+s[t]+3];
            break;
		case LODD:
			if(i.a>=0)
				{
				t=t+1;
				pos=base(i.l, s, b)+i.a+3;
				s[t]=s[pos];
				t=t+1;
				s[t]=s[pos+1];
				}
			else
				{
				pos=base(i.l,s,b)+s[t]+3;
				s[t]=s[pos];
				t=t+1;
				s[t]=s[pos+1];
				}
			break;
        case STO: 
			if(i.a>=0)
				{
				s[base(i.l, s, b)+i.a+3]=s[t];
				t=t-1;
				}
			else
				{
				s[base(i.l, s, b)+s[t-1]+3]=s[t];
				t=t-2;
				}
            break;
		case STOD:
			if(i.a>=0)
				{
				pos=base(i.l, s, b)+i.a+3;
				s[pos+1]=s[t];
				t=t-1;
				s[pos]=s[t];
				t=t-1;
				}
			else
				{
				pos=base(i.l,s,b)+s[t-2]+3;
				s[pos]=s[t-1];
				s[pos+1]=s[t];
				t=t-3;
				}
			break;
        case CAL:
			pos=int(i.d+0.1);
			for(int ii=0;ii<pos;++ii)
				s[t+3-ii]=s[t-ii];
			t-=pos;
            s[t+1]=base(i.l, s, b);
            s[t+2]=b;
            s[t+3]=p;
            b=t+1;
            p=i.a;
			t=t+3;
            break;
        case INI: 
            t=t+i.a;
            break;
        case JMP: 
            p=i.a;
            break;
        case JPC: 
            if (s[t]==0) 
            {
                p=i.a;
            }
			//printf("---nextp %d  ----\n",p);
            t=t-1;
            break;
		case SAVE:
			tmp.push_back(s[t]);
			t=t-1;
			if(i.l)
				{
				tmp.push_back(s[t]);
				t=t-1;
				}
			break;
		case LOAD:
			t=t+1;
			s[t]=tmp.back();
			tmp.pop_back();
			if(i.l)
				{
				t=t+1;
				s[t]=tmp.back();
				tmp.pop_back();
				}
			break;
		case LODP:
			pos=base(i.l, s, b)+i.a+3;
			t=t+1;
			s[t]=s[base(s[pos],s,b)+s[pos+1]+3];
			break;
		case LODPD:
			pos=base(i.l, s, b)+i.a+3;
			t=t+1;
			s[t]=s[base(s[pos],s,b)+s[pos+1]+3];
			t=t+1;
			s[t]=s[base(s[pos],s,b)+s[pos+1]+1+3];
			break;
		case STOP:
			pos=base(i.l, s, b)+i.a+3;
			s[pos]=s[t-1];
			if(s[t]<0)
				{
				s[pos+1]=s[t-2];
				t-=3;
				}
			else
				{
				s[pos+1]=s[t];
				t=t-2;
				}
			break;
		case STOFP:
			pos=base(i.l, s, b)+i.a+3;
			s[base(s[pos],s,b)+s[pos+1]+3]=s[t];
			t=t-1;
			break;
		case STOFPD:
			pos=base(i.l, s, b)+i.a+3;
			s[base(s[pos],s,b)+s[pos+1]+3]=s[t-1];
			s[base(s[pos],s,b)+s[pos+1]+1+3]=s[t];
			t=t-2;
			break;
		default:
			printf("Undefined instruction\n");
        }//end switch
    }while (p!=0);
	delete s;
}
