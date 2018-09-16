#include<iostream>
using namespace std;
#define MAX 1000000
#define ll long long
//Median of Stream of Running llegers

 ll maxHeap[MAX];
 ll minHeap[MAX];
 ll maxHeapSize=0;
 ll minHeapSize=0;
double median=0;


void Min_Heapify( ll position){
     ll left;
     ll right;
     ll temp;
    left =2*position +1;
    right =2*position +2;
     ll min=position;
    
    if(minHeap[left] < minHeap[min] && left < minHeapSize)
    {
        min=left;
    }
    if(minHeap[right] < minHeap[min] && right < minHeapSize)
    {
        min=right;
    }
    if(min!=position){
        temp=minHeap[position];
        minHeap[position]=minHeap[min];
        minHeap[min]=temp;
        
        Min_Heapify(min);
    }
    
/*    for(ll i=0;i<minHeapSize;i++){
        cout << "Min heap": ;
        cout << a[i] <<"\t" << endl;
    }*/
    
}

void Max_Heapify(ll position){
     ll left;
     ll temp;
     ll right;
    left =2*position +1;
    right =2*position +2;
     ll max=position;
    
    if(maxHeap[left] > maxHeap[max] && left < maxHeapSize)
    {
        max=left;
    }
    if(maxHeap[right] > maxHeap[max] && right < maxHeapSize){
        max=right;
    }
    if(max!=position)
    {
        temp=maxHeap[position];
        maxHeap[position]=maxHeap[max];
        maxHeap[max]=temp;
        
        Max_Heapify(max);
    }
    
/*    for(ll i=0;i<maxHeapSize;i++){
        cout << "Max heap": ;
        cout << a[i] <<"\t" << endl;
    }*/
}

void Insert_Min( ll y){
    minHeap[minHeapSize++]=y;

    ll cur = minHeapSize-1;
    
    while(cur !=0 && minHeap[cur]< minHeap[(cur-1)/2])
    {
        ll temp = minHeap[cur];
        minHeap[cur]= minHeap[(cur-1)/2];
        minHeap[(cur-1)/2] = temp;
    
        cur = (cur-1)/2;
    }
//    Min_Heapify(0);
}

 ll Extract_Min(){
     ll x=minHeap[0];
    minHeap[0]=minHeap[minHeapSize-1];
    minHeapSize--;
    Min_Heapify(0);
    return x;
}

void Insert_Max( ll y){
    maxHeap[maxHeapSize++]=y;
    
     ll cur = maxHeapSize-1;
    
    while( cur!=0 && maxHeap[cur]> maxHeap[(cur-1)/2])
    {
         ll temp = maxHeap[cur];
        maxHeap[cur]=maxHeap[(cur-1)/2];
        maxHeap[(cur-1)/2] = temp;
    
        cur = (cur-1)/2;
    
    }
    
//    for(ll i=0;i<maxHeapSize;i++);
//    printf("%d\t",maxHeap[i]);
//    Max_Heapify(0);
}

 ll Extract_Max(){
     ll x=maxHeap[0];
    maxHeap[0]=maxHeap[maxHeapSize-1];
    maxHeapSize--;
    Max_Heapify(0);
    return x;
}

double insert(ll x){
     if(maxHeapSize==0 && minHeapSize==0){
         maxHeap[maxHeapSize++]=x;
         median=x;
     }
         
     else if(maxHeapSize > minHeapSize){
         if(x < maxHeap[0]){
              ll y=Extract_Max();
             Insert_Min(y);
             Insert_Max(x);
         }
         else
         {
             //minHeap[minHeapSize++]=x;
             Insert_Min(x);
         }
         median=(double)(maxHeap[0]+minHeap[0])/2;
     }
     
     
     else if(maxHeapSize < minHeapSize)
     {
         if(x > minHeap[0]){
              ll y=Extract_Min();
             Insert_Max(y);
             Insert_Min(x);
         }
         else
         {
             //maxHeap[maxHeapSize++]=x;
             Insert_Max(x);
         }
         median=(double)(maxHeap[0]+minHeap[0])/2;
     }
     else
     {
     // when maxHeapSize == minHeapSize;
      if(x < maxHeap[0]){
          Insert_Max(x);
          median=maxHeap[0];
      } 
      else{
          Insert_Min(x);
          median=minHeap[0];
      }    
     }
     return median;
}

int main()
    {
    ll test,num;
    scanf("%lld",&test);
    while(test--)
        {
        scanf("%lld",&num);
        double x=insert(num);
        //float x=findMedian();
        printf("%.1lf\n",x);
        
    }
   return 0; 
}
