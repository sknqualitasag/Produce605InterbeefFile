#include <Rcpp.h>
#include "constant.h"

using namespace Rcpp;

//' ebv label for interbeef evaluation
const char CONSTANTS::EBV_LABEL[] = "CH";
// number of columns of rrtdm-pedigree
const unsigned CONSTANTS::NUM_COL_RRTDM = 11;
// number of columns of rrtdm-pedigree by missing informations
const unsigned CONSTANTS::NUM_COL_RRTDM_WITH_MISSING = 9;
//' missing value code as string
const char CONSTANTS::STRING_NA[] = "-9999";
//' missing value code as integer
const int CONSTANTS::INT_NA = -9999;
//' length of TVD-Nr in number of characters
const unsigned CONSTANTS::TVD_NR_LENGTH = 14;
//' length of ITB-Nr in number of characters
const unsigned CONSTANTS::ITB_NR_LENGTH = 19;
//' length of breed,country and sex code in ITB-NR
const unsigned CONSTANTS::BREED_COUNTRY_SEX_CODE_LENGTH = 7;
//' length of country code in TVD-NR
const unsigned CONSTANTS::COUNTRY_CODE_LENGTH = 2;
//' all letters in a string
const char CONSTANTS::LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//' string corresponding to debuging
const char CONSTANTS::DEBUG[] = "ja";
//' string corresponding to debuging all animal
const char CONSTANTS::DEBUGALL[] = "alle";
// string corresponding to running debug
const char CONSTANTS::RUNNING_DEBUG[] = "debug";
// string corresponding to running debug all animal
const char CONSTANTS::RUNNING_DEBUGALL[] = "alle";
// string corresponding to running routine
const char CONSTANTS::RUNNING_ROUTINE[] = "routine";
// string corresponding to breed Limouusin interbeef
const char CONSTANTS::LM_INTERBEEFBREED[] = "LM";
// string corresponding to breed Charolais interbeef
const char CONSTANTS::CH_INTERBEEFBREED[] = "CH";
// string corresponding to breed Simmental interbeef
const char CONSTANTS::SM_INTERBEEFBREED[] = "SI";
// string corresponding to breed Angus interbeef
const char CONSTANTS::AN_INTERBEEFBREED[] = "AN";
// string corresponding to breed Hereford interbeef
const char CONSTANTS::HH_INTERBEEFBREED[] = "HH";
//' min blood component of a breed
const unsigned CONSTANTS::MIN_BLOOD_CONTENT = 875;




