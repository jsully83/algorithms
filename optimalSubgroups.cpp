#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 5000;

int presum[N];

int dp[N][N];

//getMaxMinSum funtion will return how much max sum we can get

int getMaxMinSum(int *A, int n, int m)

{
    printf("getMaxMinSum N = %d, M = %d\n", n, m);
    //Base case

    // if group size is greater than array size return INT_MIN

    if(n<m){
        printf("n<m return int_min N = %d, M = %d\n", n, m);

        return INT_MIN;

    }

    // Look into the dp table

    if(dp[n][m] != 0){
        printf("dp[%d][%d] = %d\n", n, m, dp[n][m]);

        return dp[n][m];

    }

    //Recursive Case

    int maxMinSum = INT_MIN;

    for(int i=n-1; i>=m-1; i--) {

        // maximize the minimum

        int ans = min(getMaxMinSum(A,i,m-1), presum[n]-presum[i]);
        printf("ans = min %d, %d = %d - %d\n", dp[i][1], presum[n]-presum[i], presum[n], presum[i]);

        if(maxMinSum < ans) {
            printf("if minmaxsum  %d < %d\n",maxMinSum, ans);
          // if ans is greater than the maxMinSum obtained so far then perform the update

            maxMinSum = ans;
            printf("maxminsum = ans = %d\n", maxMinSum);

        }

    }
    printf("return %d\n", maxMinSum);
    return maxMinSum;

}

int *max_min_grouping(int *A,int n,int m)

{

    int ans = getMaxMinSum(A,n,m);

    cout<<"The maximum minimum sum of the m groups is: "<<ans<<"\n";

    int curSum = 0;

    int curGrpSize=0;

    int j=1;

    int *G = new int[n+1];

    for(int i=1;i<=n;i++)

    {

        curSum += A[i];  

        ++curGrpSize;

        if(curSum >= ans) {

          // move to the next group

            G[j] = curGrpSize;

            curSum = 0;

            curGrpSize = 0;

            j++;

        }

    }

    return G;

}


int main()

{

    int n;// array-size

    cout<<"Enter the size of the array:\n";

    cin>>n;

    int m; //group size

    cout<<"Enter the number of groups the array needs to be partitioned into:\n";

    cin>>m;

    

    // 1-based indexing

    int *A = new int[n+1];

    cout<<"Enter the array elements:"<<endl;

    for(int i=1;i<=n;i++){

        cin>>A[i];

    }

    // initialize the presum array with 0

    memset(presum, 0, sizeof(presum));

    // initialize the dp table with 0

    memset(dp, 0, sizeof(dp));

    

    // storing the presum of the given array

    for(int i=1;i<=n;i++) {

        presum[i] += (presum[i-1] + A[i]);

    }

    // now we will dp where dp[i][j] means maximising the min of first i numbers

    // into j group

    for(int i=1;i<=n;i++){

        dp[i][1] = presum[i];  

    }

    int *G = max_min_grouping(A, n, m);

    cout<<"The elements of the array G representing the sizes of the m-groups are: ";    

    for(int i=1;i<=m;i++)

        cout<<G[i]<<" ";

    cout<<endl;

    

    return 0;

}







