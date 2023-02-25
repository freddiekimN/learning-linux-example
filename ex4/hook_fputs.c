#define _GNU_SOURCE

#include <dlfcn.h>
#include <link.h>
#include <stdio.h>
#include <stdlib.h>

static struct {
    ElfW(Addr) start, end;
} *segments;
static int n;
static int (*real_fputs)(const char *, FILE *);

static int callback(struct dl_phdr_info *info, size_t size, void *data) {
    n = info->dlpi_phnum;
    segments = malloc(n * sizeof *segments);
    for(int i = 0; i < n; ++i) {
        segments[i].start = info->dlpi_addr + info->dlpi_phdr[i].p_vaddr;
        segments[i].end = info->dlpi_addr + info->dlpi_phdr[i].p_vaddr + info->dlpi_phdr[i].p_memsz;
    }
    return 1;
}

__attribute__((__constructor__))
static void setup(void) {
    real_fputs = dlsym(RTLD_NEXT, "fputs");
    dl_iterate_phdr(callback, NULL);
}

__attribute__((__destructor__))
static void teardown(void) {
    free(segments);
}

__attribute__((__noinline__))
int fputs(const char *str, FILE *file) {
    ElfW(Addr) addr = (ElfW(Addr))__builtin_extract_return_addr(__builtin_return_address(0));
    for(int i = 0; i < n; ++i) {
        if(addr >= segments[i].start && addr < segments[i].end) {
            // Do Nothing
            return 0;
        }
    }
    return real_fputs(str, file);
}