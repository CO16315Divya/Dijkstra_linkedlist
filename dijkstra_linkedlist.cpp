#include <climits>
#include <iostream>
#include<stdlib.h>
#define v 100
#define MAX 100
using namespace std;
int flag,count=0,mindist;
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

        start=create_node();
        temp->includeset=false;
        temp->finaldist=0;
        temp->pred=-1;
        temp->number=0;

        temp->next=NULL;
        start=temp;
        return start;


    }
    else
    {
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


    for(int i=source; i<vertices; i++)
    {

        start=insert_node(i,start,source);
    }
    return start;

}
struct node *extract_min(struct node *start,int vertices)
{
    struct node *ptr=NULL;
    int y,x;

    ptr=start;

    while(ptr->next!=NULL && ptr->includeset==true)
    {
       ptr=ptr->next;
    }
        if(ptr->includeset==false){
            ptr->includeset=true;
        }
   mindist=ptr->number;
   cout<<"\nextracted node="<<mindist<<endl;
    return start;

}
struct node* display(struct node* start)
{
    struct node* ptr;
    ptr = start;

    cout<<"\nvertex"<<"\t\t\t"<<"Minimum distance"<<endl;
    while(ptr != NULL)
    {

        cout<<ptr->number<<"\t\t\t"<<ptr->finaldist<<endl;
        ptr = ptr->next;
    }
    return start;
}

struct node *decreasekey(struct node *start,int w,int adj,int sno)
{
    struct node *ptr,*ptr2;


    ptr=start;
    ptr2=start;

    /*if(start==NULL)
    {
        display(start);
        return start;

    }*/

    while(ptr->number !=adj)
    {

        ptr=ptr->next;
    }


        while(ptr2->number!=sno)
        {

            ptr2=ptr2->next;
        }

        int oldkey=ptr->finaldist;
        int newkey=ptr2->finaldist + w;

         if(oldkey>newkey )
            {
                ptr->finaldist=ptr2->finaldist + w;

            }
            else cout<<"\nnew key is greater"<<endl;



    return start;
}
void dijkstra(int arrk[v][v],int source,int vertices)
{
    struct node *t,*ptr,*m;
    flag=vertices;

    start=initialize_single_source(start,source,vertices);


//    start=sortlist(start);
display(start);
    m=start;

    while(flag!=0)
    {

        flag--;
        //start=sortlist(start);
        start=extract_min(start,vertices);
      cout<<"\nextracted node index"<<mindist<<endl;


        count++;


        for(int j=0; j<vertices; j++)
        {
            if(arrk[mindist][j]!=0)
            {
                start=decreasekey(start,arrk[mindist][j],j,mindist);
            }

        }
        //m=m->next;



    }



    display(start);



}
int main()
{
    int i=0;



    int so, vp;

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
            if(i!=j)
            {
                cout<<"Enter the edge length between "<<i<<" and "<<j;
                cin>>arrk[i][j];
            }
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
cout<<"\nenter the source"<<endl;
cin>>so;
    dijkstra(arrk,so,vp);

    return 0;
}
/*struct node  *sortlist(struct node *start)
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
}*/
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
