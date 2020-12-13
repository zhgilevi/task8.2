#include <stdio.h>
#include <stdlib.h>

int srav=0;
int swap=0;

int partition (int* array, int start, int end)
   {
       int temp;

       int left=start, right=end;
       int pivot=(right+left)/2;
       while (left<right){
       while (left!=pivot && (srav++,array[left]<array[pivot])){
        left++;
       }
        while (right!=pivot && (srav++,array[right]>array[pivot])){
            right--;
        }
        if (pivot==right && left<right){
            temp=array[left];
            array[left]=array[pivot];
            array[pivot]=temp;
            pivot=left;
            swap++;
            right--;
        }
        else if (pivot == left && left<right){
            temp=array[right];
            array[right]=array[pivot];
            array[pivot]=temp;
            pivot=right;
            swap++;
            left++;
        }
       else if(left<right){
            temp=array[left];
            array[left]=array[right];
            array[right]=temp;
            swap++;
            left++;
            right--;


       }
       }


       return pivot;
   }

   void quicksort (int* array, int start, int end)
   {
       if ( start >= end )
       {
           return;
       }
       int pivot = partition (array, start, end);
       quicksort (array, start, pivot-1);
       quicksort (array, pivot+1, end);
   }




int main()
{
    int n;
    printf("vvedite razmer massiva\n");
    scanf("%d",&n);
    int* a;
    a=(int*)malloc(sizeof(int)*n);
    printf("vvedite massiv\n");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("otsortirovanniy massiv\n");
    quicksort(a,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n sravneniy-%d  obmenov-%d",srav,swap);
    return 0;
}
