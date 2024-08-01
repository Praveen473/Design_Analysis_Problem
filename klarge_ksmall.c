//kth largest kth smallest
#include<stdio.h>
int main()
{
    int s,l;
    int small,large,a[100],n,ans1,ans2,ksmall,klarge;
    printf("ENter N");
    scanf("%d",&n);
    printf("ENter kmall");
    scanf("%d",&ksmall);
    printf("ENter klarge");
    scanf("%d",&klarge);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        s=1;
        l=1;
        for(int j=0;j<n;j++)
        {
            ans1=a[i];
            ans2=a[i];
            if(a[i]>a[j])
            {
                //printf("small a[i] %d\n",a[i]);
                s=s+1;
                //printf("small s avlue%d\n",s);
                ans1=a[i];
            }
            if(a[i]<a[j])
            {
                //printf("large a[i] %d\n",a[i]);
                l=l+1;
                //printf("large l value %d\n",l);
                ans2=a[i];
            }
        }
        if(ksmall==s)
        {
            //printf("inside if s value %d\n",s);
            printf("answer1 %d\n",ans1);
        }
        //printf("outside klarge %d\n",klarge);
        if(klarge==l)
        {
            //printf("inside if l value %d\n",l);
            printf("answer2 %d\n",ans2);
        }
    }

}


