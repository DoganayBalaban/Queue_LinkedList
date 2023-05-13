#include <stdio.h>
#include <stdlib.h>

// Kuyruk yapısı
struct Node {
    int veri;
    struct Node* sonraki;
};

struct Node* bas = NULL;
struct Node* son = NULL;

// Eleman ekleme işlemi
void ekle(int veri) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->veri = veri;
    yeni->sonraki = NULL;

    if (son == NULL) {
        bas = yeni;
        son = yeni;
        return;
    }

    son->sonraki = yeni;
    son = yeni;
}

// Eleman silme işlemi
void sil() {
    if (bas == NULL)
        return;

    struct Node* temp = bas;
    bas = bas->sonraki;

    if (bas == NULL)
        son = NULL;

    free(temp);
}

// Kuyruktaki elemanları yazdırma işlemi
void goruntule() {
    struct Node* temp = bas;
    if (temp == NULL)
        printf("Kuyruk bos\n");
    else {
        while (temp != NULL) {
            printf("%d ", temp->veri);
            temp = temp->sonraki;
        }
        printf("\n");
    }
}

int main() {
    int secim, veri;

    while (1) {
        printf("1. Eleman ekle\n");
        printf("2. Eleman sil\n");
        printf("3. Kuyruktaki elemanlari goster\n");
        printf("4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek veri: ");
                scanf("%d", &veri);
                ekle(veri);
                break;
            case 2:
                sil();
                break;
            case 3:
                goruntule();
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim\n");
        }
    }

    return 0;
}
