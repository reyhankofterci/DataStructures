#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Write the function that deletes the next node
// from the node with the searched student name in the list.

// ��renci yap�s�
struct Ogrenci {
    char isim[50];
    struct Ogrenci* sonraki;
};

// Yeni ��renci d���m� olu�turan fonksiyon
struct Ogrenci* ogrenciOlustur(const char* isim) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->isim, isim);
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Yeni ��renci d���m�n� listenin ba��na ekleyen fonksiyon
struct Ogrenci* ogrenciEkle(struct Ogrenci* baslangic, const char* isim) {
    struct Ogrenci* yeniOgrenci = ogrenciOlustur(isim);
    yeniOgrenci->sonraki = baslangic;
    return yeniOgrenci;
}

// En uzun ismi ve uzunlu�unu bulan fonksiyon
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
        printf("Liste bo�.\n");
    }
}

int main() {
    struct Ogrenci* baslangic = NULL;
    int secim;

    while (1) {
        printf("1. �sim Ekle\n2. En Uzun �simli ��renciyi Bul\n3. ��k��\nSe�im: ");
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
                printf("Ge�ersiz se�im!\n");
                break;
        }
    }

    return 0;
}
