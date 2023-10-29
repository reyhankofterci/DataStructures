#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//5 Write the function that searches records by student name in the list


struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
    struct Ogrenci *sonraki;
};

// Yeni ��renci d���m� olu�turan fonksiyon
struct Ogrenci *ogrenciOlustur(const char *ad, const char *soyad, int numara) {
    struct Ogrenci *ogrenci = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->ad, ad);
    strcpy(ogrenci->soyad, soyad);
    ogrenci->numara = numara;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

void listeGoster(const struct Ogrenci *baslangic) {
    const struct Ogrenci *gecici = baslangic;
    while (gecici != NULL) {
        printf("Ad: %s, Soyad: %s, Numara: %d\n", gecici->ad, gecici->soyad, gecici->numara);
        gecici = gecici->sonraki;
    }
}
// ��renci d���mlerini ekleme fonksiyonu
struct Ogrenci *ogrenciEkle(struct Ogrenci *baslangic, const char *ad, const char *soyad, int numara) {
    struct Ogrenci *yeniOgrenci = ogrenciOlustur(ad, soyad, numara);
    yeniOgrenci->sonraki = baslangic;
    return yeniOgrenci;
}

// Verilen ad� ta��yan ��rencinin bir sonraki d���m�n� silen fonksiyon
struct Ogrenci *ogrenciSil(struct Ogrenci *baslangic, const char *aranan_ad) {
    struct Ogrenci *gecici = baslangic;
    struct Ogrenci *onceki = NULL;

    while (gecici != NULL) {
        if (strcmp(aranan_ad, gecici->ad) == 0) {
            if (onceki == NULL) {
                // Ba�lang�� d���m�n� de�i�tir
                baslangic = gecici->sonraki;
            } else {
                // �nceki d���m�n sonraki i�aret�isini g�ncelle
                onceki->sonraki = gecici->sonraki;
            }
            free(gecici); // Belle�i serbest b�rak
            printf("%s adl� ��rencinin sonraki d���m� silindi.\n", aranan_ad);
            return baslangic;
        }

        onceki = gecici;
        gecici = gecici->sonraki;
    }

    printf("%s adl� ��renci bulunamad�.\n", aranan_ad);
    return baslangic;
}

int main() {
    struct Ogrenci *baslangic = NULL;
    int ogrenciSayisi;
    char ad[50], soyad[50];
    int numara;
    int secim;

    while (1) {
        printf("1. ��renci Ekle\n2. ��renci Sil\n3. Liste G�ster\n4. ��k��\nSe�im: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Ad: ");
                scanf("%s", ad);
                printf("Soyad: ");
                scanf("%s", soyad);
                printf("Numara: ");
                scanf("%d", &numara);
                baslangic = ogrenciEkle(baslangic, ad, soyad, numara);
                break;

            case 2:
                printf("Silmek istedi�iniz ��rencinin ad�n� girin: ");
                scanf("%s", ad);
                baslangic = ogrenciSil(baslangic, ad);
                break;

            case 3:
                printf("��renci Listesi:\n");
                listeGoster(baslangic);
                break;

            case 4:
                exit(0);

            default:
                printf("Ge�ersiz se�im!\n");
                break;
        }
    }

    return 0;
}
