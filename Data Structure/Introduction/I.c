#include <stdio.h>
#include <string.h>

struct CreditCard
{
    long long int number;
    char name[50];
    int expiry_month;
    int expiry_year;
    int cvv;
    float limit;
};

int main(void)
{
    struct CreditCard card1;

    card1.number = 1234567891234567;
    strcpy(card1.name, "John Carter");
    card1.expiry_month = 6;
    card1.expiry_year = 30;
    card1.cvv = 123;
    card1.limit = 1200;

    printf("%lld\n", card1.number);
    printf("%s\n", card1.name);
    printf("0%i/", card1.expiry_month);
    printf("%i\n", card1.expiry_year);
    printf("%i\n", card1.cvv);
    printf("U$: %.2f", card1.limit);

    return 0;
}