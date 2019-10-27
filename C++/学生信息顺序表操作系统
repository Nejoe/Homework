#include <iostream>
#include <iomanip>
#include <string.h>
#define MAXSIZE 1000
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int Status;
using namespace std;

typedef struct{//定义Student信息
	char no[8];
	char name[20];
	int score;
}Student;

typedef Student ElemType;//定义ElemType为Student类型

typedef struct{//定义顺序存储类型SqList
	ElemType *elem;
	int length;
	int listSize;
}SqList;

Status InitList(SqList &L){//构造一个空的顺序表L
	L.elem = new ElemType[MAXSIZE];
	if(!L.elem)
    {
        return OVERFLOW;
    }
	L.length = 0;
	return OK;
}

Status InputStudent(SqList &L){//1.根据学生个数，逐个输入学生信息来初始化线性表L
    int a;
    cout<<"输入指定学生个数：";
    cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].score;
		L.length++;
	}
    return OK;

}

Status PrintList(SqList &L){//4.逐个显示学生表中所有学生的相关信息
    for(int i = 0; i < L.length; i++)
    {
        cout<<L.elem[i].no<<" "<<L.elem[i].name<<" "<<L.elem[i].score<<endl;
    }
    return OK;
}

Status ListDelete(SqList &L,int i){//删除元素i
    int j;
	if((i < 1) || (i > L.length))
    {
        cout<<"输入位置有误"<<endl;
        return ERROR;
    }
	for(j = i;j < L.length; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
    --L.length;
    return OK;
}

Status DelRepeat(SqList &L){//11.删除重复学号学生
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

Student FindName(SqList &L){//5.根据姓名进行查找，返回学生学号和成绩
    Student N;
    char str[20];
    cout<<"请输入学生姓名：";
    cin>>str;
    for(int i = 0; i < L.length; i++){
	    if(!strcmp(L.elem[i].name,str)){
	    	return L.elem[i];
		}
    }
    return N;
}

Student FindLocal(SqList &L){//7.根据指定位置返回学生信息
    int i;
    cout<<"请输入指定位置：";
    cin>>i;
    while(i < 1 || i > L.length){
        cout<<"位置有误，请重试：";
        cin>>i;
    }
    return L.elem[i-1];
}

Status InsertList(SqList &L){//8.给定一个学生信息，插入到表中指定位置
    int i, j, score;
    char no[8];
    char name[20];
    ElemType A;
    cout<<"请输入指定位置：";
    cin>>i;
    while(i < 1 || i > L.length+1){
        cout<<"位置有误，请重试：";
        cin>>i;
    }
    cout<<"请输入学生学号、姓名和成绩：";
    cin>>no>>name>>score;
    for(j = L.length-1; j >= i-1; j--){
        L.elem[j+1] = L.elem[j];
    }
    ++L.length;
    strcpy(A.no,no);
    strcpy(A.name,name);
    A.score = score;
    L.elem[i-1] = A;
    return OK;
}

Status UpDateData(SqList &L){//9.修改学生信息，输入学号，以及要修改的信息
    int i, isExist = 1;
    ElemType A;
    cout<<"请输入学号：";
    cin>>A.no;
    while(isExist){
        for(i = 0; i < L.length; i++){
            if(!strcmp(L.elem[i].no,A.no)){
                isExist = 0;
                break;
            }
        }
        if(isExist){
            cout<<"学号不存在，请重新输入：";
            cin>>A.no;
        }
    }
    cout<<"请输入学生要修改的学号、姓名和成绩：";
    cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].score;
    return OK;
}

void ShowMenu(){//展示菜单
    cout<<"********************************************"<<endl
    <<"0.退出系统"<<endl
    <<"1.根据学生个数，逐个输入学生信息来初始化线性表L"<<endl
    <<"4.逐个显示学生表中所有学生的相关信息"<<endl
    <<"5.根据姓名进行查找，返回学生学号和成绩"<<endl
    <<"7.根据指定位置返回学生信息"<<endl
    <<"8.给定一个学生信息，插入到表中指定位置"<<endl
    <<"9.修改学生信息，输入学号，以及要修改的信息"<<endl
    <<"11.删除重复学号学生"<<endl
    <<"选择功能：";
}

void ChooseMenu(){//选择菜单
    int n = 1;
    SqList L;
    InitList(L);
    while(n){
        cin>>n;
        switch(n){
            case 0:{
                cout<<"退出系统"<<endl;
                break;
            }
            case 1:{
                InputStudent(L);
                ShowMenu();
                continue;
            }
            case 4:{
                PrintList(L);
                ShowMenu();
                continue;
            }
            case 5:{
                Student a = FindName(L);
                cout<<"学号："<<a.no<<" "<<"姓名："<<a.name<<" "<<"成绩："<<a.score<<endl;
                ShowMenu();
                continue;
            }
            case 7:{
                Student b = FindLocal(L);
                cout<<"学号："<<b.no<<" "<<"姓名："<<b.name<<" "<<"成绩："<<b.score<<endl;
                ShowMenu();
                continue;
            }
            case 8:{
                InsertList(L);
                cout<<"插入完成"<<endl;
                PrintList(L);
                ShowMenu();
                continue;
            }
            case 9:{
                UpDateData(L);
                cout<<"更新完成"<<endl;
                PrintList(L);
                ShowMenu();
                continue;
            }
            case 11:{
                DelRepeat(L);
                cout<<"删除完成"<<endl;
                PrintList(L);
                ShowMenu();
                continue;
            }
        }
    }
}

int main(){
    ShowMenu();
    ChooseMenu();
    //PrintList(L);
    return 0;
}
