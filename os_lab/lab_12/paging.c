#include <stdio.h>

int main() {
    // 1) Define Data
    int np, nf, LA, PA;
    int pagenum, offset, framenum, pagesize;

    // 2) Accept data from user
    printf("Enter number of pages (np): ");
    scanf("%d", &np);
    
    printf("Enter number of frames (nf): ");
    scanf("%d", &nf);
    
    printf("Enter page size: ");
    scanf("%d", &pagesize);

    int PageTable[np];
    printf("\n--- Enter Page Table entries ---\n");
    for (int i = 0; i < np; i++) {
        printf("Enter frame number for Page %d: ", i);
        scanf("%d", &PageTable[i]);
        
        // Logical verification: Frame number shouldn't exceed total frames
        if (PageTable[i] >= nf || PageTable[i] < 0) {
            printf("  [!] Warning: Frame %d is out of bounds (should be 0 to %d).\n", PageTable[i], nf - 1);
        }
    }

    printf("\nEnter Logical Address (LA): ");
    scanf("%d", &LA);

    // 3) Find out PA corresponding to LA
    // a] pagenum = LA / pagesize
    pagenum = LA / pagesize;
    
    // b] offset = LA % pagesize
    offset = LA % pagesize;

    // Boundary Check (Not in notes, but necessary for correct execution)
    if (pagenum >= np || pagenum < 0) {
        printf("\nError: Logical address %d results in Page Number %d, which is outside the page table limit of %d.\n", LA, pagenum, np - 1);
        return 1; // Exit with error code
    }

    // c] Framenum = pagetable[pagenum]
    framenum = PageTable[pagenum];
    
    // d] PA = Framenum * pagesize + offset
    PA = (framenum * pagesize) + offset;

    // 4) Display data on screen
    printf("\n--- Address Translation Result ---\n");
    printf("Logical Address (LA) : %d\n", LA);
    printf("Page Size            : %d\n", pagesize);
    printf("Page Number          : %d\n", pagenum);
    printf("Offset               : %d\n", offset);
    printf("Frame Number         : %d\n", framenum);
    printf("Physical Address (PA): %d\n", PA);

    return 0;
}