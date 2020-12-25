void quicsort(table *tab,int left,int right)
{
    int i,j;
    if(left < right){
        i=left;
        j=right;
        tab->r[0]=tab->r[i];
        do{
            while(tab->r[j].key>tab->r[0].key && i<j)
                j--;
            if(i<j){
                tab->r[i].key = tab->r[j].key;
                i++;
            }
            while(tab->r[j].key<tab->r[0].key && i<j)
                i++;
            if(i<j){
                tab->r[j].key = tab->r[i].key;
                j--;
            }
        }while(i != j);
        tab->r[i] = tab->r[0];
        quicsort(tab,left,i-1);
        quicsort(tab,i+1;right);
    }
}
