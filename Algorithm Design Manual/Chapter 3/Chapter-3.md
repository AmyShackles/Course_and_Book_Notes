## Data Structures

### Contiguous vs. Linked Data Structures

**Contiguous**: single slab of memory - arrays, matrices, heaps, hash tables
**Linked**: distinct chunks of memory bound together by pointer - lists, trees, graphs, graph adjacency lists

### Arrays

Structures of fixed-sized data records where each element can be efficiently accessed via index

**Advantages**

- Constant-time access via index
- Space efficiency - only require space enough for data
- Memory locality - physical proximity of successive data allows for exploitations of memory caching

### Pointers and Linked Structures

**Pointers** represent the address of a location in memory

```
typedef struct list {
    item_type item; /* data item */
    struct list *next; /* point to successor */
} list;
```

- Each node in list contains one or more data fields (item) that store the data necessary
- Each node contains a pointer to at least one other node (next), which means most of the space used in the data structure has to be devoted to pointers, not data
- Need pointer to head of structure to know where to access it

**Searching a list** - can be done iteratively or recursively.

Recursive implementation of a search:

```
list *search_list(list *l, item_type x) {
    if (l == NULL) return (NULL);
    if (l -> item == x)
        return(l);
    else
        return( search_list(l->next, x));
}
```

**Insertion** - insertion at the beginning avoides traversal, but have to update pointer

```
void insert_list(list **l, item_type x) {
    list *p;
    p = malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p; /* Copies p to the place pointed to by l
}
```

**Deletion from a list** - more complicated because you need to find the pointedr for the predecessor of the item you want to delete. Recursion!

```
list *predecessor_list(list *l, item_type x) {
    if ((l == NULL) || (l->next == NULL)) {
        /* predecessor sought on null list */
        return (NULL);
    }
    if ((l->next)->item == x)
        return (l)
    else
        return( predecessor_list(l->next, x));
}
```

Predecessor is necessary because we need to change 'next' reference.

Deletion is simple after ruling out that the delete item does not exist. Have to make sure to reset pointer to head if deleting first element.

```
delete_list(list **l, item_type x) {
    list *p; /* item pointer */
    list *pred; /* predecessor pointer */
    list *search_list(), *predecessor_list();

    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
    if (pred == NULL) /* splice out of list */
        *l = p->next;
    else
        pred->next = p->next;
    free(p) /* Free memory used by node */
    }
}
```
