#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Write the function that deletes the next node
// from the node with the searched student name in the list.

// Öðrenci yapýsý
struct Ogrenci {
    char isim[50];
    struct Ogrenci* sonraki;
};

// Yeni öðrenci düðümü oluþturan fonksiyon
struct Ogrenci* ogrenciOlustur(const char* isim) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->isim, isim);
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Yeni öðrenci düðümünü listenin baþýna ekleyen fonksiyon
struct Ogrenci* ogrenciEkle(struct Ogrenci* baslangic, const char* isim) {
    struct Ogrenci* yeniOgrenci = ogrenciOlustur(isim);
    yeniOgrenci->sonraki = baslangic;
    return yeniOgrenci;
}

// En uzun ismi ve uzunluðunu bulan fonksiyon
void enUzunIsimliOgrenciyiBul(const struct Ogrenci* baslangic) {
    const struct Ogrenci* gecici = baslangic;
    const char* enUzunIsim = NULL;
    size_t enUzunUzunluk = 0;

    while (gecici != NULL) {
        size_t uzunluk = strlen(gecici->isim);
        if (uzunluk > enUzunUzunluk) {
            enUzunUzunluk = uzunluk;
            enUzunIsim = gecici->isim;
        }
        gecici = gecici->sonraki;
    }

    if (enUzunIsim != NULL) {
        printf("En uzun isim: %s\n", enUzunIsim);
        printf("Uzunluk: %zu \n", enUzunUzunluk);
    } else {
        printf("Liste boþ.\n");
    }
}

int main() {
    struct Ogrenci* baslangic = NULL;
    int secim;

    while (1) {
        printf("1. Ýsim Ekle\n2. En Uzun Ýsimli Öðrenciyi Bul\n3. Çýkýþ\nSeçim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                char isim[1000];
                printf("isim: ");
                scanf("%s", isim);
                baslangic = ogrenciEkle(baslangic, isim);
                break;

            case 2:
                enUzunIsimliOgrenciyiBul(baslangic);
                break;

            case 3:
                exit(0);

            default:
                printf("Geçersiz seçim!\n");
                break;
        }
    }

    return 0;
}
