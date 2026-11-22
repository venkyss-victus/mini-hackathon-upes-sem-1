#include <stdio.h>

int main()
{
    int start, end;

    printf("====================================\n");
    printf("     UPES CAMPUS NAVIGATION\n");
    printf("====================================\n");

    printf("\n1.  Main Gate");
    printf("\n2.  Food Court");
    printf("\n3.  Frisco");
    printf("\n4.  Chai Garam");
    printf("\n5.  Tulip");
    printf("\n6.  Team Orange");
    printf("\n7.  Girls Hostel");
    printf("\n8.  Boys Hostel");
    printf("\n9.  Gandhi Chowk");
    printf("\n10. Block 1");
    printf("\n11. Block 2");
    printf("\n12. Block 3");
    printf("\n13. Block 4");
    printf("\n14. Block 5");
    printf("\n15. Block 6");
    printf("\n16. Block 7");
    printf("\n17. Block 8");
    printf("\n18. Block 9");
    printf("\n19. Block 10");
    printf("\n20. Block 11");
    printf("\n21. Hubble");
    printf("\n22. Lab");

    printf("\n\nEnter starting location: ");
    scanf("%d", &start);

    printf("Enter destination: ");
    scanf("%d", &end);

    if(start < 1 || start > 22 || end < 1 || end > 22)
    {
        printf("\nInvalid location selected!");
        return 0;
    }

    if(start == end)
    {
        printf("\nYou are already at your destination!");
        return 0;
    }

    printf("\n\n====================================");
    printf("\n            YOUR ROUTE");
    printf("\n====================================\n\n");

    if(start == 1)
    {
        switch(end)
        {
            case 2:
                printf("Main Gate -> Food Court");
                break;

            case 21:
                printf("Main Gate -> Hubble");
                break;

            case 13:
                printf("Main Gate -> Hubble -> Block 4");
                break;

            case 14:
                printf("Main Gate -> Hubble -> Block 4 -> Block 5");
                break;

            case 4:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam");
                break;

            case 11:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2");
                break;

            case 10:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 1");
                break;

            case 12:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3");
                break;

            case 3:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                break;

            case 9:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
                break;

            case 15:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Block 6");
                break;

            case 16:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Block 6 -> Block 7");
                break;

            case 6:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Team Orange");
                break;

            case 5:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Tulip");
                break;

            case 22:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Lab");
                break;

            case 8:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Boys Hostel");
                break;

            case 7:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Boys Hostel -> Girls Hostel");
                break;

            case 17:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Block 8");
                break;

            case 18:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Block 8 -> Block 9");
                break;

            case 19:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Block 8 -> Block 9 -> Block 10");
                break;

            case 20:
                printf("Main Gate -> Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Block 8 -> Block 9 -> Block 10 -> Block 11");
                break;
        }
    }

    else if(start == 21)
    {
        switch(end)
        {
            case 1:
                printf("Hubble -> Main Gate");
                break;

            case 2:
                printf("Hubble -> Main Gate -> Food Court");
                break;

            case 13:
                printf("Hubble -> Block 4");
                break;

            case 14:
                printf("Hubble -> Block 4 -> Block 5");
                break;

            case 4:
                printf("Hubble -> Block 4 -> Chai Garam");
                break;

            case 11:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2");
                break;

            case 10:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 1");
                break;

            case 12:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3");
                break;

            case 3:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                break;

            case 9:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
                break;

            case 6:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Team Orange");
                break;

            case 5:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Tulip");
                break;

            case 8:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Boys Hostel");
                break;

            case 7:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Boys Hostel -> Girls Hostel");
                break;

            case 22:
                printf("Hubble -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Lab");
                break;

            default:
                printf("Go towards Gandhi Chowk and then proceed to the selected location.");
        }
    }

    else if(start == 13)
    {
        switch(end)
        {
            case 1:
                printf("Block 4 -> Hubble -> Main Gate");
                break;

            case 21:
                printf("Block 4 -> Hubble");
                break;

            case 14:
                printf("Block 4 -> Block 5");
                break;

            case 4:
                printf("Block 4 -> Chai Garam");
                break;

            case 11:
                printf("Block 4 -> Chai Garam -> Block 2");
                break;

            case 10:
                printf("Block 4 -> Chai Garam -> Block 1");
                break;

            case 12:
                printf("Block 4 -> Chai Garam -> Block 2 -> Block 3");
                break;

            case 3:
                printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                break;

            case 9:
                printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
                break;

            case 8:
                printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Boys Hostel");
                break;

            case 7:
                printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk -> Boys Hostel -> Girls Hostel");
                break;

            default:
                printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
        }
    }

    else if(start == 4)
    {
        switch(end)
        {
            case 13:
                printf("Chai Garam -> Block 4");
                break;

            case 11:
                printf("Chai Garam -> Block 2");
                break;

            case 10:
                printf("Chai Garam -> Block 1");
                break;

            case 12:
                printf("Chai Garam -> Block 2 -> Block 3");
                break;

            case 3:
                printf("Chai Garam -> Block 2 -> Block 3 -> Frisco");
                break;

            case 9:
                printf("Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
                break;

            case 21:
                printf("Chai Garam -> Block 4 -> Hubble");
                break;

            case 1:
                printf("Chai Garam -> Block 4 -> Hubble -> Main Gate");
                break;

            case 14:
                printf("Chai Garam -> Block 4 -> Block 5");
                break;

            default:
                printf("Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
        }
    }

    else if(start == 9)
    {
        switch(end)
        {
            case 3:
                printf("Gandhi Chowk -> Frisco");
                break;

            case 12:
                printf("Gandhi Chowk -> Frisco -> Block 3");
                break;

            case 11:
                printf("Gandhi Chowk -> Frisco -> Block 3 -> Block 2");
                break;

            case 4:
                printf("Gandhi Chowk -> Frisco -> Block 3 -> Block 2 -> Chai Garam");
                break;

            case 13:
                printf("Gandhi Chowk -> Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4");
                break;

            case 21:
                printf("Gandhi Chowk -> Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Hubble");
                break;

            case 1:
                printf("Gandhi Chowk -> Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Hubble -> Main Gate");
                break;

            case 15:
                printf("Gandhi Chowk -> Block 6");
                break;

            case 16:
                printf("Gandhi Chowk -> Block 6 -> Block 7");
                break;

            case 6:
                printf("Gandhi Chowk -> Team Orange");
                break;

            case 5:
                printf("Gandhi Chowk -> Tulip");
                break;

            case 22:
                printf("Gandhi Chowk -> Lab");
                break;

            case 8:
                printf("Gandhi Chowk -> Boys Hostel");
                break;

            case 7:
                printf("Gandhi Chowk -> Boys Hostel -> Girls Hostel");
                break;

            case 17:
                printf("Gandhi Chowk -> Block 8");
                break;

            case 18:
                printf("Gandhi Chowk -> Block 8 -> Block 9");
                break;

            case 19:
                printf("Gandhi Chowk -> Block 8 -> Block 9 -> Block 10");
                break;

            case 20:
                printf("Gandhi Chowk -> Block 8 -> Block 9 -> Block 10 -> Block 11");
                break;
        }
    }

    else if(start == 8)
    {
        switch(end)
        {
            case 7:
                printf("Boys Hostel -> Girls Hostel");
                break;

            case 9:
                printf("Boys Hostel -> Gandhi Chowk");
                break;

            case 5:
                printf("Boys Hostel -> Gandhi Chowk -> Tulip");
                break;

            case 6:
                printf("Boys Hostel -> Gandhi Chowk -> Team Orange");
                break;

            case 22:
                printf("Boys Hostel -> Gandhi Chowk -> Lab");
                break;

            case 3:
                printf("Boys Hostel -> Gandhi Chowk -> Frisco");
                break;

            case 1:
                printf("Boys Hostel -> Gandhi Chowk -> Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Hubble -> Main Gate");
                break;

            default:
                printf("Boys Hostel -> Gandhi Chowk");
        }
    }

    else if(start == 7)
    {
        switch(end)
        {
            case 8:
                printf("Girls Hostel -> Boys Hostel");
                break;

            case 9:
                printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk");
                break;

            case 5:
                printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk -> Tulip");
                break;

            case 6:
                printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk -> Team Orange");
                break;

            case 22:
                printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk -> Lab");
                break;

            case 1:
                printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk -> Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Hubble -> Main Gate");
                break;

            default:
                printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk");
        }
    }

    else
    {
        switch(start)
        {
            case 2:
                printf("Food Court -> Main Gate -> Hubble");
                break;

            case 3:
                printf("Frisco -> Gandhi Chowk");
                break;

            case 5:
                printf("Tulip -> Gandhi Chowk");
                break;

            case 6:
                printf("Team Orange -> Gandhi Chowk");
                break;

            case 10:
                printf("Block 1 -> Chai Garam");
                break;

            case 11:
                printf("Block 2 -> Chai Garam");
                break;

            case 12:
                printf("Block 3 -> Frisco -> Gandhi Chowk");
                break;

            case 14:
                printf("Block 5 -> Block 4");
                break;

            case 15:
                printf("Block 6 -> Gandhi Chowk");
                break;

            case 16:
                printf("Block 7 -> Block 6 -> Gandhi Chowk");
                break;

            case 17:
                printf("Block 8 -> Gandhi Chowk");
                break;

            case 18:
                printf("Block 9 -> Block 8 -> Gandhi Chowk");
                break;

            case 19:
                printf("Block 10 -> Block 9 -> Block 8 -> Gandhi Chowk");
                break;

            case 20:
                printf("Block 11 -> Block 10 -> Block 9 -> Block 8 -> Gandhi Chowk");
                break;

            case 22:
                printf("Lab -> Gandhi Chowk");
                break;
        }
    }

    printf("\n\n====================================");
    printf("\n        DESTINATION REACHED!");
    printf("\n====================================\n");

    return 0;
}