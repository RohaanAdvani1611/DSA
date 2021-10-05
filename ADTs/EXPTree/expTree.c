#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "expTree.h"

void initTree(ET *t, char *str){
    
    int i = 0;
    node *p1, *p2;
    node q;
    //No: of open brackets
    int brac = 0;
    
    if (!*t)
        *t = NULL;
    nstack noStack;
    cstack opStack;
    ninit(&noStack, 50);
    cinit(&opStack, 50);
    
    while (str[i] != '\0'){
        if (cisEmpty(opStack)){
            if (str[i] == '(')
                brac++;
            cpush(&opStack, str[i]);            
        }

        else if (str[i] == '('){
            brac++;
            cpush(&opStack, str[i]);
        }
        
        else if (isdigit(str[i])){
            int num = 0;
            while (isdigit(str[i])){
                num  = 10 * num + (int)(str[i] - '0');
                i++;
            }
            npush(&noStack, create_intnode(num));
            i -= 1;
        }
        
        else if (str[i] == ')'){
            brac--;
            while (cpeek(opStack) != '('){
                char curr = cpop(&opStack);

                p1 = npeek(noStack);
                npop(&noStack);
                p2 = npeek(noStack);
                npop(&noStack);
                
                q = create_charnode(curr);
                q.right = p1;
                q.left = p2;
                npush(&noStack, q);
            }
            cpop(&opStack);
        }
        //Take care of unnecessary spaces in expression
        else if (str[i] == ' '){
            i++;
            continue;
        }
        
        else if (!cisEmpty(opStack) && precendence(str[i]) < precendence(cpeek(opStack)) && precendence(str[i]) != -1){
            while (precendence(str[i]) < precendence(cpeek(opStack))){
                char curr = cpop(&opStack);
                
                p1 = npeek(noStack);
                npop(&noStack);
                p2 = npeek(noStack);
                npop(&noStack);
                    
                q = create_charnode(curr);
                q.right = p1;
                q.left = p2;
                npush(&noStack, q);
            }
            cpush(&opStack, str[i]);
        }
        
        else{
            if (precendence(str[i]) == -1){
                printf("Invalid Input");
                *t = NULL;
                return;
            }
             cpush(&opStack , str[i]);
        }  
        i++; 
    }
    
    //If open brackets var is not 0 at end, all brackets haven't been closed
    if (brac){
        printf("Invalid Expression");
        *t = NULL;
        return;
    }
    *t = npeek(noStack);
    npop(&noStack);
}

void Traverse(ET t){
    if (!t)
        return ;
    Traverse(t->left);
    //Since operands are leaves in expression tree 
    if (!t->left && !t->right){
        printf("%d ", t->key.digit);
    }
    else{
        printf("%c ", t->key.oper);
    }
    Traverse(t->right);
    return;
}

node *compute(ET t, node *root){
    if (!t)
        return NULL;
    if (!t->left && !t->right)
        return t;
    t->left = compute(t->left, root);
    t->right = compute(t->right, root);

    Traverse(root);
    printf("\n");
    node *ans = (node*)malloc(sizeof(node));
    ans->left = ans->right = NULL;

    int p;

    switch(t->key.oper){
        case '+':
            p = t->left->key.digit + t->right->key.oper;
            break;
        case '-':
            p = t->left->key.digit - t->right->key.oper;
            break;
        case '/':
            p = t->left->key.digit / t->right->key.oper;
            break;
        case '*':
            p = t->left->key.digit * t->right->key.oper;
            break;
    }
    ans->key.digit = p;
    return ans;
}

//Helper Functions
node create_intnode(int data){
    node *p = (node*)malloc(sizeof(node));
    p->key.digit = data;
    p->left = p->right = NULL;
    return *p;
}

node create_charnode(char data){
    node *p = (node*)malloc(sizeof(node));
    p->key.oper = data;
    p->left = p->right = NULL;
    return *p;
}

int precendence(char op){
    if (op == '/')
        return 4;
    else if (op == '*')
        return 3;
    else if (op == '+')
        return 2;
    else if (op == '-')
        return 1;
    else
        return -1; 
}

//Operator Stack Functions

void cinit(cstack *s,int length){
    s->top = -1;
    s->len = length;
    s->A = (char*)malloc(sizeof(char)*length);
}

void cpush(cstack *s,char data){
    if (s->top == s->len - 1)
        return ;
    s->top++;
    s->A[s->top] = data;
    return ;
}

char cpop(cstack *s){
    if (s->top == -1)
        return ;
    char p;
    p = s->A[s->top];
    s->top--;
    return p;
}

int cisFull(cstack s) {
    if(s.top == s.len - 1)
        return 1;
    else
        return 0;
}

int cisEmpty(cstack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}

char cpeek(cstack s){
    return s.A[s.top];
}

//Number Stack Functions
void ninit(nstack *s, int t) {
    s->size = t;
    s->arr = (node*)malloc(sizeof(node)* t);
    s->top = -1;
}

void npush(nstack *s, node p) {
    if(nisFull(*s))
        return;
    s->arr[++s->top] = p;
    return;
}

node npop(nstack *s){
    node n;
    n.key.digit = INT_MIN;
    n.left = NULL;
    n.right = NULL;
    if(nisEmpty(*s))
        return n;
    node r = s->arr[s->top];
    s->top--;
    return r;
}

node *npeek (nstack s) {
    node *n = (node*)malloc(sizeof(node));
    n->key.digit = INT_MIN;
    n->left = NULL;
    n->right = NULL;
    if(nisEmpty(s))
        return n;
    n->key.digit = s.arr[s.top].key.digit;
    n->left = s.arr[s.top].left;
    n->right = s.arr[s.top].right;
    return n;
 }

int nisFull(nstack s){
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int nisEmpty(nstack s){
    if(s.top == -1)
        return 1;
    else
        return 0;
}
