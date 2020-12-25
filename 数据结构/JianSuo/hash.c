#define Max 6
#define Hashmax 5
int data[Max];
struct list{
    int key;
    struct list * next;
};
typedef struct list node;
typedef node*link;
link hanshtab[Hashmax];
int counter = 1;

int hash_mod(int key)
{
    return key % Hashmax;
}

void inster_hash(int key)
{
    link p,new;
    int index;
    new = (link)malloc(sizeof(node));
    new->key = key;
    new->next = NULL;
    index = hash_mod(key);
    new->next = hashtab[index];
    hashtab[index] = new;
}

int hash_search(int key)
{
    link p;
    int index;
    counter = 0;
    index = hash_mod(key);
    p = hashtab[index];
    printf("Data[%d]:",index);
    while(p){
        counter++;
        printf("[%d]",p->key);
        if(p->key == key)
            return 1;
        else
            p=p->next;
    }
    return 0;
}
