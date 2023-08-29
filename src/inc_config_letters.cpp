#include "inc_include.h"

#ifndef _INC_CONFIG_LETTERS_CPP_
#define _INC_CONFIG_LETTERS_CPP_

int *getCharMatrix(String character){
  static int * aChar;
  
  if(character=="A"){aChar=convProgToArray(C_LET_A,1,(sizeof(C_LET_A)/2));}
  if(character=="B"){aChar=convProgToArray(C_LET_B,1,(sizeof(C_LET_B)/2));}
  if(character=="C"){aChar=convProgToArray(C_LET_C,1,(sizeof(C_LET_C)/2));}
  if(character=="D"){aChar=convProgToArray(C_LET_D,1,(sizeof(C_LET_D)/2));}
  if(character=="E"){aChar=convProgToArray(C_LET_E,1,(sizeof(C_LET_E)/2));}
  if(character=="F"){aChar=convProgToArray(C_LET_F,1,(sizeof(C_LET_F)/2));}
  if(character=="G"){aChar=convProgToArray(C_LET_G,1,(sizeof(C_LET_G)/2));}
  if(character=="H"){aChar=convProgToArray(C_LET_H,1,(sizeof(C_LET_H)/2));}
  if(character=="I"){aChar=convProgToArray(C_LET_I,1,(sizeof(C_LET_I)/2));}
  if(character=="J"){aChar=convProgToArray(C_LET_J,1,(sizeof(C_LET_J)/2));}
  if(character=="K"){aChar=convProgToArray(C_LET_K,1,(sizeof(C_LET_K)/2));}
  if(character=="L"){aChar=convProgToArray(C_LET_L,1,(sizeof(C_LET_L)/2));}
  if(character=="M"){aChar=convProgToArray(C_LET_M,1,(sizeof(C_LET_M)/2));}
  if(character=="N"){aChar=convProgToArray(C_LET_N,1,(sizeof(C_LET_N)/2));}
  if(character=="Ñ"){aChar=convProgToArray(C_LET_ENIE,1,(sizeof(C_LET_ENIE)/2));}
  if(character=="O"){aChar=convProgToArray(C_LET_O,1,(sizeof(C_LET_O)/2));}
  if(character=="P"){aChar=convProgToArray(C_LET_P,1,(sizeof(C_LET_P)/2));}
  if(character=="Q"){aChar=convProgToArray(C_LET_Q,1,(sizeof(C_LET_Q)/2));}
  if(character=="R"){aChar=convProgToArray(C_LET_R,1,(sizeof(C_LET_R)/2));}
  if(character=="S"){aChar=convProgToArray(C_LET_S,1,(sizeof(C_LET_S)/2));}
  if(character=="T"){aChar=convProgToArray(C_LET_T,1,(sizeof(C_LET_T)/2));}
  if(character=="U"){aChar=convProgToArray(C_LET_U,1,(sizeof(C_LET_U)/2));}
  if(character=="V"){aChar=convProgToArray(C_LET_V,1,(sizeof(C_LET_V)/2));}
  if(character=="W"){aChar=convProgToArray(C_LET_W,1,(sizeof(C_LET_W)/2));}
  if(character=="Y"){aChar=convProgToArray(C_LET_Y,1,(sizeof(C_LET_Y)/2));}
  if(character=="Z"){aChar=convProgToArray(C_LET_Z,1,(sizeof(C_LET_Z)/2));}
  if(character=="a"){aChar=convProgToArray(C_LET_a,1,(sizeof(C_LET_a)/2));}
  if(character=="b"){aChar=convProgToArray(C_LET_b,1,(sizeof(C_LET_b)/2));}
  if(character=="c"){aChar=convProgToArray(C_LET_c,1,(sizeof(C_LET_c)/2));}
  if(character=="d"){aChar=convProgToArray(C_LET_d,1,(sizeof(C_LET_d)/2));}
  if(character=="e"){aChar=convProgToArray(C_LET_e,1,(sizeof(C_LET_e)/2));}
  if(character=="f"){aChar=convProgToArray(C_LET_f,1,(sizeof(C_LET_f)/2));}
  if(character=="g"){aChar=convProgToArray(C_LET_g,1,(sizeof(C_LET_g)/2));}
  if(character=="h"){aChar=convProgToArray(C_LET_h,1,(sizeof(C_LET_h)/2));}
  if(character=="i"){aChar=convProgToArray(C_LET_i,1,(sizeof(C_LET_i)/2));}
  if(character=="j"){aChar=convProgToArray(C_LET_j,1,(sizeof(C_LET_j)/2));}
  if(character=="k"){aChar=convProgToArray(C_LET_k,1,(sizeof(C_LET_k)/2));}
  if(character=="l"){aChar=convProgToArray(C_LET_l,1,(sizeof(C_LET_l)/2));}
  if(character=="m"){aChar=convProgToArray(C_LET_m,1,(sizeof(C_LET_m)/2));}
  if(character=="n"){aChar=convProgToArray(C_LET_n,1,(sizeof(C_LET_n)/2));}
  if(character=="ñ"){aChar=convProgToArray(C_LET_enie,1,(sizeof(C_LET_enie)/2));}
  if(character=="o"){aChar=convProgToArray(C_LET_o,1,(sizeof(C_LET_o)/2));}
  if(character=="p"){aChar=convProgToArray(C_LET_p,1,(sizeof(C_LET_p)/2));}
  if(character=="q"){aChar=convProgToArray(C_LET_q,1,(sizeof(C_LET_q)/2));}
  if(character=="r"){aChar=convProgToArray(C_LET_r,1,(sizeof(C_LET_r)/2));}
  if(character=="s"){aChar=convProgToArray(C_LET_s,1,(sizeof(C_LET_s)/2));}
  if(character=="t"){aChar=convProgToArray(C_LET_t,1,(sizeof(C_LET_t)/2));}
  if(character=="u"){aChar=convProgToArray(C_LET_u,1,(sizeof(C_LET_u)/2));}
  if(character=="v"){aChar=convProgToArray(C_LET_v,1,(sizeof(C_LET_v)/2));}
  if(character=="w"){aChar=convProgToArray(C_LET_w,1,(sizeof(C_LET_w)/2));}
  if(character=="y"){aChar=convProgToArray(C_LET_y,1,(sizeof(C_LET_y)/2));}
  if(character=="z"){aChar=convProgToArray(C_LET_z,1,(sizeof(C_LET_z)/2));}
  if(character=="1"){aChar=convProgToArray(C_LET_1,1,(sizeof(C_LET_1)/2));}
  if(character=="2"){aChar=convProgToArray(C_LET_2,1,(sizeof(C_LET_2)/2));}
  if(character=="3"){aChar=convProgToArray(C_LET_3,1,(sizeof(C_LET_3)/2));}
  if(character=="4"){aChar=convProgToArray(C_LET_4,1,(sizeof(C_LET_4)/2));}
  if(character=="5"){aChar=convProgToArray(C_LET_5,1,(sizeof(C_LET_5)/2));}
  if(character=="6"){aChar=convProgToArray(C_LET_6,1,(sizeof(C_LET_6)/2));}
  if(character=="7"){aChar=convProgToArray(C_LET_7,1,(sizeof(C_LET_7)/2));}
  if(character=="8"){aChar=convProgToArray(C_LET_8,1,(sizeof(C_LET_8)/2));}
  if(character=="9"){aChar=convProgToArray(C_LET_9,1,(sizeof(C_LET_9)/2));}
  if(character=="0"){aChar=convProgToArray(C_LET_0,1,(sizeof(C_LET_0)/2));}
  if(character==" "){aChar=convProgToArray(C_LET_ESP,1,(sizeof(C_LET_ESP)/2));}
  
  return aChar;
}


#endif /* _INC_CONFIG_LETTERS_CPP_ */
