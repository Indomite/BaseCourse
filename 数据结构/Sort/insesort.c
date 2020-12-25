void insertsort(table *tab)
{
    int i,j;
    for(i=2;i <= tab->length;i++){
        j = i-1;
        tab->r[0] = tab->r[i];
        while(tab->r[0].key < tab->r[j].key){
            tab->r[j+1] = tab->r[j];
            j=j-1;
        }
        tab->r[j+1] = tab->r[0];
    }
}
