// =====================================================================================
//
//       Filename:  adjmulist.h
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年11月17日 20时09分34秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  wangweihao (wangweihao), 578867817@qq.com
//        Company:  none
//
// =====================================================================================

#include<iostream>  
#define MAX_VERTAX_NUM 20  
using namespace std;  

typedef enum{unvisited,visited} Visitif;  
class EBox  
{  
    public:  
        EBox();  
        Visitif mark;  
        int ivex,jvex;  
        EBox *ilink,*jlink;  
};  

EBox::EBox()  
{  
    mark=unvisited;  
    ivex=jvex=0;  
    ilink=jlink=NULL;  
}  

class VexBox  
{  
    public:  
        VexBox();  
        char data;  
        EBox *firstedge;  
};  

VexBox::VexBox()  
{  
    firstedge=NULL;  
}  

class GraphInfo  
{  
    public:  
        GraphInfo();  
        VexBox adjmulist[MAX_VERTAX_NUM];  
        int vexnum,edgenum;  
};  

GraphInfo::GraphInfo()  
{  
    vexnum=edgenum=0;  
}  

class AMLGraph  
{  
    public:  
        void ShowAMLGraph();//接口函数  
    private:  
        void GetVexNode();//得到顶点信息  
        void GetEdgeNum();//得到边的数目  
        void CreatAMLGraph();//建图  
        void PrintAMLGraph();//打印节点相关信息  
        GraphInfo AML;  
};  

void AMLGraph::ShowAMLGraph()  
{  
    GetVexNode();//得到顶点信息  
    GetEdgeNum();//得到边的数目  
    CreatAMLGraph();//建图  
    PrintAMLGraph();//打印节点相关信息  
}  

void AMLGraph::GetVexNode()//得到顶点信息  
{  
    cout<<"GetVexNode Called !"<<endl<<endl;  
    char data;  
    while(cin>>data)  
    {  
        AML.adjmulist[AML.vexnum++].data=data;  
    }  
    cin.clear();  
}  

void AMLGraph::GetEdgeNum()//得到边的数目  
{  
    cout<<"GetEdgeNum Called !"<<endl<<endl;  
    cin>>AML.edgenum;  
}  

void AMLGraph::CreatAMLGraph()//建图  
{  
    cout<<"CreatAMLGraph Called !"<<endl<<endl;  
    int recycle=AML.edgenum,t[2];//设置循环次数并用t[2]存放两个节点  
    EBox * newedge,*p;  
    while(recycle--)//循环体  
    {  
        cin>>t[0]>>t[1];//输入边连接的两个顶点  
        newedge=new EBox;//开辟新节点  
        newedge->ivex=t[0];  
        newedge->jvex=t[1];  
        for(int i=0;i<2;i++)//分别对两个点进行处理  
        {  
            p=AML.adjmulist[t[i]].firstedge;  
            if(p==NULL)  
            {  
                AML.adjmulist[t[i]].firstedge=newedge;  
            }  
            else  
            {  
                while((p->ilink!=NULL&&p->ivex==t[i])||(p->jlink!=NULL&&p->jvex==t[i]))//注意这个循环条件，老出错就是错到了这里  
                {  
                    if(t[i]==p->ivex)  
                        p=p->ilink;  
                    else  
                        p=p->jlink;  
                }  
                if(p->ivex==t[i])  
                    p->ilink=newedge;  
                else  
                    p->jlink=newedge;  
            }  
        }  
    }  
}  

void AMLGraph::PrintAMLGraph()//打印节点相关信息  
{  
    cout<<"PrintAMLGraph Called !"<<endl<<endl;  
    EBox *p;  
    for(int i=0;i<AML.vexnum;i++)  
    {  
        cout<<AML.adjmulist[i].data<<" : "<<endl;  
        p=AML.adjmulist[i].firstedge;  
        while(p!=NULL)  
        {  
            if(p->ivex==i)  
            {  
                cout<<AML.adjmulist[p->ivex].data<<"--"<<AML.adjmulist[p->jvex].data<<endl;  
                p=p->ilink;  
            }  
            else  
            {  
                cout<<AML.adjmulist[p->jvex].data<<"--"<<AML.adjmulist[p->ivex].data<<endl;  
                p=p->jlink;  
            }  
        }  
        cout<<endl;  
    }  
}  
