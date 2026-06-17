#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[100];
    float price;
} Product;

void displayAllProduct(Product arr[], int n, int showPrice);
void searchProductByID(Product arr[], int n, int searchID);
void searchProductByName(Product arr[], int n, const char *keyword);
void sortProductsByPrice(Product arr[], int n);

#endif