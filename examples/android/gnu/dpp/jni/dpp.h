/*****************************************************************************
* Model: dpp.qm
* File:  ./dpp.h
*
* This file has been generated automatically by QP Modeler (QM).
* DO NOT EDIT THIS FILE MANUALLY.
*
* Please visit www.state-machine.com/qm for more information.
*****************************************************************************/
#ifndef dpp_h
#define dpp_h

enum DPPSignals {
    EAT_SIG = Q_USER_SIG, /* published by Table to let a philosopher eat */
    DONE_SIG,             /* published by Philosopher when done eating */
    PAUSE_SIG,            /* published by BSP to pause the application */
    TERMINATE_SIG,        /* published by BSP to terminate the application */
    MAX_PUB_SIG,          /* the last published signal */

    HUNGRY_SIG,           /* posted direclty to Table from hungry Philo */
    MAX_SIG               /* the last signal */
};

/* @(/1/0) .................................................................*/
typedef struct TableEvtTag {
/* protected: */
    QEvt super;

/* public: */
    uint8_t philoNum;
} TableEvt;


/* number of philosophers */
#define N_PHILO ((uint8_t)5)


/* @(/2/4) .................................................................*/
void Philo_ctor(void);

/* @(/2/5) .................................................................*/
void Table_ctor(void);

int main(int argc, char *argv[]);

extern QActive * const AO_Philo[N_PHILO];
extern QActive * const AO_Table;

#endif                    /* dpp_h */
