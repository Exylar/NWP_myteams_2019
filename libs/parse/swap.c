/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** swap
*/

static void swap(char **ptr1, char **ptr2)
{
    char *swp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = swp;
}
