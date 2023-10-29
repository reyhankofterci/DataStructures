#include <stdio.h>
#include <stdlib.h>


/*1- Write a function that adds all odd numbers to the beginning of
the list and all even numbers to the end of the list until -1 is
entered from the keyboard */



// Düðüm yapýsý
struct Node {
    int value;
    struct Node* next;
};

// Yeni bir düðüm oluþturur
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// listenin baþýna tek sayýlarý ,listenin sonuna  çift sayýlarý ekleyen fonksiyon
void ekleTekCiftListeye(struct Node** head, int value)
{
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (value % 2 == 1)
    { // Tek sayý ise
        newNode->next = *head;
        *head = newNode;
    }
    else
    { // Çift sayý ise
            if (*head == NULL)
            { // Eðer liste boþsa
            *head = newNode;
            }
            else
            {
            struct Node* temp = *head;
                while (temp->next != NULL)
                {
                temp = temp->next;
                }
            temp->next = newNode;
            }
     }
}

// Liste içeriðini yazdýran fonksiyon
void printList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* liste = NULL;
    int sayi;

    printf("enter numbers(write -1 to stop): \n");
    while (1) {
        scanf("%d", &sayi);
        if (sayi == -1) {
            break;
        }
        ekleTekCiftListeye(&liste, sayi);
    }

    printList(liste);

    // Belleði temizle.
    while (liste != NULL) {
        struct Node* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}
