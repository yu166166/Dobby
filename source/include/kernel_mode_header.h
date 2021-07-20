#pragma once

#include <mach/mach_types.h>
#include <mach/mach_vm.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *vm_map_entry_t;
extern vm_map_t kernel_map;


typedef void * pmap_paddr_t;
struct pmap;
typedef struct pmap * pmap_t;
extern pmap_t kernel_pmap;

extern task_t kernel_task;

// ----- pmap -----

typedef uint64_t vaddr_t;
typedef uint64_t paddr_t;

struct pmap;
typedef struct pmap * pmap_t;

void pmap_kit_init();

paddr_t pmap_kit_kvtophys(pmap_t pmap, vaddr_t va);

int pmap_kit_set_perm(pmap_t pmap, vaddr_t start, vaddr_t end, unsigned int prot);

#define cppvPsnk 1
#define cppvPsrc 2
void pmap_kit_bcopy_phys(addr64_t src, addr64_t dst, size_t size, int flags);

uint64_t pmap_kit_kvtotte(pmap_t pmap, vaddr_t va);

#ifdef __cplusplus
}
#endif
