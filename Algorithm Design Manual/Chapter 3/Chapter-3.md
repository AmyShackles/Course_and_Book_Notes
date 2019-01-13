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

### Comparisons:

**Advantages of linked lists over static arrays**:

- Overflow can never occur unless memory actually full
- Insertions/deletions are simpler
- With large records, moving pointers is easier and faster than moving items themselves

**Advantages of arrays**:

- Linked lists require extra space for storing pointers
- Linked lists do not allow for random access
- Arrays allow for better memory locality and cache performance than random pointer jumping

**Take Home**: Dynamic memory allocation provides us with flexibility on how and where we use our limited storage resources

### Stacks and Queues:

**Container**: Data structure that permits storage and retrieval of data items _independent of content_, unlike dictionaries which are abstract data types that retrieve based on key, values, or content.

Containers are distinguished by retrieval order support. In two of the most important types of container, retrieval order is based on insertion order.

**Stacks**: Last in, first out (LIFO) - simple to implement and efficient, so good container to use if retrieval order doesn't matter, such as processing batch jobs. _put_ and _get_ operations usually called 'push' and 'pop'.
`push(x, s) -> insert item x at top of stack s`
`pop(s) -> return (and remove) top item of stack s`

Algorithmically, LIFO tends to happen in the course of executing recursive algorithms.

**Queues**: First in, first out (FIFO) - useful when wanting to reduce maximum time spent waiting (average waiting time is same whether LIFO or FIFO). Trickier to implement -> most appropriate for applications (like certain simulations) where order is important. _put_ and _get_ operations are called 'enqueue' and 'dequeue'
`enqueue(x, q) -> insert item x at the back of queue q`
`dequeue(q) -> return (and remove) front item from queue q`

Stacks and queues can be implemented using either arrays or linked lists.

### Dictionaries:

Permits access to data items by content

Primary operations supported by dictionaries:

- Search(D, k) - Given key k, return pointer to element in dictionary D where key value is k, if exists.
- Insert (D, x) - Given date item x, add to the set in dictionary D.
- Delete (D, x) - Given a pointer to a given data item x in dictionary D, remove it from D

Some dictionary data structures also support:

- Max(D) or Min(D) - Retrieve item with longest (or smallest) key from D. Enables dictionary to serve as a priority queue.
- Predecessor(D, x) or Successor(D, x) -> retrieve the item from D whose key is immediately before (or after) x in sorted order - enables iterating through elements.

Many data processing tasks can be handled with dictionaries.

Ex: Want to remove duplicate names from mailing list and print in sorted order:
Initiate empty dictionary D whose search key will be record name. Read through mailing list, search to see if in dictionary. If not, insert. When finished, extract remaining names out of dictioanry. Start from first item Min(D) and calling successor until obtain Max(D), traverse all elements in sorted order.

Running times for fundamental dictionary operations:

- Search -> you test the key against (potentially) each element of an unsorted array, which is linerar as worst case
- Insertion - implemented by incrementing n and copying item to nth cell in the array, leaving bulk of array untouched, so this is constant time
- Deletion - removing the nth element leaves a hole that needs to be filled, which would mean O(n) but you can write over A[x] with A[n] and decrement n, which would be constant time
- Predecessor and Successor -> both require iterating through all elements to determine in an unsorted array
- Min and Max are also defined with respect to sorted order and require linear sweeps to identify in an unsorted array.

For sorted arrays:

- Searching can be done in O(log n) time using binary search.
- Min/Max, Successor/Predecessor become O(1)
- Insertions and deletions become more expensive (O(n)) because they may result in moving other elements around

**Take Home**: Data structure design must balance all the different operations it supports. The fastest data structure to support both operations A and B may well not be the fastest data structure to support A or B.

| Dictionary operation                  | Unsorted Array | Sorted Array |
| ------------------------------------- | -------------- | ------------ |
| Search (L, k)                         | O(n)           | O(log n)     |
| Insert (L, x)                         | O(1)           | O(n)         |
| Delete (L, x)                         | O(1)\*         | O(n)         |
| Successor (L, x) / Predecessor (L, x) | O(n)           | O(1)         |
| Min (L) / Max (L)                     | O(n)           | O(1)         |

| Dictionary Operation | Singly Unsorted | Doubly Unsorted | Singly Sorted | Doubly Sorted |
| -------------------- | --------------- | --------------- | ------------- | ------------- |
| Search (L, k)        | O(n)            | O(n)            | O(n)          | O(n)          |
| Insert (L, x)        | O(1)            | O(1)            | O(n)          | O(n)          |
| Delete (L, x)        | O(n)\*          | O(1)            | O(n)\*        | O(1)          |
| Successor (L, x)     | O(n)            | O(n)            | O(1)          | O(1)          |
| Predecessor(L, x)    | O(n)            | O(n)            | O(n)\*        | O(1)          |
| Minimum(L)           | O(n)            | O(n)            | O(1)          | O(1)          |
| Maximum(L)           | O(n)            | O(n)            | O(1)          | O(1)          |

Deletion from singly linked list is O(n) because you only have pointer to item to be deleted, so you need to traverse the list to find the previous node in order to update that node's next property - a doubly linked list solves that problem.
Deleting is faster for sorted linked lists than for sorted arrays because there's no need to move elements around following deletion.

Searching - sorting is less beneficial for linked lists because you can't implement a binary search due to the inability to randomly access. Linked lists allow you to terminate early when searches are unsuccessful, but worst case is still linear.

Successor can be implemented in constant time, but predecessor faces the same issue mentioned earlier, having no reference to predecessor, necessitating iteration through list.

Maximum - max element sits at tail of list which would normally require O(n), but we can maintain a pointer to the list tailk, which can be updated in constant time in doubly linked lists -> on insertion, check fi last->next = NULL and on deletion set last to predecessor of last if last element.

Maximum can be constant for singly linked lists as well because the charge for deletion is already linear and adding an extra linear pass to update the pointer doesn't harm the asymptotic complexity of delete while it does give us the maximum in constant time.

### Binary Search Trees

Requires fast access to median elements above and below a given node.

**Rooted binary tree**: recursively defined as either being empty or consisting of a node called the root together with two rooted binary trees called the left and right subtrees.

The order among brother nodes matters in rooted trees such that left is different from right.

**Binary search tree**: labels each node with a single key so that for any node labeled x, all nodes in the left subtree of x have keys < x while all nodes in the right subtree of x have keys > x. For any binary tree on n nodes, and any set of n keys, there is _one_ and only one labeling that makes it a binary search tree.

Binary tree nodes have left and right pointer fields, an optional parent pointer, and a data field.

```
typedef struct tree {
    item_type item; /* data item */
    struct tree *parent; /* pointer to parent */
    struct tree *left; /* pointer to left child */
    struct tree *right; /* pointer to right child */
} tree;
```

Basic operations supported by binary trees: searching, traversal, deletion, insertion

**Search in a tree**

```
tree *search_tree(tree *l, item_type x) {
    if (l == NULL) return (NULL);
    if (l->item == x) return (l);
    if (x < l->item)
        return( search_tree(l->left, x) );
    else
        return( search_tree(l->right, x) );
}
```

Runs in O(h) time where h denotes the height of the tree.

**Finding maximum and minimum**

```
tree *find_minimum(tree *t) {
    tree *min;
    if (t == NULL) return (NULL);
    min = t;
    while (min->left != NULL)
        min = min->left;
    return(min);
}
```

Traverse, visiting nodes recursively in accordance with the policy that all keys smaller than root lie in left subtree of root and all keys bigger than root lie in right subtree, produces an in-order traversal of the search tree.

```
void traverse_tree(tree *l) {
    if (l != NULL) {
        traverse_tree(l->left);
        process_item(l->item);
        traverse_tree(l->right);
    }
}
```

O(n) traverseal.

Changing the position of process_item to be before traversing left and right subtrees results in pre-order traversal and moving it to after traversing left and right subtrees results in post-order traversal.

**Insertion**:

```
insert_tree(tree **l, item_type x, tree *parent) {
    tree *p;
    if (*l == NULL) {
        p = malloc(sizeof(tree)); /* allocate new node */
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p; /* link into parent record */
        return;
    }
    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);
}
```

Insertion is a constant time opreation after the search has been performed in O(h) time.

**Deletion**
If node to delete has no children, clear pointer to that node.
If node to delete has one child, connect that node's child to its parent.
If node to delete has two children, relabel node with the key of its immediate successor in sorted order (leftmost descendant in the right subtree)

Deletion worst case complexity is O(h) with h being the height of the tree. The height of a tree can range from log n to n dependent on insertion order.
