#include "add_functions.h"

void addBundle(Bundle bundles[],
               int *bundleCount,
               Item items[],
               int itemCount)
{
    Bundle newBundle;

    int i;
    int j;
    int found;

    printf("Input Bundle ID: ");
    scanf("%s", newBundle.bundleID);

    found = 0;

    for(i = 0; i < *bundleCount; i++)
    {
        if(strcmp(bundles[i].bundleID,
                  newBundle.bundleID) == 0)
        {
            found = 1;
        }
    }

    if(found == 1)
    {
        printf("ERROR: Bundle ID already exists!\n");
        return;
    }

    printf("Input Bundle Name: ");
    scanf(" %[^\n]", newBundle.bundleName);

    printf("Input Number Of Items: ");
    scanf("%d", &newBundle.itemCount);

    if(newBundle.itemCount < 2)
    {
        printf("ERROR: Bundle must contain at least 2 items!\n");
        return;
    }

    for(i = 0; i < newBundle.itemCount; i++)
    {
        printf("Input Item ID %d: ", i + 1);
        scanf("%s", newBundle.itemIDs[i]);

        found = 0;

        for(j = 0; j < itemCount; j++)
        {
            if(strcmp(items[j].itemID,
                      newBundle.itemIDs[i]) == 0)
            {
                found = 1;
            }
        }

        if(found == 0)
        {
            printf("ERROR: Item does not exist!\n");
            return;
        }
    }

    printf("Input Discount Percent: ");
    scanf("%f", &newBundle.discountPercent);

    if(newBundle.discountPercent <= 0 ||
       newBundle.discountPercent >= 100)
    {
        printf("ERROR: Invalid Discount Percent!\n");
        return;
    }

    bundles[*bundleCount] = newBundle;

    (*bundleCount)++;

    printf("Bundle Added Successfully!\n");
}