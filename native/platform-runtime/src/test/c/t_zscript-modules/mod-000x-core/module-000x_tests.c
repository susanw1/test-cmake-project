#include <stdio.h>
#include <t_zscript-modules/all-modules_defs.h>

int main(void) {
    #if __STDC_VERSION__ == 201112L
        printf("C Standard: C11\n");
    #elif __STDC_VERSION__ == 199901L
        printf("C Standard: C99\n");
    #elif __STDC_VERSION__ == 201710L
        printf("C Standard: C17\n");
    #else
        printf("C Standard: Unknown\n");
    #endif

    module000xCore();
}
