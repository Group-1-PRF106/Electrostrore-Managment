#include "add_functions.h"

void addItem(struct item items[], int *n)
{
    struct item newItem;
    int i;
    int found = 0;

    printf("Input Item ID: ");
    scanf("%d", &newItem.productid);

    for(i = 0; i < *n; i++)
    {
        if(items[i].productid == newItem.productid)
        {
            found = 1;
        }
    }

    if(found == 1)
    {
        printf("ERROR: ID already exists!\n");
    }
    else
    {
        printf("Input Name: ");
        scanf(" %39s", newItem.productname);

        printf("Input Company: ");
        scanf("%39s", newItem.productcomp);

        printf("Input Price: ");
        scanf("%d", &newItem.price);

        if(newItem.price <= 0)
        {
            printf("ERROR: Price must be > 0\n");
        }
        else
        {
            printf("Input Quantity: ");
            scanf("%d", &newItem.Qnt);

            if(newItem.Qnt <= 0)
            {
                printf("ERROR: Quantity must be > 0\n");
            }
            else
            {
                items[*n] = newItem;
                (*n)++;

                printf("Add Item Successfully!\n");
            }
        }
    }
}