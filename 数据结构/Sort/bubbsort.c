void bubblesort(table *tab)
{
    int i,j,done;
    i = 1;done=1;
    while(i<=tab->length && done){
        done = 0£»
        for(j=1;j <= tab->length-i;i++)
        if(tab->r[j+1].key < tab->r[j].key){
            tab->r[0] = tab->r[j];
            tab->r[j] = tab->r[j+1];
            tab->r[j+1] = tab->r[0];
        }
        i++;
    }
}
