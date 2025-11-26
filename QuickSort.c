// Program on Quick Sort
#include<stdio.h>

  void quick_sort(int arr[],int,int);
  int  n;
  int  main()
  {
  int arr[30],l,r,i;

  printf("\nInput number of elements:  ");
  scanf(" %d",&n);
  printf("\nInput  array values one by one: ");
  for(i=0;i<n;i++)
  scanf(" %d",&arr[i]);
  l=0;
  r=n-1;
  quick_sort(arr,l,r);
  printf("\nThe quick sorted array is:  ");
  for(i=0;i<n;i++)
  printf(" %d",arr[i]);
  printf("\n");
  }
  void quick_sort(int arr[],int low,int high)
  {
    int temp,j,i,pivot,k;
    if(low>=high)
        return;
    else
    {
      pivot=arr[low];
      i=low+1;
      j = high;
      while(i<=j)
      {
          while(arr[i]<pivot && i  <= high)
          {
          i ++;
          }
        while(arr[j]>pivot && j >  low)
        {
            j--;
        }
        if(i<j)
        {
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;

          i++;
          j--;
          }
    }

      arr[low]=arr[j];
      arr[j]=pivot;
      quick_sort(arr,low,j-1);
      quick_sort(arr,j+1,high);
    }
  }
