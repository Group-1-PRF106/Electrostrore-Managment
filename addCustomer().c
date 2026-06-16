#include "add_functions.h"

int checkEmail(char email[])
{
    int i;

    for(i = 0 ; email[i] != '\0' ; i++)
    {
        if(email[i] == '@')
        {
            return 1;
        }
    }

    return 0;
}

int checkPhone(char phone[])
{
    int i;

    for(i = 0 ; phone[i] != '\0' ; i++)
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            return 0;
        }
    }

    return 1;
}

void addCustomer(Customer customers[],
                 int *n)
{
    Customer newCus;

    int i;
    int found = 0;

    printf("Input Customer ID: ");
    scanf("%s", newCus.customerID);

    for(i=0;i<*n;i++)
    {
        if(strcmp(customers[i].customerID,
                  newCus.customerID)==0)
        {
            found = 1;
        }
    }

    if(found == 1)
    {
        printf("ERROR: ID Exists\n");
    }
    else
    {
        printf("Input Name: ");
        scanf(" %[^\n]", newCus.name);

        printf("Input Email: ");
        scanf("%s", newCus.email);

        if(checkEmail(newCus.email)==0)
        {
            printf("ERROR: Invalid Email\n");
        }
        else
        {
            printf("Input Phone: ");
            scanf("%s", newCus.phone);

            if(checkPhone(newCus.phone)==0)
            {
                printf("ERROR: Invalid Phone\n");
            }
            else
            {
                customers[*n]=newCus;
                (*n)++;

                printf("Customer Added!\n");
            }
        }
    }
}