#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//3 - Output : 54->58->62->65->71->73->��102


// ��renci bilgisi saklayacak d���m yap�s�
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Yeni bir ��renci d���m� olu�turan i�lev
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// ��renci listesini ekrana yazd�ran i�lev
void ogrenciListesiniYazdir(struct Ogrenci* baslangic) {
    struct Ogrenci* current = baslangic;
    int sayac = 1;

    while (current != NULL) {
        printf("%d-%s %d %d\n", current->numara, current->isim, current->yas, sayac);
        current = current->sonraki;
        sayac++;
    }
}

int main() {
    struct Ogrenci* baslangic = NULL;
    struct Ogrenci* son = NULL;
    int numara, yas;
    char isim[50];
    int sayac = 1;

    while (1) {
        printf("��renci numaras�, ad� ve ya��n� girin (bitirmek i�in -1 girin):\n");
        scanf("%d", &numara);

        if (numara == -1) {
            break;
        }

        scanf("%s %d", isim, &yas);

        struct Ogrenci* ogrenci = yeniOgrenci(numara, isim, yas);

        if (baslangic == NULL) {
            baslangic = ogrenci;
            son = ogrenci;
        } else {
            son->sonraki = ogrenci;
            son = ogrenci;
        }
    }

    // ��renci listesini ekrana yazd�r
    ogrenciListesiniYazdir(baslangic);

    // Belle�i temizle
    struct Ogrenci* current = baslangic;
    while (current != NULL) {
        struct Ogrenci* temp = current;
        current = current->sonraki;
        free(temp);
    }

    return 0;
}
