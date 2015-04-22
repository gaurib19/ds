#include<stdio.h>
#include<stdlib.h>

int mem[1000];
int Reg[4];
int op1,op2;

main()	
{
	char fname[30];
	printf("file name:");
	gets(fname);
	load(fname);
}

void load(char fname[30])
{
	FILE *fp;
	int i=0,pc=0;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
	printf("unable to open file");
	exit(0);
	}
	else 
	{
	while(!feof(fp))
	{
	fscanf(fp,"%d",&mem[i]);
printf("\n %d %d ",i,mem[i]);	
i++;
	pc++;
	}
	fclose(fp);
	execute();
}
}
void execute()	
{	
	int instn,opcode,R=0,addr,i=0,pc=0;
	while(1)
	{
	instn=mem[pc];
	opcode=instn/10000;
	instn=instn%10000;
	R=instn/1000;
	addr=instn%1000;
	
switch(opcode)
{
	case 0:exit(0);
	case 1:Reg[R-1]=Reg[R-1]+mem[addr];
		break;
	case 2:Reg[R-1]=Reg[R-1]-mem[addr];
		break;
	case 3:Reg[R-1]=Reg[R-1]*mem[addr];
		break;
	case 4:Reg[R-1]=mem[addr];
		break;
	case 5:mem[addr]=Reg[R-1];
		break;
	case 6:op1=Reg[R-1];
		op2=mem[addr];
		break;
	case 7:switch(R)
		{
			case 1:if(op1<op2) pc=addr-1;
				break;
			case 2:if(op1<=op2) pc=addr-1;
				break;
			case 3:if(op1==op2) pc=addr-1;
				break;
			case 4:if(op1>op2) pc=addr-1;
				break;
			case 5:if(op1>=op2) pc=addr-1;
				break;
			case 6:pc=addr-1;
				break;
			default:printf("invalid relational operator");
			exit(0);
		}
		break;
	case 8:if(mem[addr]==0)
		{
		printf("Runtime error:divide by 0");
		}
		else
		Reg[R-1]=Reg[R-1]/mem[addr];
		break;
	case 9:printf("Input:");
		scanf("%d",&mem[addr]);
		break;
	case 10:printf("Output:");
		printf("%d",mem[addr]);
		break;
	default:printf("Error:Invalid opcode");
		exit(0);
}
pc++;
}
}
