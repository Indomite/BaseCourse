
void permuate(int a[],int low,int high)
{
    if(low == high)
        for(int j=1;j < high;j++){
            printf("%d",a[j]);
            printf("\n");
        }
        return -1;
        for(i = low;i <= high;i++){
                int temp;
                temp = a[low];
                a[i] = a[low];
                a[low] = temp;
            permuate(a,low+1,high);
                a[low] = a[i];
                a[i] = temp;
        }
}
