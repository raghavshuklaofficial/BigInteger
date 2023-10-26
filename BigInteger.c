#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigInteger.h"

struct node *create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void free_node(struct node *node) {
    free(node);
}

void free_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        struct node *next = temp->next;
        free_node(temp);
        temp = next;
    }
}

struct node *add_big_integers(struct node *num1, struct node *num2) {
    return add(num1, num2);
}

struct node *subtract_big_integers(struct node *num1, struct node *num2) {
    return subtract(num1, num2);
}

struct node *multiply_big_integers(struct node *num1, struct node *num2) {
    return multiply(num1, num2);
}

struct node *divide_big_integers(struct node *num1, struct node *num2) {
    return divide(num1, num2);
}

struct node *modulus_big_integers(struct node *num1, struct node *num2) {
    return modulus(num1, num2);
}

void print_big_integer(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create two big integers.
    struct node *num1 = create_node(12345);
    struct node *num2 = create_node(67890);

    // Add the two big integers together.
    struct node *add_result = add_big_integers(num1, num2);

    // Subtract the two big integers.
    struct node *subtract_result = subtract_big_integers(num1, num2);

    // Multiply the two big integers together.
    struct node *multiply_result = multiply_big_integers(num1, num2);

    // Divide the first big integer by the second big integer.
    struct node *divide_result = divide_big_integers(num1, num2);

    // Compute the modulus of the first big integer by the second big integer.
    struct node *modulus_result = modulus_big_integers(num1, num2);

    // Print the results to the console.
    printf("Add result: ");
    print_big_integer(add_result);

    printf("Subtract result: ");
    print_big_integer(subtract_result);

    printf("Multiply result: ");
    print_big_integer(multiply_result);

    printf("Divide result: ");
    print_big_integer(divide_result);

    printf("Modulus result: ");
    print_big_integer(modulus_result);

    // Free the big integers from memory.
    free_list(num1);
    free_list(num2);
    free_list(add_result);
    free_list(subtract_result);
    free_list(multiply_result);
    free_list(divide_result);
    free_list(modulus_result);

    return 0;
}
