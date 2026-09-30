#include <stdio.h>

#define MAX 100
#define PHI_KHAM 150000
#define PHI_BHYT 30000

// Ham tinh phi kham cua mot benh nhan
int tinh_phi(int bhyt) {
    if (bhyt == 1) {
        return PHI_BHYT;
    }

    return PHI_KHAM;
}

// Ham in danh sach hang cho
void in_danh_sach(int so_thu_tu[], int tuoi[], int bhyt[], int n) {
    int tong_doanh_thu = 0;
    int tong_uu_tien = 0;

    printf("\n============================================================\n");
    printf("                    DANH SACH HANG CHO\n");
    printf("============================================================\n");

    if (n == 0) {
        printf("Hang cho dang rong.\n");
        printf("Tong doanh thu du kien: 0 VNĐ\n");
        printf("So benh nhan uu tien: 0\n");
        return;
    }

    printf("%-8s %-12s %-10s %-15s %-15s\n",
           "Index", "So thu tu", "Tuoi", "BHYT", "Phi kham");

    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        int phi = tinh_phi(bhyt[i]);

        printf("%-8d %-12d %-10d %-15s %-15d\n",
               i,
               so_thu_tu[i],
               tuoi[i],
               bhyt[i] == 1 ? "Co" : "Khong",
               phi);

        tong_doanh_thu += phi;

        if (tuoi[i] >= 70) {
            tong_uu_tien++;
        }
    }

    printf("------------------------------------------------------------\n");
    printf("Tong so benh nhan: %d\n", n);
    printf("Tong doanh thu du kien: %d VNĐ\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", tong_uu_tien);
}

// Ham xoa benh nhan tai index K bang cach don mang
void huy_luot_kham(int so_thu_tu[], int tuoi[], int bhyt[], int *n, int k) {
    if (*n == 0) {
        printf("\nLoi: Hang cho dang rong, khong the huy luot.\n");
        return;
    }

    if (k < 0 || k >= *n) {
        printf("\nLoi: Index K khong hop le.\n");
        printf("Index hop le: 0 den %d.\n", *n - 1);
        return;
    }

    printf("\nDa huy luot kham tai index %d - So thu tu %d.\n",
           k, so_thu_tu[k]);

    // Don cac phan tu phia sau sang trai
    for (int i = k; i < *n - 1; i++) {
        so_thu_tu[i] = so_thu_tu[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
    }

    // Giam so luong benh nhan active
    (*n)--;
}

int main() {
    int so_thu_tu[MAX];
    int tuoi[MAX];
    int bhyt[MAX];

    int n;

    printf("============================================================\n");
    printf("       HE THONG TIEP NHAN & XEP HANG MEDICARE\n");
    printf("============================================================\n");

    // Nhap so luong benh nhan
    do {
        printf("Nhap so luong benh nhan ban dau (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX) {
            printf("Loi: So luong phai nam trong khoang 0-%d.\n", MAX);
        }
    } while (n < 0 || n > MAX);

    // Nhap thong tin tung benh nhan
    for (int i = 0; i < n; i++) {
        printf("\n--- Benh nhan %d ---\n", i + 1);

        // Cap so thu tu tu dong
        so_thu_tu[i] = 1001 + i;

        printf("So thu tu: %d\n", so_thu_tu[i]);

        // Nhap tuoi va kiem tra
        do {
            printf("Nhap tuoi (1-120): ");
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Loi: Tuoi phai nam trong khoang 1-120.\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        // Nhap BHYT va kiem tra
        do {
            printf("Nhap BHYT (1 = Co, 0 = Khong): ");
            scanf("%d", &bhyt[i]);

            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("Loi: BHYT chi duoc nhap 0 hoac 1.\n");
            }
        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }

    // In danh sach ban dau
    printf("\n\n********** HANG CHO BAN DAU **********\n");
    in_danh_sach(so_thu_tu, tuoi, bhyt, n);

    // Nhap vi tri can huy
    if (n > 0) {
        int k;

        printf("\n============================================================\n");
        printf("                    HUY LUOT KHAM\n");
        printf("============================================================\n");

        printf("Nhap index K can huy (0-%d): ", n - 1);
        scanf("%d", &k);

        // Huy luot
        huy_luot_kham(so_thu_tu, tuoi, bhyt, &n, k);

        // In danh sach sau khi huy
        printf("\n\n********** HANG CHO SAU KHI HUY **********\n");
        in_danh_sach(so_thu_tu, tuoi, bhyt, n);
    } else {
        printf("\nHang cho rong, khong co luot de huy.\n");
    }

    return 0;
}