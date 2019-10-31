#include <iostream>
#include <iomanip>
#include <string.h>
#define MAXSIZE 1000
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int Status;
using namespace std;

typedef struct//定义Book信息
{
	char no[100];
	char name[100];
	float price;
}Book;

typedef Book ElemType;//定义ElemType为Book类型

typedef struct//定义顺序存储类型SqList
{
	ElemType *elem;
	int length;
}SqList;

Status InitList(SqList &L)//构造一个空的顺序表L
{
	L.elem = new ElemType[MAXSIZE];
	if(!L.elem)
    {
        return OVERFLOW;
    }
	L.length = 0;
	return OK;
}

Status PrintBookList(SqList &L)//输出书列表
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        cout<<L.elem[i].no<<" "<<L.elem[i].name<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<L.elem[i].price<<endl;
    }
    return OK;
}

Status ListDelete(SqList &L,int i)//删除元素i
{
    int j;
	if((i < 1) || (i > L.length))
    {
        cout<<"Sorry,the position to be deleted is invalid!"<<endl;
        return ERROR;
    }
	for(j = i;j <= L.length-1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
    --L.length;
    return OK;
}

Status DelRepeat(SqList &L)//删除书号重复图书
{
    for(int i = 0; i <= L.length; i++)
    {
        for(int j = L.length-1; j > i; j--)
        {
            if(!(strcmp(L.elem[i].no,L.elem[j].no)))
            {
                ListDelete(L,j);
            }
        }
    }
    return OK;
}

Status GetAvg(SqList &L)
{
    float sum = 0,avg = 0;
    for(int i = 0; i < L.length; i++)
    {
        sum = sum + L.elem[i].price;

    }
    avg = sum / L.length;
    for(int j = 0; j < L.length; j++)//特殊作用，修改价格
    {
        if(L.elem[j].price < avg)
        {
            L.elem[j].price *= 1.2;
        }
        else
        {
            L.elem[j].price *= 1.1;
        }
    }
    return OK;
}

Status CreationList(SqList &L,char *no,char *name,float &price)//储存书信息
{
    ElemType B;
    strcpy(B.no,no);
    strcpy(B.name,name);
    B.price = price;
    L.elem[L.length] = B;//L的elem数组存储书的信息
    L.length++;
    return OK;
}

int main()
{
    int n;
    char no[50],name[50];
    float price;
    SqList L;
    InitList(L);
    while(1)//循环输入，以“0 0 0”作为结束标志
    {
        cin>>no>>name>>price;
        if(no[0] == '0' && name[0] == '0' && price == 0)
            break;
        CreationList(L,no,name,price);
    }
    PrintBookList(L);
    return 0;
}
