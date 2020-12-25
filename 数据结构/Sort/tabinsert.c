void tableinsertSort(table2 *tab)
{
    int i,p,q;
    tab->r[0].link = 1;
    tab->r[1].link = 0;
    for(i=2;i<=tab->length;i++){
        q=0;
        p=tab->r[0].link;
        while(p!=0 && tab->r[p].key>=tab->r[p].key){
            q=p;
            p=tab->r[p].link;
        }
        tab->r[i].link = p;
        tab->r[q].link = i;
    }
}
