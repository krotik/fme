#include <assem.h>

/* EQUates table */



/* Files */



static struct {
/*           --> CSECT: CSECT001 <-- */
  BYTE  __FILLER_csect001_0001[136];
  FWORD __wsave[18];
  BYTE  __wprt[80];
/*COUNT*/
  DECIMAL(4, __wct);
/*NO OF CREDIT TRANS*/
  DECIMAL(4, __wnum);
/*AMOUNT*/
  DECIMAL(4, __wtotal);

/* CSECT #defines */
#define FILLER_csect001_0001 local.__FILLER_csect001_0001
#define wsave local.__wsave
#define wprt local.__wprt
#define wct local.__wct
#define wnum local.__wnum
#define wtotal local.__wtotal
} __attribute__((packed)) local;


/*           --> EXPORTED DATA <-- */
int fmt001a2(regs_t * p_regs);
FWORD V_FMT001A2 = (FWORD)&fmt001a2;

