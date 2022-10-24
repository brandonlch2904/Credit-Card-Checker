#include <cs50.c>
#include <stdio.h>

long long get_card(void);
int check_sum(long long cardNumber);
int length_cal(long long cardNumber);
int find_start(long long cardNumber);
char *check_card(int cardLength, int startDigits, int checkSum);

int main(void)
{
    //Get card number from user
    long long cardNumber = get_card();
    //Checksum
    int checkSum = check_sum(cardNumber);
    // Check card length
    int cardLength = length_cal(cardNumber);
    //Check starting digits
    int startDigits = find_start(cardNumber);
    //Check card type
    char *cardType = check_card(cardLength, startDigits, checkSum);
    printf("%s\n", cardType);


}

long long get_card(void)
{
    long long cardNumber;
    do
    {
        cardNumber = get_long_long("What's your card number: \n");
    }
    while (cardNumber < 0);
    return cardNumber;
}

int check_sum(long long cardNumber)
{
    int first = 0, second = 0, totalFirst = 0, totalSecond = 0, totalSum = 0, secondmult = 0;
    while (cardNumber > 0)
    {
        //Get last digit
        for (int i = 0; i < 1; i++)
        {
            first = cardNumber % 10;
            totalFirst += first;
            cardNumber /= 10;
        }
        //Get second last digit
        for (int i = 0; i < 1; i++)
        {
            second = cardNumber % 10;
            secondmult = second * 2;
            if (secondmult > 9)
            {
                secondmult = (secondmult % 10) + 1;
            }
            totalSecond += secondmult;
            cardNumber /= 10;
        }
    }
    totalSum = totalFirst + totalSecond;
    return totalSum;
}


int length_cal(long long cardNumber)
{
    int length;
    //Remove last digit and add 1 to length until none
    for (length = 0; cardNumber > 0; length++)
    {
        cardNumber /= 10;
    }
    return length;
}

int find_start(long long cardNumber)
{
    //Get first 2 digits
    while (cardNumber > 99)
    {
        cardNumber /= 10;
    }
    //Get first digit if starts with 4
    if (cardNumber >= 40 && cardNumber <= 49)
    {
        cardNumber /= 10;
    }
    return cardNumber;

}

char *check_card(int cardLength, int startDigits, int checkSum)
{
    char *cardType;
    //checkSum
    int lastnum = checkSum % 10;


    if (lastnum == 0 && (cardLength >= 13 && cardLength <= 16))
    {
        if (cardLength == 15 && (startDigits == 34 || startDigits == 37))
        {
            cardType = "AMEX";
            return cardType;
        }
        else if (cardLength == 16 && (startDigits > 50 && startDigits < 56))
        {
            cardType = "MASTERCARD";
            return cardType;
        }
        else if (startDigits == 4)
        {
            cardType = "VISA";
            return cardType;
        }
        else
        {
            cardType = "INVALID";
            return cardType;
        }
    }
    else
    {
        cardType = "INVALID";
        return cardType;
    }
}