#include <stdlib.h>
#include <stdio.h>
#include <komut.h>
#include <mem.h>

#define TAMPON_BOYUTU 256

char **bolum_dizisi_olustur();

int main() {
    char tampon[TAMPON_BOYUTU];
    Islem kayit = islem_olustur();
    enum Komut islem;

    do {
        printf("> ");

        if (fgets(tampon, sizeof(tampon), stdin) == NULL) {
            perror("Konsol girdisi okunamiyor.");
            exit(1);
        }

        size_t len = strlen(tampon);
        if (len < 1) {
            perror("Bos giris yapildi.");
            exit(1);
        }

        /* Sondaki satır sonu karakteri silinir. */
        if (tampon[len - 1] == '\n') tampon[len - 1] = '\0';

        char **bolumler = bolum_dizisi_olustur();
        int bolumSayisi;
        int hataKodu = girdiyi_cozumle(tampon, kayit, bolumler, &bolumSayisi, &islem);
        if (hataKodu != 0) {
            hata_mesaji_yazdir(hataKodu);
            printf("\n");
            continue;
        }

        Siparis *siparis;
        switch (islem) {
            case SIPARIS_EKLE:
                islem_siparis_ekle(kayit, bolumler[1], bolumler[2], bolumler[3], bolumler[4]);
                break;
            case SIPARIS_EKLE_DOSYADAN:
                break;
            case SIPARIS_ARA:
                islem_siparis_ara(kayit, strtol(bolumler[1], NULL, 10), &siparis);
                siparis_yazdir(*siparis);
                break;
            case SIPARIS_YAZDIR:
                break;
            case SIPARIS_YAZDIR_DOSYAYA:
                break;
            case CIKIS:
                break;
        }
    } while (islem != CIKIS);

    islem_yoket(kayit);

    exit(0);
}

char **bolum_dizisi_olustur() {
    char **bolumler;

    bolumler = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; ++i) {
        bolumler[i] = malloc(sizeof(char) * TAMPON_BOYUTU);
    }

    return bolumler;
}