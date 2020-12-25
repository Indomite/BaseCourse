void shellinsertsort(table *tab)
{
        int i,j,d;
        d = tab->length/2;
        while(d>=1){
            for(i = d+1;i <= tab->length;i++){
                tab->r[0] = tab->r[i];
                j = i-d;
                while(j > 0 && tab->r[0].key < tab->r[j].key){
                    tab->r[j+d] = tab->r[j];
                    j=j-d;
                }
                tab->r[j+d] = tab->r[0];
            }
            d=d/2;
        }
}
