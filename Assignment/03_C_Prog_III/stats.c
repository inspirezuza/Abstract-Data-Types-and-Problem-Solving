#include <stdio.h>
#include <stdlib.h>
void findStats(int n, int nums[],double *avg, int *maxi, int *mini){
    *maxi = -999999;
    *mini = 999999;
    double sum = 0;
    for(int i=0;i<n;i++){
        if(nums[i] > *maxi){
            *maxi = nums[i];
        }
        if(nums[i] < *mini){
            *mini = nums[i];
        }
        sum+=nums[i];
    }
    *avg = sum/(double)n; 
}
int main() {
    int n, i, maxi, mini;
    double avg;
    int *nums;

    scanf("%d", &n);
    nums = (int *)malloc(sizeof (int) *n);
    for (i=0; i<n; i++)
        scanf("%d", nums+i);
    findStats(n,nums,&avg,&maxi,&mini);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}