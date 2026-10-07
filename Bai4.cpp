#include <stdio.h>
#include <string.h>

struct HanhKhach {
    char maPNR[15];
    char hoTen[50];
    char hangVe[15];
    float canNangHanhLy;
    float phiHanhLy;
};

int main() {
    struct HanhKhach danhSach[100];
    int soLuong = 0;
    int choice;

    do {
        printf("=== HE THONG CHECK-IN HANG KHONG ===\n");
        printf("1. Them hanh khach check-in\n");
        printf("2. Hien thi danh sach hanh khach\n");
        printf("3. Cap nhat hanh ly theo ma PNR\n");
        printf("4. Thong ke chuyen bay\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                if (soLuong >= 100) {
                    printf("Bo nho day, khong the them hanh khach!\n");
                    break;
                }
                printf("Nhap ma PNR: ");
                scanf("%14s", danhSach[soLuong].maPNR);
                while (getchar() != '\n');

                printf("Nhap ho ten: ");
                fgets(danhSach[soLuong].hoTen, sizeof(danhSach[soLuong].hoTen), stdin);
                danhSach[soLuong].hoTen[strcspn(danhSach[soLuong].hoTen, "\n")] = '\0';

                printf("Nhap hang ve (Business/Deluxe/Eco): ");
                scanf("%14s", danhSach[soLuong].hangVe);
                while (getchar() != '\n');

                printf("Nhap so kg hanh ly ky gui: ");
                scanf("%f", &danhSach[soLuong].canNangHanhLy);
                while (getchar() != '\n');

                float kgMienPhi = 0.0;
                if (strcmp(danhSach[soLuong].hangVe, "Business") == 0) {
                    kgMienPhi = 30.0;
                } else if (strcmp(danhSach[soLuong].hangVe, "Deluxe") == 0) {
                    kgMienPhi = 20.0;
                } else {
                    kgMienPhi = 0.0;
                }

                float kgVuot = danhSach[soLuong].canNangHanhLy - kgMienPhi;
                if (kgVuot < 0) {
                    kgVuot = 0;
                }
                danhSach[soLuong].phiHanhLy = kgVuot * 50000.0;

                printf("Them hanh khach thanh cong! Phi hanh ly qua cuoc: %.0f VND\n", danhSach[soLuong].phiHanhLy);
                soLuong++;
                break;
            }
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }
                printf("-----------------------------------------------------------------------------------------\n");
                printf("| STT   | Ma PNR     | Ho va Ten                 | Hang ve      | Can nang       | Phi hanh ly        |\n");
                printf("-----------------------------------------------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    printf("| %-5d | %-10s | %-25s | %-12s | %-14.1f | %-18.0f |\n",
                           i + 1,
                           danhSach[i].maPNR,
                           danhSach[i].hoTen,
                           danhSach[i].hangVe,
                           danhSach[i].canNangHanhLy,
                           danhSach[i].phiHanhLy);
                }
                printf("-----------------------------------------------------------------------------------------\n");
                break;
            }
            case 3: {
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }
                char searchPNR[15];
                printf("Nhap ma PNR can cap nhat: ");
                scanf("%14s", searchPNR);
                while (getchar() != '\n');

                int foundIndex = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].maPNR, searchPNR) == 0) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    printf("Ma PNR khong ton tai trong he thong!\n");
                } else {
                    printf("Tim thay hanh khach: %s\n", danhSach[foundIndex].hoTen);
                    printf("Nhap so kg hanh ly ky gui moi: ");
                    scanf("%f", &danhSach[foundIndex].canNangHanhLy);
                    while (getchar() != '\n');

                    float kgMienPhi = 0.0;
                    if (strcmp(danhSach[foundIndex].hangVe, "Business") == 0) {
                        kgMienPhi = 30.0;
                    } else if (strcmp(danhSach[foundIndex].hangVe, "Deluxe") == 0) {
                        kgMienPhi = 20.0;
                    } else {
                        kgMienPhi = 0.0;
                    }

                    float kgVuot = danhSach[foundIndex].canNangHanhLy - kgMienPhi;
                    if (kgVuot < 0) {
                        kgVuot = 0;
                    }
                    danhSach[foundIndex].phiHanhLy = kgVuot * 50000.0;

                    printf("Cap nhat thanh cong! Phi hanh ly moi: %.0f VND\n", danhSach[foundIndex].phiHanhLy);
                }
                break;
            }
            case 4: {
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }
                int countBusiness = 0;
                float totalFee = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].hangVe, "Business") == 0) {
                        countBusiness++;
                    }
                    totalFee += danhSach[i].phiHanhLy;
                }
                printf("So luong hanh khach hang Business: %d\n", countBusiness);
                printf("Tong doanh thu phi hanh ly qua cuoc: %.0f VND\n", totalFee);
                break;
            }
            case 5:
                printf("Da thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
