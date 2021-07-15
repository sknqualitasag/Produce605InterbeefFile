#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "juldate.h"

#define IGREG (15 + 31L * (10 + 12L * 1582))


long julDate(string yyyy, string mm, string dd){

  int year, month, day;
  if(yyyy != "-9999" && mm != "-9999" && dd != "-9999" ){
    //        cout<<yyyy<<" "<<mm<<" "<<dd<<endl;
    if(yyyy.size() != 4) return -9999;

    year = atoi(yyyy.c_str());                //Converting to integer


    month = atoi(mm.c_str());               //Converting to integer
    if(month>12 || month<1) return -9999;

    day = atoi(dd.c_str());                  //Converting to integer
    if(day>31 || day<1) return -9999;

    long int jul;
    int ja, jy=year,jm;
    if(jy == 0) {
      cout<<"ERROR in jul_date: There is no year 0, setting date to missing \n";
      return(-9999);
    }
    if(jy < 0) ++jy;
    if(month > 2) {
      jm = month+1;
    }
    else{
      --jy;
      jm = month + 13;
    }

    jul = (long) (floor(365.25*jy) + floor(30.6001*jm) + day + 1720995);
    if(day + 31L * (month + 12L * year) >= IGREG) {
      ja = (int)(0.01*jy);
      jul += 2 - ja + (int) (0.25*ja);
    }
    //        cout<<jul<<endl;
    return(jul);

  }
  else return(-9999);
};

long julDate1(string yyyymmdd){

  int year, month, day;

  string yyyy = yyyymmdd.substr(0,4);
  string mm = yyyymmdd.substr(4,2);
  string dd = yyyymmdd.substr(6,2);

  if(yyyy != "-9999" && mm != "-9999" && dd != "-9999" ){
    if(yyyy.size() != 4) return -9999;

    year = atoi(yyyy.c_str());                //Converting to integer


    month = atoi(mm.c_str());               //Converting to integer
    if(month>12 || month<1) return -9999;

    day = atoi(dd.c_str());                  //Converting to integer
    if(day>31 || day<1) return -9999;

    long int jul;
    int ja, jy=year,jm;
    if(jy == 0) {
      cout<<"ERROR in jul_date: There is no year 0, setting date to missing \n";
      return(-9999);
    }
    if(jy < 0) ++jy;
    if(month > 2) {
      jm = month+1;
    }
    else{
      --jy;
      jm = month + 13;
    }

    jul = (long) (floor(365.25*jy) + floor(30.6001*jm) + day + 1720995);
    if(day + 31L * (month + 12L * year) >= IGREG) {
      ja = (int)(0.01*jy);
      jul += 2 - ja + (int) (0.25*ja);
    }
    //       cout<<jul<<endl;
    return(jul);

  }
  else return(-9999);
};
