
#ifdef USE_VPP
/* $::SYSECT = uc("FMT001A6"); ""; */
@@ $::SYSECT = uc("FMT001A6");"";@@
#endif
#include "FMT001A6.h"
/* Entry points are: fmt001a6 */
  int
fmt001a6(regs_t * p_regs);
void
fmtbbb2_FMT001A6();

/* End of declarations */

#include "FMT001A6_init.h"

int
fmt001a6(regs_t * p_regs)
{
  regs = *p_regs;
  exit_flag = 0;
/*  <ENTRY POINT>  */
  wds2 = (wds2_t *) regs.r6;
  wds1 = (wds1_t *) regs.r5;
/*  <NAME=FMT001A6>  */
/*   SAMPLE PROGRAM WITH MULTIPLE ENTRY POINTS DEFINED BY A USER MACRO */
/* SET CALLING PARAMETER */
/* CALL MODULE */
  regs.r4 = *(FWORD *) regs.r1;
  *(FWORD *) regs.r4 = *(FWORD *) test1a;
  *(FWORD *) (regs.r4 + 4) = *(FWORD *) test1b;
  result_code = fmt401();
  regs.r15 = result_code;
  exit_flag = 0;
  return (regs.r15);
}

/* ************************************************************ */

void
fmtbbb2_FMT001A6()
{
/*        <FERMAT><SB><9><============================================> */
/* SET CALLING PARAMETER */
  regs.r4 = *(FWORD *) regs.r1;
  *(FWORD *) regs.r4 = *(FWORD *) test2;
  regs.r5 = (FWORD) wtab1;
  wds1 = (wds1_t *) regs.r5;
  regs.r6 = (FWORD) wrec2;
  wds2 = (wds2_t *) regs.r6;
  for (;;) {                    /* DO loop 1 */
    if (*wds1->wds1f1 == 0xFF) {
      break;
    } else {
      *(FWORD *) wds2->wds2f1 = *(FWORD *) wds1->wds1f1;
      memmove(wds2->wds2f2, wds1->wds1f2, 6);
      memmove(wds2->wds2f3, wds1->wds1f3, 3);
      memmove(wds2->wds2f4, wds1->wds1f4, 3);
      result_code = fmt402(wrec2);
      regs.r15 = result_code;
    }
  }                             /* OD */
/* was: CALL dispatch */
  return;
}

/* ************************************************************ */
