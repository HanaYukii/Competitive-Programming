#include<bits/stdc++.h>
using namespace std;
int n,prv[3],pl[3];
struct p3
{
    string id,name;
    int score[3];
    int sum;
    int rk;
    int idx;
}cont[105];
bool cmp(p3 x,p3 y)
{
    if(x.sum!=y.sum)
    {
        return x.sum>y.sum;
    }
    else if(x.score[prv[0]]!=y.score[prv[0]])
    {
        return x.score[prv[0]]>y.score[prv[0]];
    }
    else if(x.score[prv[1]]!=y.score[prv[1]])
    {
        return x.score[prv[1]]>y.score[prv[1]];
    }
    else
    {
        return x.score[prv[2]]>y.score[prv[2]];
    }
}
bool cmp2(p3 x,p3 y)
{
    return x.idx<y.idx;
}


int main()
{
    cin>>n;
    cin>>pl[0]>>pl[1]>>pl[2];
    cin>>prv[0]>>prv[1]>>prv[2];
    for(int i=0;i<n;i++)
    {
        cin>>cont[i].id>>cont[i].name>>cont[i].score[0]>>cont[i].score[1]>>cont[i].score[2];
        cont[i].idx=i;
        cont[i].sum=cont[i].score[0]*pl[0]+cont[i].score[1]*pl[1]+cont[i].score[2]*pl[2];
    }
    puts("ID NAME SCORE1 SCORE2 SCORE3 SUM RANK");
    sort(cont,cont+n,cmp);
    for(int i=0;i<n;i++)
    {
        cont[i].rk=i+1;
    }
    sort(cont,cont+n,cmp2);
    for(int i=0;i<n;i++)
    {

        cout<<cont[i].id<<' '<<cont[i].name<<' '<<cont[i].score[0]<<' '<<cont[i].score[1];
        cout<<' '<<cont[i].score[2]<<' '<<cont[i].sum<<' '<<cont[i].rk<<endl;
    }
}
