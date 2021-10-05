#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main(){
    /*
    queue q;
    initq(&q, 10);

    node r = {12, NULL, NULL};
    node w = {32, NULL, NULL};
    node e = {15, NULL, NULL};
    node t = {10, NULL, NULL};

    enqueue(&q, r);
    r.left = &e;

    enqueue(&q, *r.left);
    node item = dequeue(&q);
    printf("%d", item.key);
*/


    bst t;
    init(&t);
    insert(&t, 45);
    insert(&t, 55);
    insert(&t, 12);
    insert(&t, 15);
    printf("No. of leaf node : %d\n", count_leafnode(t));
    printf("No. of nodes in tree : %d\n", count(t));
    printf("isFree : %d\n", isFullt(t));
    printf("isComplete : %d", isComplete(t));
    return ;

}
