//
// Created by CBunt on 11/20/2019.
//

#include "DBtester.h"

int DBtester::test(){
    int RetInt = 0;
    time_t rawtime;
    struct tm *ptm;
    time(&rawtime);
    ptm = gmtime(&rawtime);
    FILE *log;
    log = fopen("TEST.LOG","w");
    ChocAnDB *DB;
    fprintf(log, "TESTING CHOCAN DATABASE: %02d:%02d:%02d\n", (ptm->tm_hour)%24, ptm->tm_min, ptm->tm_sec);
    DB = new ChocAnDB(RetInt);
    if (RetInt == 0){
        fprintf(log,"PASSED DATABASE FILE OPENED: %02d:%02d:%02d\n", (ptm->tm_hour)%24, ptm->tm_min, ptm->tm_sec);
    }
    else
        fprintf(log,"FAILED DATABASE FILE OPENED: %02d:%02d:%02d\t ERRORCODE: \n", (ptm->tm_hour)%24, ptm->tm_min, ptm->tm_sec, RetInt);
    delete DB;
    fprintf(log, "TEST COMPLETE: %02d:%02d:%02d\n", (ptm->tm_hour)%24, ptm->tm_min, ptm->tm_sec);
    fclose(log);
    return 0;
}
