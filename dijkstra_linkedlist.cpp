#include <climits>
#include <iostream>
#include<stdlib.h>
#define v 100
#define MAX 100
using namespace std;
int flag,count=0;
struct node
{

    bool includeset;
    int finaldist;
    int pred;
    int number;
    struct node *next;
};
struct node *start=NULL;
struct node *p=NULL;

struct node *start2=NULL;

struct node* create_node()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}

struct node *insert_node(int x,struct node *start,int source)
{
    struct node *ptr;

    struct node *temp =NULL;
    temp=create_node();
    if(x==source)
    {
        //cout<<"\nin if";
        start=create_node();
        temp->includeset=false;
        temp->finaldist=0;
        temp->pred=-1;
        temp->number=0;

        temp->next=NULL;
        start=temp;
        return start;
        // start-next=NULL;

    }
    else
    {
        //cout<<"\nin else";
        ptr=start;
        temp->includeset=false;
        temp->finaldist=INT_MAX;
        temp->pred=INT_MIN;
        temp->number=x;





        while( ptr->next != NULL )
        {

            ptr=ptr->next;
        }



        ptr->next=temp;

        temp->next=NULL;
        return start;
       // cout<<"\nelse end";

    }

}



struct node  *initialize_single_source(struct node *start,int source,int vertices)
{

    //cout<<"\nin inialisation";
    for(int i=source; i<vertices; i++)
    {

        start=insert_node(i,start,source);
    }
    return start;

}
struct node *extract_min(struct node *start,int vertices)
{
    int y,x,mindist;
    struct node *temp,*prev;


    //cout<<"\nin extract min";
    prev=start;
    temp=prev;

    while(prev!=NULL)
    {
      //  cout<<"\nin while of extract min";
        if(prev->includeset==false)
        {

            x=prev->finaldist;
            y=prev->number;
            break;
        }
        else prev=prev->next;
    }

    while(temp!=NULL)
    {
        if(temp->includeset==false && temp->finaldist<prev->finaldist)
        {

            prev=temp;
            temp=temp->next;

        }
        else temp=temp->next;
    }
    //cout<<"\nextract min end"<<"mindist= "<<prev->finaldist<<"y= :"<<prev->number;
    return prev;

}
struct node* display(struct node* start)
{
    struct node* ptr;
    ptr = start;
    //cout<<"\n\nin display\n\n";
    cout<<"\nvertex"<<"\t\t\t"<<"Minimum distance"<<endl;
    while(ptr != NULL)
    {

        cout<<ptr->number<<"\t\t\t"<<ptr->finaldist<<endl;
        ptr = ptr->next;
    }
    return start;
}
struct node  *sortlist(struct node *start)
{
    struct node *i,*j,*ptr;

    if(start==NULL||(start->next == NULL))
    {
        cout<<"list is empty or having only 1 element";
        return start;
    }
    else
    {

        for(i=start; i->next!=NULL; i=i->next)

        {

            for(j=i->next; j!=NULL; j=j->next)
            {
                if(i->finaldist>j->finaldist)
                {
                    ptr->finaldist=i->finaldist;
                    ptr->includeset=i->includeset;
                    ptr->pred=i->pred;
                    ptr->number=i->number;


                    i->finaldist=j->finaldist;
                    i->includeset=j->includeset;
                    i->pred=j->pred;
                    i->number=j->number;


                    j->finaldist=ptr->finaldist;
                    j->includeset=ptr->includeset;
                    j->pred=ptr->pred;
                    j->number=ptr->number;
                }

            }
        }

    }
    return start;
}
/*struct node *set_include(struct node *p)
{
    struct node *temp,*ptr;
    temp=start2;
    if(temp==NULL)
    {
        temp->includeset=true;
        temp->finaldist=p->finaldist;
        temp->number=p->number;
        temp->pred=p->pred;
        temp->next=NULL;
        start2=temp;
        return start2;
    }
    else
    {
        ptr=start2;
        temp->includeset=true;
        temp->finaldist=p->finaldist;
        temp->pred=p->pred;
        temp->number=p->number;





        while( ptr->next != NULL )
        {

            ptr=ptr->next;
        }



        ptr->next=temp;

        temp->next=NULL;
        return start2;
        cout<<"\nelse end in setinclude";

    }
}
*/
struct node *decreasekey(struct node *start,int mindist,int adj,int sno,struct node *p)
{
    struct node *ptr,*temp1,*ptr2,*temp2;
    temp1=create_node();
    temp2=create_node();

    ptr=start;
    ptr2=start;
    //cout<<"\nstart number "<<start->number;
    if(start==NULL)
    {
        display(start);
        return start;

    }
    //cout<<"\ndecreasekey"<<endl;
    //cout<<"\nj= "<<adj;
    while(ptr->number !=adj)
    {
        //cout<<"ptr number"<<ptr->number;
        ptr=ptr->next;
    }
    if(ptr->includeset==false)
    {
        //cout<<"\nin if\n";
        while(ptr2->number!=sno)
        {

            ptr2=ptr2->next;
        }
        temp1=ptr;
        temp2=ptr2;
        int oldkey=temp1->finaldist;
        int newkey=temp2->finaldist + mindist;
        //cout<<"\nnewkey"<<newkey;
        if(temp1->includeset==true)
            cout<<"\nalready included in set\n";
        else
        {
            if(oldkey>newkey )
            {
                temp1->finaldist=temp2->finaldist + mindist;
                temp1->pred=temp2->number;
                //cout<<"temp1 finaldist"<<temp1->finaldist;
            }
            else cout<<"\nnew key is greater"<<endl;

        }
    }
    //display(start);
//cout<<"\nstart number "<<start->number;
    return start;
}
void dijkstra(int arrk[v][v],int source,int vertices)
{
    struct node *t,*ptr,*m;
    flag=vertices;

    start=initialize_single_source(start,source,vertices);
    //cout<<"initialization end";
    //display(start);

    start=sortlist(start);
    //display(start);
    m=start;

    while(m!=NULL)
    {
        //cout<<"\nin while "<<count;
        flag--;
        //cout<<"flag="<<flag;



        start=sortlist(start);

        //cout<<"\nsorting end";

        p=create_node();
        p=extract_min(start,vertices);
        //cout<<"\nout of extract min";
        //cout<<"\np ka include set "<<p->includeset;
        p->includeset=true;
        //cout<<"p extract min "<<p->includeset<<endl;
        /*start2=create_node();
        start2=set_include(p);*/
        count++;

        //cout<<"flag="<<flag;
        //cout<<"p number"<<p->number;
        //cout<<"\nstart number "<<start->number;
        for(int j=0; j<vertices; j++)
        {
            if(arrk[p->number][j]!=0)
            {
                start=decreasekey(start,arrk[p->number][j],j,p->number,p);
            }

        }
        m=m->next;



    }


    //cout<<"\nout of while";
    display(start);



}
int main()
{
    int i=0;



    int vp;

    int arrk[MAX][MAX],e;
    cout<<"enter the number of vertices(undirected graph)"<<endl;
    cin>>vp;
    cout<<"enter the number of edges"<<endl;
    cin>>e;
    if(vp<=0 || e<=0)
    {
        cout<<"\ninvalid input";
        return 0;
    }
    for(int i=0; i<vp; i++)
    {
        for(int j=0; j<vp; j++)
        {
            if(i!=j){
            cout<<"Enter the edge length between "<<i<<" and "<<j;
            cin>>arrk[i][j];}
            else arrk[i][j]=0;

        }
    }


    cout<<"output matrix is ---->"<<endl;
    for(i=0; i<vp; i++)
    {
        for(int j=0; j<vp; j++)
        {

            cout<<"\t"<<arrk[i][j];

        }
        cout<<endl;
    }

    dijkstra(arrk,0,vp);

    return 0;
}
