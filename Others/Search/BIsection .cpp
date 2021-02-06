///Topic : Binary Search

int Bsearch(int k, int n){

    int lo=0;
    int hi=1000;
    int mn=INT_MAX;

    while(hi-lo>2){
        int mid=(lo+hi)/2;

        if(check(mid, k, n)){
            mn=mid;
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    while(check(mn-1,k,n))mn--;
    return mn;
}
