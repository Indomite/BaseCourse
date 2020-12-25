void simpleselectsort(table *tab)
{
    int i,j,k;
    for(i = 1;i <= tab->length-1;i++){
        k=i;
        for(j=i+1;j<=tab->length;j++)
            if(tab->r[j].key < tab->r[k].key)
            k = j;
        if(k != i){
            tab->r[0] = tab->r[k];
            tab->r[k] = tab->r[i];
            tab->r[i] = tab->[0];
        }
    }
}
