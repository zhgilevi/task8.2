#include <stdio.h>
#include <stdlib.h>

int srav=0;
int swap=0;





 int change(int *a,int l,int r){
int i=l,j=r;



int p=(l+(r))/2;
int op=a[p];
printf("\n l=%d p=%d  r=%d \n ",l,p,r);

while (i<j){
    while ((srav++,a[i]<op)){
    i++;    }
    while ( (srav++,a[j]>op)){
        j--;
        }
    if (i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        if (j==p){
            p=i;
            printf("i");
        }
        else if (i==p){
            p=j;
            printf("j");
        }
        i++;
        j--;
        swap++;
    }
}

return p;
/*
if (a[i]==op){
    //printf("\n znach=%d  index=%d \n",op,i);
    return i;
}
//printf("\n znach=%d  index=%d \n",(i+1),p);
return i+1;
*/
}



void quick_sort(int *a,int l,int r){

if (l==r)
    return;

if (abs(r-l)==1){
    if (a[r]<a[l]){
        int temp=a[r];
        a[r]=a[l];
        a[l]=temp;
        swap++;
    }
    srav++;
    return;
}


if (l<r){
    int p=change(a,l,r);
    printf("\n index=%d znachenie=%d \n",p,a[p]);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,r);
    //printf("%d\n",p);
}

}



int main()
{
    int *a,n;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1);
    for (int i=0;i<n-2;i++){
        printf("%d ",a[i]);
    }
    //printf("%d",a[9]);
    printf("\n swap=%d  srav=%d",swap,srav);
    return 0;
}
