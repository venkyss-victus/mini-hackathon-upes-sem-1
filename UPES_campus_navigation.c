#include <stdio.h>

#define LOCATION_COUNT 36
#define LEGACY_COUNT 22

static const char *const location_names[LOCATION_COUNT] = {
    "Main Gate",
    "Food Court",
    "Frisco",
    "Chai Garam",
    "Tulip",
    "Team Orange",
    "Girls Hostel",
    "Boys Hostel",
    "Gandhi Chowk",
    "Block 1",
    "Block 2",
    "Block 3",
    "Block 4",
    "Block 5",
    "Block 6",
    "Block 7",
    "Block 8",
    "Block 9",
    "Block 10",
    "Block 11",
    "Hubble",
    "Lab",
    "Library",
    "IT Hub",
    "Lower Basketball",
    "Cricket Ground",
    "Enrollment Office",
    "MAC",
    "Containers",
    "Open Auditorium",
    "Paper Recycling",
    "Energy Department",
    "Volleyball Court",
    "Pickleball Court",
    "Hostel Basketball",
    "Guest Accommodation",
};

/* A 1 is a sample-map link; a 0 means no link. */
static const int weights[LOCATION_COUNT][LOCATION_COUNT] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Main Gate */
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Food Court */
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Frisco */
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Chai Garam */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Tulip */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Team Orange */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, /* Girls Hostel */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Boys Hostel */
    {0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, /* Gandhi Chowk */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 1 */
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 2 */
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, /* Block 3 */
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 4 */
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 5 */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 6 */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 7 */
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 8 */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Block 9 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, /* Block 10 */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, /* Block 11 */
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Hubble */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Lab */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, /* Library */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* IT Hub */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, /* Lower Basketball */
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, /* Cricket Ground */
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, /* Enrollment Office */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, /* MAC */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, /* Containers */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Open Auditorium */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Paper Recycling */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Energy Department */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Volleyball Court */
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, /* Pickleball Court */
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, /* Hostel Basketball */
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, /* Guest Accommodation */
};

static void show_sample_map(void)
{
    puts("-------------------------- CAMPUS MAP --------------------------");
    puts("");
    puts("                            [Main Gate]");
    puts("                          /      |       \\");
    puts("                         /       |        \\");
    puts("               [Food Court]   [Hubble]   [Enrollment Office]");
    puts("                   |             |              |");
    puts("                [Block 5]    [Block 1]        [MAC]");
    puts("                   |             |              |");
    puts("                [Block 4]    [Block 2]      [Containers]");
    puts("                   |          /    \\            |");
    puts("                [Frisco] [Block 3] [Chai Garam] [Library]");
    puts("");
    puts("Academic and connecting paths");
    puts("[Chai Garam]--[Frisco]--[Gandhi Chowk]");
    puts("[Food Court]--[Gandhi Chowk]");
    puts("[Food Court]--[Block 3]--[Open Auditorium]--[Block 10]");
    puts("[Block 3]--[Paper Recycling]");
    puts("[Block 3]--[Gandhi Chowk]");
    puts("[Block 10]--[Energy Department]--[Block 11]");
    puts("[Lab]--[IT Hub]");
    puts("Block 10 side: stairs down. Block 11 side: return road.");
    puts("");
    puts("                          [Gandhi Chowk]");
    puts("                                 |");
    puts("                                 +--[Tulip]");
    puts("                                 +--[Boys Hostel]");
    puts("                                 +--[Block 6]--[Library]--[IT Hub]");
    puts("                                 +--[Block 7]");
    puts("                                 +--[Block 8]--[Team Orange]");
    puts("                                 +--[Block 9]--[Block 10]--[Block 11]");
    puts("                                 `--[Lab]");
    puts("");
    puts("Sports paths");
    puts("[Library]--[Lower Basketball]--[Cricket Ground]--[Team Orange]");
    puts("Lower Basketball to Cricket Ground uses stairs.");
    puts("Guest Accommodation is a descriptive label.");
    puts("[Gandhi Chowk]--[Hostel Basketball]--[Guest Accommodation]--[Girls Hostel]");
    puts("[Hostel Basketball]--[Cricket Ground]");
    puts("Girls Hostel is to the left on the approach via Guest Accommodation.");
    puts("[Lower Basketball]");
    puts("        |");
    puts("        +--[Volleyball Court]");
    puts("        `--[Pickleball Court]");
    puts("");
    puts("Each link = 1 sample hop. Repeated names are the same stops.");
    puts("Schematic only. Links do not represent surveyed walking distances.");
    puts("----------------------------------------------------------------");
    putchar('\n');
}

static void show_locations(int limit)
{
    for (int i = 0; i < limit; ++i)
        printf("\n%d. %s", i + 1, location_names[i]);
    putchar('\n');
}

/* Consume the rest of the input line and check for extra characters. */
static int has_extra_input(void)
{
    int ch, extra = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\r')
            extra = 1;
    }
    return extra;
}

static int read_number(const char *prompt, int max)
{
    int number, result, extra;

    while (1) {
        printf("%s", prompt);
        result = scanf("%2d", &number);
        if (result == EOF)
            return 0;

        extra = has_extra_input();
        if (result == 1 && !extra && number >= 1 && number <= max)
            return number;

        printf("Enter a whole number from 1 to %d.\n", max);
    }
}

static int find_another_route(void)
{
    char answer;
    int extra;

    while (1) {
        printf("\nFind another route? (y/n): ");
        if (scanf(" %c", &answer) != 1)
            return 0;

        extra = has_extra_input();
        if (!extra && (answer == 'y' || answer == 'Y'))
            return 1;
        if (!extra && (answer == 'n' || answer == 'N'))
            return 0;

        puts("Please enter y or n.");
    }
}

static void print_route(int start, int end)
{
    printf("\n====================================\n");
    printf("            YOUR ROUTE\n");
    printf("====================================\n\n");

    switch(start)
    {
        case 1:
            switch(end)
            {
                case 2:
                    printf("Main Gate -> Food Court");
                    return;
                case 21:
                    printf("Main Gate -> Hubble");
                    return;
                case 14:
                    printf("Main Gate -> Hubble -> Block 5");
                    return;
                case 13:
                    printf("Main Gate -> Hubble -> Block 5 -> Block 4");
                    return;
                case 4:
                    printf("Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam");
                    return;
                case 10:
                    printf("Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 1");
                    return;
                case 11:
                    printf("Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
            }
            printf("Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 2:
            switch(end)
            {
                case 1:
                    printf("Food Court -> Main Gate");
                    return;
                case 21:
                    printf("Food Court -> Main Gate -> Hubble");
                    return;
                case 14:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5");
                    return;
                case 13:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4");
                    return;
                case 4:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam");
                    return;
                case 10:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 1");
                    return;
                case 11:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
            }
            printf("Food Court -> Main Gate -> Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 3:
            switch(end)
            {
                case 12:
                    printf("Frisco -> Block 3");
                    return;
                case 11:
                    printf("Frisco -> Block 3 -> Block 2");
                    return;
                case 10:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 1");
                    return;
                case 4:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam");
                    return;
                case 13:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4");
                    return;
                case 14:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5");
                    return;
                case 21:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
                case 9:
                    printf("Frisco -> Gandhi Chowk");
                    return;
            }
            printf("Frisco -> Gandhi Chowk");
            break;

        case 4:
            switch(end)
            {
                case 10:
                    printf("Chai Garam -> Block 1");
                    return;
                case 11:
                    printf("Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
                case 13:
                    printf("Chai Garam -> Block 4");
                    return;
                case 14:
                    printf("Chai Garam -> Block 4 -> Block 5");
                    return;
                case 21:
                    printf("Chai Garam -> Block 4 -> Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
            }
            printf("Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 5:
            printf("Tulip -> Gandhi Chowk");
            break;

        case 6:
            switch(end)
            {
                case 17:
                    printf("Team Orange -> Block 8");
                    return;
                case 9:
                    printf("Team Orange -> Block 8 -> Gandhi Chowk");
                    return;
            }
            printf("Team Orange -> Block 8 -> Gandhi Chowk");
            break;

        case 7:
            switch(end)
            {
                case 8:
                    printf("Girls Hostel -> Boys Hostel");
                    return;
                case 9:
                    printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk");
                    return;
            }
            printf("Girls Hostel -> Boys Hostel -> Gandhi Chowk");
            break;

        case 8:
            switch(end)
            {
                case 7:
                    printf("Boys Hostel -> Girls Hostel");
                    return;
                case 9:
                    printf("Boys Hostel -> Gandhi Chowk");
                    return;
            }
            printf("Boys Hostel -> Gandhi Chowk");
            break;

        case 9:
            printf("Gandhi Chowk");
            break;

        case 10:
            switch(end)
            {
                case 4:
                    printf("Block 1 -> Chai Garam");
                    return;
                case 11:
                    printf("Block 1 -> Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Block 1 -> Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Block 1 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
                case 13:
                    printf("Block 1 -> Chai Garam -> Block 4");
                    return;
                case 14:
                    printf("Block 1 -> Chai Garam -> Block 4 -> Block 5");
                    return;
                case 21:
                    printf("Block 1 -> Chai Garam -> Block 4 -> Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Block 1 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Block 1 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
            }
            printf("Block 1 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 11:
            switch(end)
            {
                case 4:
                    printf("Block 2 -> Chai Garam");
                    return;
                case 10:
                    printf("Block 2 -> Chai Garam -> Block 1");
                    return;
                case 12:
                    printf("Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Block 2 -> Block 3 -> Frisco");
                    return;
                case 13:
                    printf("Block 2 -> Chai Garam -> Block 4");
                    return;
                case 14:
                    printf("Block 2 -> Chai Garam -> Block 4 -> Block 5");
                    return;
                case 21:
                    printf("Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
            }
            printf("Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 12:
            switch(end)
            {
                case 3:
                    printf("Block 3 -> Frisco");
                    return;
                case 11:
                    printf("Block 3 -> Block 2");
                    return;
                case 4:
                    printf("Block 3 -> Block 2 -> Chai Garam");
                    return;
                case 10:
                    printf("Block 3 -> Block 2 -> Chai Garam -> Block 1");
                    return;
                case 13:
                    printf("Block 3 -> Block 2 -> Chai Garam -> Block 4");
                    return;
                case 14:
                    printf("Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5");
                    return;
                case 21:
                    printf("Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
            }
            printf("Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 13:
            switch(end)
            {
                case 4:
                    printf("Block 4 -> Chai Garam");
                    return;
                case 10:
                    printf("Block 4 -> Chai Garam -> Block 1");
                    return;
                case 11:
                    printf("Block 4 -> Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Block 4 -> Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
                case 14:
                    printf("Block 4 -> Block 5");
                    return;
                case 21:
                    printf("Block 4 -> Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Block 4 -> Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
            }
            printf("Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 14:
            switch(end)
            {
                case 13:
                    printf("Block 5 -> Block 4");
                    return;
                case 21:
                    printf("Block 5 -> Hubble");
                    return;
                case 1:
                    printf("Block 5 -> Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Block 5 -> Hubble -> Main Gate -> Food Court");
                    return;
                case 4:
                    printf("Block 5 -> Block 4 -> Chai Garam");
                    return;
                case 10:
                    printf("Block 5 -> Block 4 -> Chai Garam -> Block 1");
                    return;
                case 11:
                    printf("Block 5 -> Block 4 -> Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
            }
            printf("Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 15:
            switch(end)
            {
                case 16:
                    printf("Block 6 -> Block 7");
                    return;
                case 9:
                    printf("Block 6 -> Gandhi Chowk");
                    return;
            }
            printf("Block 6 -> Gandhi Chowk");
            break;

        case 16:
            switch(end)
            {
                case 15:
                    printf("Block 7 -> Block 6");
                    return;
                case 9:
                    printf("Block 7 -> Block 6 -> Gandhi Chowk");
                    return;
            }
            printf("Block 7 -> Block 6 -> Gandhi Chowk");
            break;

        case 17:
            switch(end)
            {
                case 6:
                    printf("Block 8 -> Team Orange");
                    return;
                case 9:
                    printf("Block 8 -> Gandhi Chowk");
                    return;
            }
            printf("Block 8 -> Gandhi Chowk");
            break;

        case 18:
            switch(end)
            {
                case 19:
                    printf("Block 9 -> Block 10");
                    return;
                case 20:
                    printf("Block 9 -> Block 10 -> Block 11");
                    return;
                case 9:
                    printf("Block 9 -> Gandhi Chowk");
                    return;
            }
            printf("Block 9 -> Gandhi Chowk");
            break;

        case 19:
            switch(end)
            {
                case 18:
                    printf("Block 10 -> Block 9");
                    return;
                case 20:
                    printf("Block 10 -> Block 11");
                    return;
                case 9:
                    printf("Block 10 -> Block 9 -> Gandhi Chowk");
                    return;
            }
            printf("Block 10 -> Block 9 -> Gandhi Chowk");
            break;

        case 20:
            switch(end)
            {
                case 19:
                    printf("Block 11 -> Block 10");
                    return;
                case 18:
                    printf("Block 11 -> Block 10 -> Block 9");
                    return;
                case 9:
                    printf("Block 11 -> Block 10 -> Block 9 -> Gandhi Chowk");
                    return;
            }
            printf("Block 11 -> Block 10 -> Block 9 -> Gandhi Chowk");
            break;

        case 21:
            switch(end)
            {
                case 1:
                    printf("Hubble -> Main Gate");
                    return;
                case 2:
                    printf("Hubble -> Main Gate -> Food Court");
                    return;
                case 14:
                    printf("Hubble -> Block 5");
                    return;
                case 13:
                    printf("Hubble -> Block 5 -> Block 4");
                    return;
                case 4:
                    printf("Hubble -> Block 5 -> Block 4 -> Chai Garam");
                    return;
                case 10:
                    printf("Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 1");
                    return;
                case 11:
                    printf("Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2");
                    return;
                case 12:
                    printf("Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3");
                    return;
                case 3:
                    printf("Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco");
                    return;
            }
            printf("Hubble -> Block 5 -> Block 4 -> Chai Garam -> Block 2 -> Block 3 -> Frisco -> Gandhi Chowk");
            break;

        case 22:
            switch(end)
            {
                case 9:
                    printf("Lab -> Gandhi Chowk");
                    return;
            }
            printf("Lab -> Gandhi Chowk");
            break;
    }

    if(end != 9)
    {
        printf(" -> ");

        switch(end)
        {
            case 1:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate");
                break;

            case 2:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble -> Main Gate -> Food Court");
                break;

            case 3:
                printf("Frisco");
                break;

            case 4:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam");
                break;

            case 5:
                printf("Tulip");
                break;

            case 6:
                printf("Block 8 -> Team Orange");
                break;

            case 7:
                printf("Boys Hostel -> Girls Hostel");
                break;

            case 8:
                printf("Boys Hostel");
                break;

            case 10:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 1");
                break;

            case 11:
                printf("Frisco -> Block 3 -> Block 2");
                break;

            case 12:
                printf("Frisco -> Block 3");
                break;

            case 13:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4");
                break;

            case 14:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5");
                break;

            case 15:
                printf("Block 6");
                break;

            case 16:
                printf("Block 6 -> Block 7");
                break;

            case 17:
                printf("Block 8");
                break;

            case 18:
                printf("Block 9");
                break;

            case 19:
                printf("Block 9 -> Block 10");
                break;

            case 20:
                printf("Block 9 -> Block 10 -> Block 11");
                break;
            case 21:
                printf("Frisco -> Block 3 -> Block 2 -> Chai Garam -> Block 4 -> Block 5 -> Hubble");
                break;

            case 22:
                printf("Lab");
                break;
        }
    }

    printf("\n\n====================================\n");
    printf("       DESTINATION REACHED!\n");
    printf("====================================\n");

    return;
}

/* Dijkstra uses the same undirected, one-unit links as the printed map. */
static void print_shortest_map_route(int start, int end)
{
    int distance[LOCATION_COUNT];
    int previous[LOCATION_COUNT];
    int visited[LOCATION_COUNT] = {0};
    int path[LOCATION_COUNT];
    int count = 0;
    const int infinity = LOCATION_COUNT + 1;

    for (int i = 0; i < LOCATION_COUNT; ++i) {
        distance[i] = infinity;
        previous[i] = -1;
    }

    --start;
    --end;
    distance[start] = 0;

    for (int step = 0; step < LOCATION_COUNT; ++step) {
        int current = -1;

        for (int i = 0; i < LOCATION_COUNT; ++i)
            if (!visited[i] && distance[i] < infinity &&
                (current == -1 || distance[i] < distance[current]))
                current = i;

        if (current == -1 || current == end)
            break;

        visited[current] = 1;
        for (int next = 0; next < LOCATION_COUNT; ++next) {
            if (!visited[next] && weights[current][next] != 0 &&
                distance[current] + weights[current][next] < distance[next]) {
                distance[next] = distance[current] + weights[current][next];
                previous[next] = current;
            }
        }
    }

    if (distance[end] == infinity) {
        puts("\nNo route is available on the sample map.");
        return;
    }

    for (int current = end; current != -1; current = previous[current])
        path[count++] = current;

    puts("\nSHORTEST ROUTE ON THE SAMPLE MAP (DIJKSTRA)");
    for (int i = count - 1; i >= 0; --i)
        printf("%s%s", location_names[path[i]], i ? " -> " : "\n");
    printf("Total: %d sample units\n", distance[end]);
}

int main(void)
{
    int start, end;

    puts("====================================");
    puts("     UPES CAMPUS NAVIGATION");
    puts("====================================");

    do {
        int mode, limit;

        puts("\n1. Shortest route on the corrected sample map (Dijkstra)");
        puts("2. Legacy preset route (may use old links)");
        mode = read_number("Choose route mode (1/2): ", 2);
        if (!mode) {
            putchar('\n');
            return 0;
        }
        if (mode == 1) {
            putchar('\n');
            show_sample_map();
        }

        limit = mode == 1 ? LOCATION_COUNT : LEGACY_COUNT;
        show_locations(limit);

        start = read_number("\nEnter starting location: ", limit);
        if (!start) {
            putchar('\n');
            return 0;
        }
        end = read_number("Enter destination: ", limit);
        if (!end) {
            putchar('\n');
            return 0;
        }

        if (start == end) {
            puts("\nYou are already at your destination!");
        } else if (mode == 1) {
            print_shortest_map_route(start, end);
        } else {
            print_route(start, end);
            putchar('\n');
        }
    } while (find_another_route());

    puts("\nGoodbye!");
    return 0;
}
