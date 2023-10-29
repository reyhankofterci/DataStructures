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

// Yeni öðrenci düðümü oluþturan fonksiyon
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
// Öðrenci düðümlerini ekleme fonksiyonu
struct Ogrenci *ogrenciEkle(struct Ogrenci *baslangic, const char *ad, const char *soyad, int numara) {
    struct Ogrenci *yeniOgrenci = ogrenciOlustur(ad, soyad, numara);
    yeniOgrenci->sonraki = baslangic;
    return yeniOgrenci;
}

// Verilen adý taþýyan öðrencinin bir sonraki düðümünü silen fonksiyon
struct Ogrenci *ogrenciSil(struct Ogrenci *baslangic, const char *aranan_ad) {
    struct Ogrenci *gecici = baslangic;
    struct Ogrenci *onceki = NULL;

    while (gecici != NULL) {
        if (strcmp(aranan_ad, gecici->ad) == 0) {
            if (onceki == NULL) {
                // Baþlangýç düðümünü deðiþtir
                baslangic = gecici->sonraki;
            } else {
                // Önceki düðümün sonraki iþaretçisini güncelle
                onceki->sonraki = gecici->sonraki;
            }
            free(gecici); // Belleði serbest býrak
            printf("%s adlý öðrencinin sonraki düðümü silindi.\n", aranan_ad);
            return baslangic;
        }

        onceki = gecici;
        gecici = gecici->sonraki;
    }

    printf("%s adlý öðrenci bulunamadý.\n", aranan_ad);
    return baslangic;
}

int main() {
    struct Ogrenci *baslangic = NULL;
    int ogrenciSayisi;
    char ad[50], soyad[50];
    int numara;
    int secim;

    while (1) {
        printf("1. Öðrenci Ekle\n2. Öðrenci Sil\n3. Liste Göster\n4. Çýkýþ\nSeçim: ");
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
                printf("Silmek istediðiniz öðrencinin adýný girin: ");
                scanf("%s", ad);
                baslangic = ogrenciSil(baslangic, ad);
                break;

            case 3:
                printf("Öðrenci Listesi:\n");
                listeGoster(baslangic);
                break;

            case 4:
                exit(0);

            default:
                printf("Geçersiz seçim!\n");
                break;
        }
    }

    return 0;
}
