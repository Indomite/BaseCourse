void binarysort(table *tab)
{
    int i,j,left,right,mid;
    for(i=2;i<tab->length;i++){
        tab->r[0] = tab->r[i];
        left = 1;
        right = i-1
        while(left <= right){
            mid = (low+right)/2;
            if(tab->r[i].key < tab->r[mid].key)
                right = mid-1;
            else
                left=mid+1;
        }
        for(j=i-1;j>=left;j--)
            tab->r[j+1] = tab->r[j];
        tab->r[left]=tab->r[0];
    }
}
