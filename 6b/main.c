#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition
struct node {
    int co;            // Coefficient
    int po;            // Power / Exponent
    struct node *addr; // Pointer to next node
};
typedef struct node *NODE;

// 2. Insert at End Function
NODE insertend(NODE start, int co, int po) {
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if(start == NULL) return temp;

    cur = start;
    while(cur->addr != NULL) cur = cur->addr;
    cur->addr = temp;
    return start;
}

// 3. Multiplication Function
NODE multiply(NODE poly1, NODE poly2) {
    NODE p1 = poly1;
    NODE p2 = poly2;
    NODE res = NULL;

    if (poly1 == NULL || poly2 == NULL) return NULL;

    while (p1 != NULL) {
        p2 = poly2;
        while (p2 != NULL) {
            int coeff = p1->co * p2->co;
            int power = p1->po + p2->po;

            // Check if a node with the same power already exists to combine them
            NODE temp = res;
            int found = 0;
            while (temp != NULL) {
                if (temp->po == power) {
                    temp->co += coeff;
                    found = 1;
                    break;
                }
                temp = temp->addr;
            }

            // If the power is new, insert it at the end
            if (!found) {
                res = insertend(res, coeff, power);
            }

            p2 = p2->addr;
        }
        p1 = p1->addr;
    }
    return res;
}

// 4. Display Function
void display(NODE start) {
    if (start == NULL) {
        printf("0\n");
        return;
    }
    NODE cur = start;
    while (cur != NULL) {
        printf("%dx^%d", cur->co, cur->po);
        cur = cur->addr;
        if (cur != NULL && cur->co >= 0) {
            printf(" + ");
        } else if (cur != NULL) {
            printf(" "); // Gracefully handles formatting for negative numbers
        }
    }
    printf("\n");
}

// 5. Your Main Function
int main()
{
    NODE poly1 = NULL, poly2 = NULL, poly;
    int n, i, co, po;

    printf("\n Read no of terms for the 1st polynomial: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf(" Read co & po for the %d term: ", i);
        scanf("%d%d", &co, &po);
        poly1 = insertend(poly1, co, po);
    }
    printf("\n First polynomial is: ");
    display(poly1);

    printf("\n Read no of terms for the 2nd polynomial: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf(" Read co & po for the %d term: ", i);
        scanf("%d%d", &co, &po);
        poly2 = insertend(poly2, co, po);
    }
    printf("\n Second polynomial is: ");
    display(poly2);

    poly = multiply(poly1, poly2);
    printf("\n The resultant polynomial is: ");
    display(poly);

    return 0;
}
