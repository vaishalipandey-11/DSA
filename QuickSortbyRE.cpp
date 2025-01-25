   #include <iostream>
   #include<vector>
   using namespace std;
   void QS(vector<int>&arr , int start , int end ){
    if(start>= end) return ;
    int i = start -1;
    int j = start ;
    int pivot = end;
    while(j<pivot ){
         if(arr[j] <arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
         }
         j++;

    }
    i++;
    swap(arr[i], arr[pivot]);
    QS(arr , start , i-1);
    QS(arr , i+1, end);
    

   }
    int main(){
        vector arr = {17,2,1,18,6,3,5,4};
        int start =  0;
        int end = arr.size();
        QS(arr , start , end);
        
        for(int i=1 ; i<=arr.size(); i++){
             cout<<arr[i] <<" ";
        }

    }