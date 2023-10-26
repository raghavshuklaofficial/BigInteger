#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node *add(struct node *num1, struct node *num2) {
    struct node *result = NULL;
    struct node *temp, *prev = NULL;
    int carry = 0, sum;

    while (num1 != NULL || num2 != NULL) {
        sum = carry + (num1 ? num1->data : 0) + (num2 ? num2->data : 0);
        carry = (sum >= INT_MAX) ? 1 : 0;
        sum = sum % INT_MAX;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = sum;
        temp->next = NULL;
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    if (carry > 0) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = carry;
        temp->next = NULL;
        prev->next = temp;
    }

    return result;
}

struct node *subtract(struct node *num1, struct node *num2) {
    struct node *result = NULL;
    struct node *temp, *prev = NULL;
    int borrow = 0, diff;

    while (num1 != NULL || num2 != NULL) {
        diff = borrow + (num1 ? num1->data : 0) - (num2 ? num2->data : 0);
        borrow = (diff < 0) ? -1 : 0;
        diff = (diff < 0) ? diff + INT_MAX : diff;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = diff;
        temp->next = NULL;
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    return result;
}

struct node *multiply(struct node *num1, struct node *num2) {
    struct node *result = NULL;
    struct node *temp, *prev = NULL;
    int carry = 0, prod, i, j;
    int m = 0, n = 0;

    struct node *temp1 = num1;
    while (temp1 != NULL) {
        m++;
        temp1 = temp1->next;
    }

    struct node *temp2 = num2;
    while (temp2 != NULL) {
        n++;
        temp2 = temp2->next;
    }

    int *arr1 = (int*)malloc(m * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));

    i = 0;
    temp1 = num1;
    while (temp1 != NULL) {
        arr1[i++] = temp1->data;
        temp1 = temp1->next;
    }

    j = 0;
    temp2 = num2;
    while (temp2 != NULL) {
        arr2[j++] = temp2->data;
        temp2 = temp2->next;
    }

    int *res = (int*)calloc(m + n, sizeof(int));
    for (i = m - 1; i >= 0; i--) {
        carry = 0;
        for (j = n - 1; j >= 0; j--) {
            prod = arr1[i] * arr2[j] + carry + res[i + j + 1];
            carry = prod / INT_MAX;
            res[i + j + 1] = prod % INT_MAX;
        }
        res[i + j + 1] = carry;
    }

    for (i = 0; i < m + n; i++) {
        if (res[i] != 0) break;
    }

    for (j = i; j < m + n; j++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = res[j];
        temp->next = NULL;
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    if (result == NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = 0;
        temp->next = NULL;
        result = temp;
    }

    free(arr1);
    free(arr2);
    free(res);

    return result;
}

struct node *divide(struct node *num1, struct node *num2) {
    struct node *result = NULL;
    struct node *temp, *prev = NULL;
    int cmp = 0, i, j;
    int m = 0, n = 0;

    struct node *temp1 = num1;
    while (temp1 != NULL) {
        m++;
        temp1 = temp1->next;
    }

    struct node *temp2 = num2;
    while (temp2 != NULL) {
        n++;
        temp2 = temp2->next;
    }

    int *arr1 = (int*)malloc(m * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));

    i = 0;
    temp1 = num1;
    while (temp1 != NULL) {
        arr1[i++] = temp1->data;
        temp1 = temp1->next;
    }

    j = 0;
    temp2 = num2;
    while (temp2 != NULL) {
        arr2[j++] = temp2->data;
        temp2 = temp2->next;
    }

    int *res = (int*)calloc(m, sizeof(int));
    for (i = 0; i < m; i++) {
        res[i] = 0;
    }

    for (i = 0; i < m; i++) {
        res[i] = res[i] + arr1[i];
        while (1) {
            cmp = 0;
            for (j = n - 1; j >= 0; j--) {
                if (res[i + j] < arr2[j]) {
                    cmp = -1;
                    break;
                } else if (res[i + j] > arr2[j]) {
                    cmp = 1;
                    break;
                }
            }
            if (cmp < 0) break;
            for (j = n - 1; j >= 0; j--) {
                res[i + j] = res[i + j] - arr2[j];
                if (res[i + j] < 0 && j > 0) {
                    res[i + j] = res[i + j] + INT_MAX;
                    res[i + j - 1] = res[i + j - 1] - 1;
                }
            }
            if (j < 0) break;
        }
    }

    for (i = 0; i < m; i++) {
        if (res[i] != 0) break;
    }

    for (j = i; j < m; j++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = res[j];
        temp->next = NULL;
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    if (result == NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = 0;
        temp->next = NULL;
        result = temp;
    }

    free(arr1);
    free(arr2);
    free(res);

    return result;
}

struct node *modulus(struct node *num1, struct node *num2) {
    struct node *result = NULL;
    struct node *temp, *prev = NULL;
    int cmp = 0, i, j;
    int m = 0, n = 0;

    struct node *temp1 = num1;
    while (temp1 != NULL) {
        m++;
        temp1 = temp1->next;
    }

    struct node *temp2 = num2;
    while (temp2 != NULL) {
        n++;
        temp2 = temp2->next;
    }

    int *arr1 = (int*)malloc(m * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));

    i = 0;
    temp1 = num1;
    while (temp1 != NULL) {
        arr1[i++] = temp1->data;
        temp1 = temp1->next;
    }

    j = 0;
    temp2 = num2;
    while (temp2 != NULL) {
        arr2[j++] = temp2->data;
        temp2 = temp2->next;
    }

    int *res = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (i = 0; i < m; i++) {
        res[i] = res[i] + arr1[i];
        while (1) {
            cmp = 0;
            for (j = n - 1; j >= 0; j--) {
                if (res[i + j] < arr2[j]) {
                    cmp = -1;
                    break;
                } else if (res[i + j] > arr2[j]) {
                    cmp = 1;
                    break;
                }
            }
            if (cmp < 0) break;
            for (j = n - 1; j >= 0; j--) {
                res[i + j] = res[i + j] - arr2[j];
                if (res[i + j] < 0 && j > 0) {
                    res[i + j] = res[i + j] + INT_MAX;
                    res[i + j - 1] = res[i + j - 1] - 1;
                }
            }
            if (j < 0) break;
        }
    }

    for (i = 0; i < n; i++) {
        if (res[i] != 0) break;
    }

    for (j = i; j < n; j++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = res[j];
        temp->next = NULL;
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    if (result == NULL) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = 0;
        temp->next = NULL;
        result = temp;
    }

    free(arr1);
    free(arr2);
    free(res);

    return result;
}
