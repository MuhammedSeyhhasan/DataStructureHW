
/// Soru 1 -
//Tek ve çift sayıları listeye ekleyen fonksiyon
void addNumbers(struct Node** head)
{
    int num;
    while (1) {
        printf("Bir sayi girin (Cikis icin -1): ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        struct Node* newNodePtr = newNode(num);

        if (num % 2 == 1) {
            /// Tek sayıları listenin başına ekler
            newNodePtr->next = *head;
            *head = newNodePtr;
        } else {
            /// Çift sayıları listenin sonuna ekler
            if (*head == NULL) {
                *head = newNodePtr;
            } else {
                struct Node* temp = *head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNodePtr;
            }
        }
    }
}
///////////////////////////////////

/// soru 2 -
// Karşılaştırma fonksiyonu sıralama işlemi için kullanılır
int karsilastir(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

int main() {
    int sayilar[100];

    // Rastgele sayılarla diziye değer atama
    for (int i = 0; i < 100; i++) {
        sayilar[i] = rand() % 1000;  // 0 ile 999 arasında rastgele sayılar
    }

    // Diziyi büyükten küçüğe sıralama
    qsort(sayilar, 100, sizeof(int), karsilastir);

    // Sıralanmış diziyi ekrana basma
    printf("siralanmis Sayilar: \n");
    for (int i = 0; i < 100; i++) {
        printf("%d\n", sayilar[i]);

    }
    printf("\n");

    return 0;
}
///////////////////////////////////



///soru 3 -
// Öğrenci bilgilerini temsil eden bağlı liste düğümü
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Yeni öğrenci düğümü oluşturma
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Bağlı liste üzerinde dolaşıp öğrenci bilgilerini yazdıran ve sayan fonksiyon
void ogrenciBilgileriniYazdirVeSay(struct Ogrenci* baslangic) {
    struct Ogrenci* current = baslangic;
    int ogrenciSayisi = 0;

    while (current != NULL) {
        printf("%d- Numara: %d, Isim: %s, Yas: %d\n", ogrenciSayisi + 1, current->numara, current->isim, current->yas);
        current = current->sonraki;
        ogrenciSayisi++;
    }

    printf("Toplam Ogrenci Sayisi: %d\n", ogrenciSayisi);
}
///////////////////////////////////




///soru 4 -
// Öğrenci adına göre kayıt arama
struct Ogrenci* ogrenciAra(struct Ogrenci* baslangic, const char* arananIsim) {
    struct Ogrenci* temp = baslangic;

    while (temp != NULL) {
        if (strcmp(temp->isim, arananIsim) == 0) {
            return temp; // İstenen öğrenciyi bulduk
        }
        temp= temp->sonraki;
    }

    return NULL; // İstenen öğrenci bulunamadı
}
///////////////////////////////////




/// soru 5 -
// Öğrenci adına göre düğüm silme
void ogrenciSil(struct Ogrenci* baslangic, const char* silinecekIsim) {
    struct Ogrenci* temp = baslangic;
    struct Ogrenci* onceki = NULL;

    while (temp != NULL) {
        if (strcmp(temp->isim, silinecekIsim) == 0) {
            if (temp->sonraki != NULL) {
                // Aranan düğümün sonraki düğümü siliniyor
                struct Ogrenci* silinecek = temp->sonraki;
                temp->sonraki = silinecek->sonraki;
                free(silinecek);
                printf("%s isimli ogrencinin sonraki kaydi silindi.\n", silinecekIsim);
            } else {
                printf("%s isimli ogrencinin sonraki kaydi bulunamadi.\n", silinecekIsim);
            }
            return;
        }
        temp= temp->sonraki;
    }

    printf("%s isimli ogrenci bulunamadi.\n", silinecekIsim);
}
///////////////////////////////////





///soru 6 -
// Bağlı liste en uzun ismi bulan fonksiyon
void enUzunIsimliOgrenci(struct Ogrenci* baslangic) {
    struct Ogrenci* current = baslangic;
    char enUzunIsim[50] = "";
    int enUzunUzunluk = 0;

    while (current != NULL) {
        int uzunluk = strlen(current->isim);
        if (uzunluk > enUzunUzunluk) {
            enUzunUzunluk = uzunluk;
            strcpy(enUzunIsim, current->isim);
        }
        current = current->sonraki;
    }

    if (enUzunUzunluk > 0) {
        printf("Listedeki en uzun isim: %s\nUzunluk: %d\n", enUzunIsim, enUzunUzunluk);
    } else {
        printf("Listede ismi olan ogrenci bulunamadi.\n");
    }
}
///////////////////////////////////

