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

// #include <stdio.h>

// int main() {
//     int s;
//     int a[100], n, ans1, ans2, ksmall, klarge;
    
//     // Reading input values
//     printf("Enter N: ");
//     scanf("%d", &n);
//     printf("Enter ksmall: ");
//     scanf("%d", &ksmall);
//     printf("Enter klarge: ");
//     scanf("%d", &klarge);
    
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
    
//     // Finding the k-th smallest element
//     for (int i = 0; i < n; i++) {
//         s = 1;
//         for (int j = 0; j < n; j++) {
//             if (a[i] > a[j]) {
//                 s++;
//             }
//         }
//         if (ksmall == s) {
//             ans1 = a[i];
//             break;
//         }
//     }
    
//     // Finding the k-th largest element
//     for (int i = 0; i < n; i++) {
//         s = 1;
//         for (int j = 0; j < n; j++) {
//             if (a[i] < a[j]) {
//                 s++;
//             }
//         }
//         if (klarge == s) {
//             ans2 = a[i];
//             break;
//         }
//     }
    
//     // Printing the results
//     printf("The %d-th smallest element is %d\n", ksmall, ans1);
//     printf("The %d-th largest element is %d\n", klarge, ans2);

//     return 0;
// }
