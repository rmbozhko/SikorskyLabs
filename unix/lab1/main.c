#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void            printFileSystemLinkedLimits() {
        printf("Значення границі %s дорівнює %ld\n", "_SC_ARG_MAX", sysconf(_SC_ARG_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_CHILD_MAX", sysconf(_SC_CHILD_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_HOST_NAME_MAX", sysconf(_SC_HOST_NAME_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_LOGIN_NAME_MAX", sysconf(_SC_LOGIN_NAME_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_NGROUPS_MAX", sysconf(_SC_NGROUPS_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_CLK_TCK", sysconf(_SC_CLK_TCK));
        printf("Значення границі %s дорівнює %ld\n", "_SC_OPEN_MAX", sysconf(_SC_OPEN_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_PAGESIZE", sysconf(_SC_PAGESIZE));
        printf("Значення границі %s дорівнює %ld\n", "_SC_RE_DUP_MAX", sysconf(_SC_RE_DUP_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_STREAM_MAX", sysconf(_SC_STREAM_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_SYMLOOP_MAX", sysconf(_SC_SYMLOOP_MAX));
        printf("Значення помилки: %s\n", strerror(errno));
        printf("Значення границі %s дорівнює %ld\n", "_SC_TTY_NAME_MAX", sysconf(_SC_TTY_NAME_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_TZNAME_MAX", sysconf(_SC_TZNAME_MAX));
        printf("Значення помилки: %s\n", strerror(errno));
        printf("Значення границі %s дорівнює %ld\n", "_SC_VERSION", sysconf(_SC_VERSION));
        printf("Значення границі %s дорівнює %ld\n", "_SC_BC_BASE_MAX", sysconf(_SC_BC_BASE_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_BC_DIM_MAX", sysconf(_SC_BC_DIM_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_BC_SCALE_MAX", sysconf(_SC_BC_SCALE_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_BC_STRING_MAX", sysconf(_SC_BC_STRING_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_COLL_WEIGHTS_MAX", sysconf(_SC_COLL_WEIGHTS_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_EXPR_NEST_MAX", sysconf(_SC_EXPR_NEST_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_LINE_MAX", sysconf(_SC_LINE_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_RE_DUP_MAX", sysconf(_SC_RE_DUP_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_SC_2_VERSION", sysconf(_SC_2_VERSION));
        printf("Значення границі %s дорівнює %ld\n", "_SC_2_C_DEV", sysconf(_SC_2_C_DEV));
        printf("Значення границі %s дорівнює %ld\n", "_SC_2_FORT_DEV", sysconf(_SC_2_FORT_DEV));
        printf("Значення помилки: %s\n", strerror(errno));
        printf("Значення границі %s дорівнює %ld\n", "_SC_2_FORT_RUN", sysconf(_SC_2_FORT_RUN));
        printf("Значення помилки: %s\n", strerror(errno));
        printf("Значення границі %s дорівнює %ld\n", "_SC_2_LOCALEDEF", sysconf(_SC_2_LOCALEDEF));
        printf("Значення границі %s дорівнює %ld\n", "_SC_2_SW_DEV", sysconf(_SC_2_SW_DEV));
}

void            printFileSystemUnLinkedLimits() {
        printf("Значення границі %s дорівнює %ld\n", "_PC_LINK_MAX", pathconf("/", _PC_LINK_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_PC_MAX_CANON", pathconf("/", _PC_MAX_CANON));
        printf("Значення границі %s дорівнює %ld\n", "_PC_MAX_INPUT", pathconf("/", _PC_MAX_INPUT));
        printf("Значення границі %s дорівнює %ld\n", "_PC_NAME_MAX", pathconf("/", _PC_NAME_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_PC_PATH_MAX", pathconf("/", _PC_PATH_MAX));
        printf("Значення границі %s дорівнює %ld\n", "_PC_PIPE_BUF", pathconf("/", _PC_PIPE_BUF));
        printf("Значення границі %s дорівнює %ld\n", "_PC_CHOWN_RESTRICTED", pathconf("/", _PC_CHOWN_RESTRICTED));
        printf("Значення границі %s дорівнює %ld\n", "_PC_NO_TRUNC", pathconf("/", _PC_NO_TRUNC));
        printf("Значення границі %s дорівнює %ld\n", "_PC_VDISABLE", pathconf("/", _PC_VDISABLE));
}

int             main(void) {
        printf("Значення всіх границь, що не пов'язані з файловою системою\n");
        printFileSystemLinkedLimits();

        printf("\nЗначення всіх границь, що пов'язані з файловою системою\n");
        printFileSystemUnLinkedLimits();

        return 0;
}
