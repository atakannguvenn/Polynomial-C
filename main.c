#include <stdio.h>
#include <stdlib.h>

struct node
{
        int coe;
        int exp;
        struct node *next;
};

typedef struct node report;
struct node *insert_s(struct node *start,int co,int ex);
void build_polynomial(report *tp);
void print_polyno(report *tp);
int multiply(report *tp, report *gp);
int poly_evaluate(int x, report *tp);


int main()
{
        report f_link,g_link;
        build_polynomial(&f_link);
        printf("f(x) is: ");
        print_polyno(&f_link);
        build_polynomial(&g_link);
        printf("g(x) is: ");
        print_polyno(&g_link);
        multiply(&f_link, &g_link);
}


void build_polynomial(report *tp)
{
        int i;
     	for(tp->next =NULL,i=0;i<3;i++,tp=tp->next)
        {
                tp->next = (report *)malloc(sizeof(report));
                tp->next->next=NULL;
                tp->coe=rand()%10;
                tp->exp=i;
        }
}


void print_polyno(report *tp)
{
        while(tp->next!=NULL )
        {
                if(tp->coe!=0)
                {
                        printf("%d x ^%d + ",tp->coe,tp->exp);
                }
                tp=tp->next;
        }
        printf("\b\b \n");
}



int multiply(report *tp, report *gp)
{
        int k, ans;
        struct node *start3;
        struct node *p2_beg = gp;
        start3=NULL;
        while(tp->next!=NULL)
        {
                gp=p2_beg;
                while(gp->next!=NULL)
                {
                        start3=insert_s(start3,tp->coe*gp->coe,tp->exp+gp->exp);
                        gp=gp->next;
                }
                tp=tp->next;
        }
        printf("h(x) is: ");
        print_polyno(start3);
        printf("Enter the value of x:");
        scanf(" %d", &k);
        ans = poly_evaluate(k, start3);
        printf("\n The output of h(%d) is %d.\n", k,ans);
}

struct node *insert_s(struct node *start,int co,int ex)
{
        struct node *ptr,*tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->coe=co;
        tmp->exp=ex;
        if(start==NULL || ex > start->exp)
        {
                tmp->next=start;
                start=tmp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL && ptr->next->exp >= ex)
                        ptr=ptr->next;
                tmp->next=ptr->next;
                ptr->next=tmp;
        }
        return start;
}

int poly_evaluate(int y, report *tp)
{
        int result=0,tempresult=1, exponent=0, multi=0;
        while(tp->next!=NULL )
        {
                if(tp->coe!=0)
                {
                        printf("%d*%d^%d + ",tp->coe, y, tp->exp);
                        exponent = tp->exp;
                        multi = tp->coe;
                        if (exponent == 0)
                        {
                                tempresult = 1;
                        }
                        while (exponent != 0)
                        {
                                tempresult = tempresult * y;
                                exponent = exponent - 1;
                        }
                        tempresult = tempresult * multi;
                        result = result + tempresult;
                        tempresult = 1;
                }
                tp=tp->next;
        }
        printf("\b\b \n");
        return result;
}
