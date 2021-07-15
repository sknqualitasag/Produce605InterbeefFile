//
//
//   Header for global constants
//

#ifndef Const_h
#define Const_h


class CONSTANTS {
public:
  //' ebv label for interbeef evaluation
  static const char EBV_LABEL[];
  //' number of columns of rrtdm-pedigree
  static const unsigned NUM_COL_RRTDM;
  //' number of columns of rrtdm-pedigree by missing informations
  static const unsigned NUM_COL_RRTDM_WITH_MISSING;
  // string corresponding to missing value code
  static const char STRING_NA[];
  //' missing value code as integer
  static const int INT_NA;
  // length of TVD-Nr in number of characters
  static const unsigned TVD_NR_LENGTH;
  //' length of ITB-Nr in number of characters
  static const unsigned ITB_NR_LENGTH;
  //' length of breed,country and sex code in ITB-NR
  static const unsigned BREED_COUNTRY_SEX_CODE_LENGTH;
  // number of characters that correspond to the country code
  static const unsigned COUNTRY_CODE_LENGTH;
  // string that corresponds to all letters
  static const char LETTERS[];
  // string corresponding to debuging
  static const char DEBUG[];
  //' string corresponding to debuging all animal
  static const char DEBUGALL[];
  // string corresponding to running debug
  static const char RUNNING_DEBUG[];
  // string corresponding to running debug all animal
  static const char RUNNING_DEBUGALL[];
  // string corresponding to running routine
  static const char RUNNING_ROUTINE[];
  // string corresponding to breed Limouusin interbeef
  static const char LM_INTERBEEFBREED[];
  // string corresponding to breed Charolais interbeef
  static const char CH_INTERBEEFBREED[];
  // string corresponding to breed Simmental interbeef
  static const char SM_INTERBEEFBREED[];
  // string corresponding to breed Angus interbeef
  static const char AN_INTERBEEFBREED[];
  // string corresponding to breed Hereford interbeef
  static const char HH_INTERBEEFBREED[];
  //' min blood component of a breed
  static const unsigned MIN_BLOOD_CONTENT;








};

#endif
