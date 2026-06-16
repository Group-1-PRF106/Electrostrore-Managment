#include "add_functions.h"

void addOrder(Order orders[],
              int *orderCount,
              Customer customers[],
              int customerCount,
              Item items[],
              int itemCount,
              Bundle bundles[],
              int bundleCount)
{
    Order newOrder;

    int i;
    int found;
    int itemIndex;
    int bundleIndex;

    printf("Input Order ID: ");
    scanf("%s", newOrder.orderID);

    found = 0;

    for(i = 0; i < *orderCount; i++)
    {
        if(strcmp(orders[i].orderID,
                  newOrder.orderID) == 0)
        {
            found = 1;
        }
    }

    if(found == 1)
    {
        printf("ERROR: Order ID already exists!\n");
        return;
    }

    printf("Input Customer ID: ");
    scanf("%s", newOrder.customerID);

    found = 0;

    for(i = 0; i < customerCount; i++)
    {
        if(strcmp(customers[i].customerID,
                  newOrder.customerID) == 0)
        {
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("ERROR: Customer not found!\n");
        return;
    }

    printf("Input Number Of Items: ");
    scanf("%d", &newOrder.itemCount);

    if(newOrder.itemCount <= 0)
    {
        printf("ERROR: Invalid Quantity!\n");
        return;
    }

    newOrder.subtotal = 0;

    for(i = 0; i < newOrder.itemCount; i++)
    {
        int j;

        printf("\nItem %d\n", i + 1);

        printf("Input Item ID: ");
        scanf("%s", newOrder.itemIDs[i]);

        itemIndex = -1;

        for(j = 0; j < itemCount; j++)
        {
            if(strcmp(items[j].itemID,
                      newOrder.itemIDs[i]) == 0)
            {
                itemIndex = j;
            }
        }

        if(itemIndex == -1)
        {
            printf("ERROR: Item not found!\n");
            return;
        }

        printf("Input Quantity: ");
        scanf("%d", &newOrder.quantities[i]);

        if(newOrder.quantities[i] <= 0)
        {
            printf("ERROR: Invalid Quantity!\n");
            return;
        }

        newOrder.subtotal +=
            items[itemIndex].price *
            newOrder.quantities[i];
    }

    printf("Input Bundle ID (NONE if no bundle): ");
    scanf("%s", newOrder.bundleID);

    newOrder.discount = 0;

    if(strcmp(newOrder.bundleID, "NONE") != 0)
    {
        bundleIndex = -1;

        for(i = 0; i < bundleCount; i++)
        {
            if(strcmp(bundles[i].bundleID,
                      newOrder.bundleID) == 0)
            {
                bundleIndex = i;
            }
        }

        if(bundleIndex == -1)
        {
            printf("ERROR: Bundle not found!\n");
            return;
        }

        newOrder.discount =
            newOrder.subtotal *
            bundles[bundleIndex].discountPercent
            / 100;
    }

    newOrder.total =
        newOrder.subtotal -
        newOrder.discount;

    printf("Input Payment Status: ");
    scanf("%s", newOrder.paymentStatus);

    orders[*orderCount] = newOrder;

    (*orderCount)++;

    printf("Order Added Successfully!\n");
}