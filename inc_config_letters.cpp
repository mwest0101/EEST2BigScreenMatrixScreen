#include "inc_include.h"

#ifndef _INC_CONFIG_LETTERS_CPP_
#define _INC_CONFIG_LETTERS_CPP_

int *getCharMatrix(char character){
  static int * aChar;
  switch (character) {
    case 'A':aChar=convProgToArray(C_LET_A,(sizeof(C_LET_A)/2));break;
    case 'B':aChar=convProgToArray(C_LET_B,(sizeof(C_LET_B)/2));break;
    case 'C':aChar=convProgToArray(C_LET_C,(sizeof(C_LET_C)/2));break;
    case 'D':aChar=convProgToArray(C_LET_D,(sizeof(C_LET_D)/2));break;
    case 'E':aChar=convProgToArray(C_LET_E,(sizeof(C_LET_E)/2));break;
    case 'F':aChar=convProgToArray(C_LET_F,(sizeof(C_LET_F)/2));break;
    case 'G':aChar=convProgToArray(C_LET_G,(sizeof(C_LET_G)/2));break;
    case 'H':aChar=convProgToArray(C_LET_H,(sizeof(C_LET_H)/2));break;
    case 'I':aChar=convProgToArray(C_LET_I,(sizeof(C_LET_I)/2));break;
    case 'J':aChar=convProgToArray(C_LET_J,(sizeof(C_LET_J)/2));break;
    case 'K':aChar=convProgToArray(C_LET_K,(sizeof(C_LET_K)/2));break;
    case 'L':aChar=convProgToArray(C_LET_L,(sizeof(C_LET_L)/2));break;
    case 'M':aChar=convProgToArray(C_LET_M,(sizeof(C_LET_M)/2));break;
    case 'N':aChar=convProgToArray(C_LET_N,(sizeof(C_LET_N)/2));break;
    case 'ENIE':aChar=convProgToArray(C_LET_ENIE,(sizeof(C_LET_ENIE)/2));break;
    case 'O':aChar=convProgToArray(C_LET_O,(sizeof(C_LET_O)/2));break;
    case 'P':aChar=convProgToArray(C_LET_P,(sizeof(C_LET_P)/2));break;
    case 'Q':aChar=convProgToArray(C_LET_Q,(sizeof(C_LET_Q)/2));break;
    case 'R':aChar=convProgToArray(C_LET_R,(sizeof(C_LET_R)/2));break;
    case 'S':aChar=convProgToArray(C_LET_S,(sizeof(C_LET_S)/2));break;
    case 'T':aChar=convProgToArray(C_LET_T,(sizeof(C_LET_T)/2));break;
    case 'U':aChar=convProgToArray(C_LET_U,(sizeof(C_LET_U)/2));break;
    case 'V':aChar=convProgToArray(C_LET_V,(sizeof(C_LET_V)/2));break;
    case 'W':aChar=convProgToArray(C_LET_W,(sizeof(C_LET_W)/2));break;
    case 'Y':aChar=convProgToArray(C_LET_Y,(sizeof(C_LET_Y)/2));break;
    case 'Z':aChar=convProgToArray(C_LET_Z,(sizeof(C_LET_Z)/2));break;
    case 'a':aChar=convProgToArray(C_LET_a,(sizeof(C_LET_a)/2));break;
    case 'b':aChar=convProgToArray(C_LET_b,(sizeof(C_LET_b)/2));break;
    case 'c':aChar=convProgToArray(C_LET_c,(sizeof(C_LET_c)/2));break;
    case 'd':aChar=convProgToArray(C_LET_d,(sizeof(C_LET_d)/2));break;
    case 'e':aChar=convProgToArray(C_LET_e,(sizeof(C_LET_e)/2));break;
    case 'f':aChar=convProgToArray(C_LET_f,(sizeof(C_LET_f)/2));break;
    case 'g':aChar=convProgToArray(C_LET_g,(sizeof(C_LET_g)/2));break;
    case 'h':aChar=convProgToArray(C_LET_h,(sizeof(C_LET_h)/2));break;
    case 'i':aChar=convProgToArray(C_LET_i,(sizeof(C_LET_i)/2));break;
    case 'j':aChar=convProgToArray(C_LET_j,(sizeof(C_LET_j)/2));break;
    case 'k':aChar=convProgToArray(C_LET_k,(sizeof(C_LET_k)/2));break;
    case 'l':aChar=convProgToArray(C_LET_l,(sizeof(C_LET_l)/2));break;
    case 'm':aChar=convProgToArray(C_LET_m,(sizeof(C_LET_m)/2));break;
    case 'n':aChar=convProgToArray(C_LET_n,(sizeof(C_LET_n)/2));break;
    case 'enie':aChar=convProgToArray(C_LET_enie,(sizeof(C_LET_enie)/2));break;
    case 'o':aChar=convProgToArray(C_LET_o,(sizeof(C_LET_o)/2));break;
    case 'p':aChar=convProgToArray(C_LET_p,(sizeof(C_LET_p)/2));break;
    case 'q':aChar=convProgToArray(C_LET_q,(sizeof(C_LET_q)/2));break;
    case 'r':aChar=convProgToArray(C_LET_r,(sizeof(C_LET_r)/2));break;
    case 's':aChar=convProgToArray(C_LET_s,(sizeof(C_LET_s)/2));break;
    case 't':aChar=convProgToArray(C_LET_t,(sizeof(C_LET_t)/2));break;
    case 'u':aChar=convProgToArray(C_LET_u,(sizeof(C_LET_u)/2));break;
    case 'v':aChar=convProgToArray(C_LET_v,(sizeof(C_LET_v)/2));break;
    case 'w':aChar=convProgToArray(C_LET_w,(sizeof(C_LET_w)/2));break;
    case 'y':aChar=convProgToArray(C_LET_y,(sizeof(C_LET_y)/2));break;
    case 'z':aChar=convProgToArray(C_LET_z,(sizeof(C_LET_z)/2));break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
  return aChar;
}

#endif /* _INC_CONFIG_LETTERS_CPP_ */
