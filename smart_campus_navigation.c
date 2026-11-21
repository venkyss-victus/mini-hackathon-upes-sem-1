/*
Smart Campus Navigation System

A graph-based campus navigation system that helps students find
the shortest route between different locations on campus.
*/

#include <stdio.h>

#define MAX 8
#define INF 99999

void showLocations();
void showMap();
void shortestPath(int graph[MAX][MAX], int start, int destination);
int minDistance(int distance[], int visited[]);

int main() {

    int graph[MAX][MAX] = {
        /* Gate AB1  AB2  Lib  Cafe Hostel Sports Parking */

        {0,  4,   6,   0,   0,   0,   0,   3},  // Main Gate
        {4,  0,   2,   3,   5,   0,   0,   0},  // Academic Block 1
        {6,  2,   0,   2,   0,   5,   0,   0},  // Academic Block 2
        {0,  3,   2,   0,   2,   0,   4,   0},  // Library
        {0,  5,   0,   2,   0,   3,   3,   0},  // Cafeteria
        {0,  0,   5,   0,   3,   0,   2,   0},  // Hostel
        {0,  0,   0,   4,   3,   2,   0,   4},  // Sports Area
        {3,  0,   0,   0,   0,   0,   4,   0}   // Parking
    };

    int choice;
    int start, destination;

    while (1) {

        printf("\n=====================================\n");
        printf("   SMART CAMPUS NAVIGATION SYSTEM\n");
        printf("        UPES BIDHOLI CAMPUS\n");
        printf("=====================================\n");

        printf("1. Show Campus Locations\n");
        printf("2. Show Campus Map\n");
        printf("3. Find Shortest Route\n");
        printf("4. Emergency Route to Main Gate\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                showLocations();
                break;

            case 2:

                showMap();
                break;

            case 3:

                showLocations();

                printf("\nEnter starting location number: ");
                scanf("%d", &start);

                printf("Enter destination location number: ");
                scanf("%d", &destination);

                if (start < 1 || start > MAX ||
                    destination < 1 || destination > MAX) {

                    printf("\nInvalid location!\n");

                } else if (start == destination) {

                    printf("\nYou are already at the destination!\n");

                } else {

                    shortestPath(graph, start - 1, destination - 1);
                }

                break;

            case 4:

                showLocations();

                printf("\nEnter your current location: ");
                scanf("%d", &start);

                if (start < 1 || start > MAX) {

                    printf("\nInvalid location!\n");

                } else if (start == 1) {

                    printf("\nYou are already at the Main Gate.\n");

                } else {

                    printf("\nFinding emergency route to Main Gate...\n");

                    shortestPath(graph, start - 1, 0);
                }

                break;

            case 5:

                printf("\nThank you for using Smart Campus Navigation!\n");
                printf("Have a great day at UPES!\n");

                return 0;

            default:

                printf("\nInvalid choice! Please try again.\n");
        }
    }
}


void showLocations() {

    printf("\n----------- CAMPUS LOCATIONS -----------\n");

    printf("1. Main Gate\n");
    printf("2. Academic Block 1\n");
    printf("3. Academic Block 2\n");
    printf("4. Library\n");
    printf("5. Cafeteria\n");
    printf("6. Hostel\n");
    printf("7. Sports Area\n");
    printf("8. Parking\n");
}


void showMap() {

    printf("\n------------- CAMPUS MAP -------------\n\n");

    printf("             [Main Gate]\n");
    printf("              /       \\\n");
    printf("             /         \\\n");
    printf("      [Parking]      [Academic 1]\n");
    printf("          |           /       \\\n");
    printf("          |      [Academic 2]  \\\n");
    printf("          |          |        [Library]\n");
    printf("          |          |          |\n");
    printf("      [Sports]----[Hostel]---[Cafeteria]\n");

    printf("\n--------------------------------------\n");
}


int minDistance(int distance[], int visited[]) {

    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < MAX; i++) {

        if (visited[i] == 0 && distance[i] < min) {

            min = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}


void shortestPath(int graph[MAX][MAX],
                  int start,
                  int destination) {

    char locations[MAX][30] = {
        "Main Gate",
        "Academic Block 1",
        "Academic Block 2",
        "Library",
        "Cafeteria",
        "Hostel",
        "Sports Area",
        "Parking"
    };

    int distance[MAX];
    int visited[MAX];
    int previous[MAX];

    for (int i = 0; i < MAX; i++) {

        distance[i] = INF;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[start] = 0;

    for (int count = 0; count < MAX - 1; count++) {

        int u = minDistance(distance, visited);

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < MAX; v++) {

            if (!visited[v] &&
                graph[u][v] != 0 &&
                distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];

                previous[v] = u;
            }
        }
    }

    if (distance[destination] == INF) {

        printf("\nNo route available!\n");
        return;
    }

    int path[MAX];
    int pathLength = 0;
    int current = destination;

    while (current != -1) {

        path[pathLength] = current;
        pathLength++;

        current = previous[current];
    }

    printf("\n=====================================\n");
    printf("          BEST ROUTE FOUND\n");
    printf("=====================================\n");

    printf("\nFrom : %s\n", locations[start]);
    printf("To   : %s\n", locations[destination]);

    printf("\nRoute:\n\n");

    for (int i = pathLength - 1; i >= 0; i--) {

        printf("%s", locations[path[i]]);

        if (i != 0)
            printf("  ->  ");
    }

    printf("\n\nTotal Distance: %d units\n",
           distance[destination]);

    printf("=====================================\n");
}