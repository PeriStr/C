#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

typedef struct Product {
    char description[50];
    double price;
    int item_count;
} Product;

typedef struct Order {
    int product_id;
    int client_id;
} Order;

void initializeCatalog(Product catalog[]);
void processOrder(Product catalog[], int clientSocket);
void printReport(Product catalog[]);

int main() {
    Product catalog[20];
    initializeCatalog(catalog);

    // Create socket
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size = sizeof(struct sockaddr_in);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Fork for each client
    for (int i = 0; i < 5; i++) {
        if (fork() == 0) {
            // Child process code
            srand(time(NULL) ^ getpid());
            clientSocket = accept(serverSocket, (struct 
                      sockaddr*)&clientAddr, &addr_size);

            for (int j = 0; j < 10; j++) {
                sleep(1);
                Order order;
                order.product_id = rand() % 20;
                order.client_id = i;

                // Sending the order to the parent process (E-shop)
                write(clientSocket, &order, sizeof(Order));

                // Process order
                processOrder(catalog, clientSocket);
            }

            close(clientSocket);
            exit(0);
        }
    }

    // Parent process code
    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    // Close the server socket
    close(serverSocket);

    // Print the report
    printReport(catalog);

    return 0;
}

void initializeCatalog(Product catalog[]) {
    // Initialize the catalog with products
    for (int i = 0; i < 20; i++) {
        sprintf(catalog[i].description, "Product %d", i + 1);
        catalog[i].price = (float)(rand() % 20 + 1);
        catalog[i].item_count = 2;
    }
}

void processOrder(Product catalog[], int clientSocket) {
    Order order;
    read(clientSocket, &order, sizeof(Order));

    int result = 0;
    if (catalog[order.product_id].item_count > 0) {
        // Update the catalog
        result = 1;
        catalog[order.product_id].item_count--;
    } else {
        printf("Product %d out of stock\n", order.product_id);
    }

    // Results of the order
    write(clientSocket, &result, sizeof(int));
}

void printReport(Product catalog[]) {
    // Loop for printing the report
    for (int i = 0; i < 20; i++) {
        printf("Product: %s\n", catalog[i].description);
        printf("Requests: %d\n", 2 * 5 * 10);
        printf("Sold items: %d\n", 2 * 5 * 10 - catalog[i].item_count);
        printf("Users not served: \n");
        if (catalog[i].item_count < 0) {
            printf("%d\n", -catalog[i].item_count);
        }
    }

    // Calculate the total sales
    int totalOrders = 2 * 5 * 10;
    int successfulOrders = 2 * 5 * 10 - catalog[0].item_count;
    int failedOrders = catalog[0].item_count < 0 ? -catalog[0].item_count : 0;
    double totalRevenue = 0;

    for (int i = 0; i < 20; i++) {
        totalRevenue = totalRevenue + (2 * 5 * 10 - catalog[i].item_count) * catalog[i].price;
    }

    // Final report of the sales
    printf("Total Orders: %d\n", totalOrders);
    printf("Successful Orders: %d\n", successfulOrders);
    printf("Failed Orders: %d\n", failedOrders);
    printf("Total Revenue: %.2f\n", totalRevenue);
}
