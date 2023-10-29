#include <stdio.h>
#include <stdlib.h>

/*2
- Add 100 randomly generated numbers to the list, write the
c code that sorts all the numbers entered from largest to
smallest and prints them on the screen.*/



// D���m yap�s�
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir d���m olu�turur
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Liste i�eri�ini yazd�ran fonksiyon
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// D���m� s�ral� bir �ekilde liste i�ine ekleyen fonksiyon
void siraliEkle(struct Node** head, int value) {
    struct Node* new_node = newNode(value);

    if (*head == NULL || value > (*head)->data) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    struct Node* list = NULL;
    int sayi;
    int i;

    // Rastgele 100 say�y� liste i�ine ekle
    for (i = 0; i < 100; i++) {
        sayi = rand() % 100; // 0 ile 999 aras�nda rastgele bir say� �retir
        siraliEkle(&list, sayi);
    }

    // S�ralanm�� liste i�eri�ini ekrana yazd�r�r
    printf(":");
    printList(list);

    // Belle�i temizle
    while (list != NULL) {
        struct Node* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
