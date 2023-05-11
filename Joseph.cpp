#include <iostream>
#include <random>

using namespace std;
typedef struct Josephus
{
    short password=0;
    short ID=0;
    Josephus *next;
}Josephus;

void ScanfMN(short &UpperlimitM,short &NumberOfPersonN)
{
    cout << "what's upper limit of the number reporting?\n";
    do
    {
        cout << "please enter in a number between 1 and 30\n";
        cin >> UpperlimitM;
    } while (!(UpperlimitM>0&&UpperlimitM<=30));
    cout << endl;
    cout << "what's number of the persons?\n";
    do
    {
        cout << "please enter in a number between 1 and 30\n";
        cin >> NumberOfPersonN;
    } while (!(NumberOfPersonN>0&&NumberOfPersonN<=30));
}

Josephus* IniJosephus(short UpperlimitM,short NumberOfPersonN,Josephus *&pre)
{
    std::mt19937 eng(std::random_device{}());
    uniform_int_distribution<int> password(1,UpperlimitM);
    Josephus *p= new Josephus;
    Josephus *in=p;
    for(int i=0;i<NumberOfPersonN;i++)
    {
        p->ID=i+1;
        p->password=password(eng); 
        if (i==NumberOfPersonN-1||NumberOfPersonN==1)
        {
            pre=p;
            p->next=in;
        }
        else
        {
            p->next=new Josephus;
            p=p->next;
        }    
    }
    return in;
}

void JosephusFunc(Josephus *core,short m,short memberNum,Josephus *&pre)
{
    Josephus *ps=core; 
    Josephus *temp;  
    while (memberNum>1)
    {
        for(int i=0;i<m-1;i++)
        {
            pre=pre->next;
            ps=ps->next;
        }
        m=ps->password;
        cout << ps->ID << " out!" <<endl;
        pre->next=pre->next->next;
        delete ps;
        ps=pre->next;
        memberNum--;
    }
    cout << ps->ID << " out!" <<endl;

}
static Josephus *pre;

void PrintJosephus(Josephus *start,short n)
{
    Josephus *p=start;
    cout << "here I will list the passwords of these" << n << " persons" << endl;
    cout << p->password << "···>";
    p=p->next;
    for (; p != start; p=p->next)
    {
        cout << p->password << "···>";
    }
    cout << endl ;
}

int main()
{
    short UpperlimitM=0;
    short NumberOfPersonN=0;
    ScanfMN(UpperlimitM,NumberOfPersonN);
    Josephus *core=IniJosephus(UpperlimitM,NumberOfPersonN,pre);
    PrintJosephus(core,NumberOfPersonN);
    JosephusFunc(core,UpperlimitM,NumberOfPersonN,pre);
    return 0;
}