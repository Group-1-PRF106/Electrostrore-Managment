#include "add_functions.h"

void addItem(Item items[], int *n)
{
    Item newItem;
    int i;
    int found = 0;

    printf("Input Item ID: ");
    scanf("%s", newItem.itemID);

    for(i = 0; i < *n; i++)
    {
        if(strcmp(items[i].itemID,
                  newItem.itemID) == 0)
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
        scanf(" %[^\n]", newItem.name);

        printf("Input Price: ");
        scanf("%f", &newItem.price);

        if(newItem.price <= 0)
        {
            printf("ERROR: Price must be > 0\n");
        }
        else
        {
            printf("Input Quantity: ");
            scanf("%d", &newItem.quantity);

            if(newItem.quantity <= 0)
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