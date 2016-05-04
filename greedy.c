#import <stdio.h>
#import <cs50.h>
#import <math.h>

int main(void)
{
    
    float total;
    int intDollar;
    int intTotal; 
    float cents; 
    int intCents; 
    int totQuarters; 
    int totDimes; 
    int totNick; 
    int totPennies; 
    int totalCoins = 0; 
    
    //Constants for coin values 
    int const quarter = 25; 
    int const dime = 10; 
    int const nickel = 5; 
    int const penny = 1; 
    
    do 
    {
        printf("Enter total dollar amount: ");
        total = GetFloat();
    } 
    while(total < 0);
    

    intDollar = (int) total;
    cents = round((total - intDollar)*100);
    intCents = (int) cents; 

    intTotal = (intDollar * 100) + intCents;

    
    totQuarters = intTotal / quarter; 
    
    intTotal = (intTotal - (quarter*totQuarters)); 
    
    totalCoins = totalCoins + totQuarters; 
    
    
    totDimes = intTotal / dime; 
        
    intTotal = (intTotal - (dime*totDimes)); 
        
    totalCoins = totalCoins + totDimes; 

        
    totNick = intTotal / nickel; 
        
    intTotal = (intTotal - (nickel*totNick)); 
        
    totalCoins = totalCoins +totNick; 


    totPennies = intTotal / penny; 
        
    intTotal = (intTotal - (penny*totPennies)); 
        
    totalCoins = totalCoins + totPennies; 
    

    printf("%d\n", totalCoins);
    
    
}
