#ifndef SIPARIS_H
#define SIPARIS_H

typedef struct {
    int anahtar;
    char *ad;
    char *malzeme;
    char *renk;
} Siparis;

extern void siparis_yazdir(Siparis siparis);

#endif //SIPARIS_H
