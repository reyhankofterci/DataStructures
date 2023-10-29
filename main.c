#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//3 - Output : 54->58->62->65->71->73->……102


// Öðrenci bilgisi saklayacak düðüm yapýsý
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Yeni bir öðrenci düðümü oluþturan iþlev
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Öðrenci listesini ekrana yazdýran iþlev
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
        printf("Öðrenci numarasý, adý ve yaþýný girin (bitirmek için -1 girin):\n");
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

    // Öðrenci listesini ekrana yazdýr
    ogrenciListesiniYazdir(baslangic);

    // Belleði temizle
    struct Ogrenci* current = baslangic;
    while (current != NULL) {
        struct Ogrenci* temp = current;
        current = current->sonraki;
        free(temp);
    }

    return 0;
}
