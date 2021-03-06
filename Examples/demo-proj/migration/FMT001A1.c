
#ifdef USE_VPP
/* $::SYSECT = uc("FMT001A1"); ""; */
@@ $::SYSECT = uc("FMT001A1");"";@@
#endif
#include "FMT001A1.h"
/* Entry points are: fmt001a1 */
  int
fmt001a1(regs_t * p_regs);
void
getrec_FMT001A1_p();

FILE *
  ddin;
FILE *
  rdsout;
#define ddin_status V_DDIN_STATUS
extern FWORD
  ddin_status;
                            /* FIXME: This variable was not in the ll file */

/* End of declarations */

#include "FMT001A1_init.h"

int
fmt001a1(regs_t * p_regs)
{
  regs = *p_regs;
  exit_flag = 0;
/*  <ENTRY POINT>  */
/*  <NAME=FMT001A1>  */
/* ********************************************************************* */
/*        <FERMAT><ML><0><> */
/*        <FERMAT><ML><0><> */
/*        <FERMAT><ML><0><> */
/* */
  OPEN(ddin, "INPUT", &result_code);
  OPEN(rdsout, "OUTPUT", &result_code);
/* READ FIRST RECORD */
  getrec_FMT001A1_p();
  if (exit_flag == 1) {
    exit_flag = 0;
    return (regs.r15);
  }
  for (;;) {                    /* DO loop 1 */
                                         /* STORE INDEX WORD IN PRINT LINE */
                            /* Execute instruction successfully processed: */
                                             /* <EXEC TARGET 162: 230 230> */
    memmove(wprt, (BYTE *) regs.r4, (regs.r5 + 1));
/* *WMVC1   MVC   WPRT(1),0(R4) */
                                                     /* ADDRESS PRINT LINE */
                                                         /* SKIP OVER WORD */
    regs.r8 = ((FWORD) wprt + regs.r5 + 2);
    for (;;) {                  /* DO loop 2 */
                                                      /* STORE PAGE NUMBER */
                            /* Execute instruction successfully processed: */
                                             /* <EXEC TARGET 169: 231 231> */
      memmove((BYTE *) regs.r8, (BYTE *) regs.r6, (regs.r7 + 1));
/* *WMVC2   MVC   0(1,R8),0(R6) */
                                                 /* INDEX OVER PAGE NUMBER */
      regs.r8 = (regs.r7 + regs.r8 + 1);
                                                        /* STORE LAST WORD */
                            /* Execute instruction successfully processed: */
                                             /* <EXEC TARGET 172: 232 232> */
      memmove(wlast, wrec, (regs.r5 + 1));
/* *WMVC3   MVC   WLAST(1),WREC */
                                                       /* READ NEXT RECORD */
      getrec_FMT001A1_p();
      if (exit_flag == 1) {
        goto LOOP_EXIT_1;
      }
                                                   /* INDEX WORD CHANGED ? */
                            /* Execute instruction successfully processed: */
                                             /* <EXEC TARGET 151: 229 229> */
/* *WCLC1   CLC   WLAST(1),0(R4) */
                                                                    /* NO. */
      if (memcmp(wlast, (BYTE *) regs.r4, (regs.r5 + 1))) {
        break;
      } else {
                                                          /* ADD SEPARATOR */
        *(BYTE *) regs.r8 = ',';
                                                   /* INDEX OVER SEPARATOR */
        regs.r8++;
      }
    }                           /* OD */
                                                 /* YES - WRITE PRINT LINE */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File min for RDSOUT */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File min for RDSOUT */
    PUT_FIXED(rdsout, wprt, &result_code);
                                                       /* CLEAR PRINT LINE */
    memset(wprt, ' ', 80);
  }                             /* OD */
LOOP_EXIT_1:;
  exit_flag = 0;
  return (regs.r15);
}

/* ************************************************************ */

void
getrec_FMT001A1_p()
{
/* */
/* READ RECORD */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File min for DDIN  */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File min for DDIN  */
/* FIXME: Unknown File max for DDIN  */
/* FIXME: Unknown File min for DDIN  */
  GET_FIXED(ddin, wrec, &result_code);
  regs.r15 = ddin_status;
  if (end_of_file(ddin)) {
/* */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File min for RDSOUT */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File max for RDSOUT */
                                     /* FIXME: Unknown File min for RDSOUT */
    PUT_FIXED(rdsout, wprt, &result_code);
    CLOSE(ddin, &result_code);
    CLOSE(rdsout, &result_code);
/* */
/*        <FERMAT><ML><0><> */
    exit_flag = 1;
  } else {
                                                          /* START OF WORD */
    regs.r4 = (FWORD) wrec;
    regs.r5 = (FWORD) wrec;
    for (;;) {                  /* DO loop 3 */
                                                        /* SEPARATOR (,) ? */
                                                                   /* YES. */
      if (*(BYTE *) regs.r5 == ',') {
        break;
      } else {
                                                   /* INDEX NEXT CHARACTER */
        regs.r5++;
      }
    }                           /* OD */
                                              /* SAVE START OF PAGE NUMBER */
    regs.r7 = (regs.r5 + 1);
                                                         /* LENGTH OF WORD */
    regs.r5 -= (FWORD) wrec;
                                                  /* DECREMENT FOR EXECUTE */
                                                   /* START OF PAGE NUMBER */
    regs.r6 = regs.r7;
    for (;;) {                  /* DO loop 4 */
                                                                  /* END ? */
                                                                   /* YES. */
      if (*(BYTE *) regs.r7 == ' ') {
        break;
      } else {
                                                   /* INDEX NEXT CHARACTER */
        regs.r7++;
      }
    }                           /* OD */
                                                  /* LENGTH OF PAGE NUMBER */
    regs.r7 -= regs.r6;
                                                  /* DECREMENT FOR EXECUTE */
    regs.r5--;
    regs.r7--;
                                                                 /* RETURN */
    exit_flag = 0;
  }
  return;
}

/* ************************************************************ */
