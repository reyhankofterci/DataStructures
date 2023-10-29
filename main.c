#include <stdio.h>
#include <string.h>

/*Write a function that stores the student number, name and age,
 traverses all the nodes in the list, writes all the student
 information on the screen and counts it.
The output should look like this on the screen:
1- Saliha 27 201
2- Ece 19 203
*/

struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
};

void ogrenciEkle(struct Ogrenci *ogrenciListesi, int *ogrenciSayisi, const char *ad, const char *soyad, int numara) {
    if (*ogrenciSayisi < 50) { // Maksimum 50 ��renci eklenebilir
        strcpy(ogrenciListesi[*ogrenciSayisi].ad, ad);
        strcpy(ogrenciListesi[*ogrenciSayisi].soyad, soyad);
        ogrenciListesi[*ogrenciSayisi].numara = numara;
        (*ogrenciSayisi)++;
    } else {
        printf("Maksimum ��renci say�s�na ula��ld�!\n");
    }
}

void ogrenciAra(const struct Ogrenci *ogrenciListesi, int ogrenciSayisi, const char *aranan_ad) {
    int bulunan = 0;

    for (int i = 0; i < ogrenciSayisi; i++) {
        if (strcmp(aranan_ad, ogrenciListesi[i].ad) == 0) {
            printf("Ad: %s, Soyad: %s, Numara: %d\n", ogrenciListesi[i].ad, ogrenciListesi[i].soyad, ogrenciListesi[i].numara);
            bulunan = 1;
        }
    }

    if (!bulunan) {
        printf("��renci bulunamad�.\n");
    }
}

int main() {
    struct Ogrenci ogrenciListesi[50];
    int ogrenciSayisi = 0;

    // ��renci ekleme k�sm�
    int secim;
    char ad[50], soyad[50];
    int numara;

    while (1) {
        printf("1. ��renci Ekle\n2. ��renci Ara\n3. ��k��\nSe�im: ");
        scanf("%d", &secim);

        if (secim == 1) {
            printf("Ad: ");
            scanf("%s", ad);
            printf("Soyad: ");
            scanf("%s", soyad);
            printf("Numara: ");
            scanf("%d", &numara);
            ogrenciEkle(ogrenciListesi, &ogrenciSayisi, ad, soyad, numara);
        } else if (secim == 2) {
            printf("Aranan ��renci Ad�: ");
            scanf("%s", ad);
            ogrenciAra(ogrenciListesi, ogrenciSayisi, ad);
        } else if (secim == 3) {
            break;
        } else {
            printf("Ge�ersiz se�im!\n");
        }
    }

    return 0;
}
