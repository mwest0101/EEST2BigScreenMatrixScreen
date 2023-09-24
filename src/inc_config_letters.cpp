
#include <Arduino.h>
#include "inc_include.h"
#ifndef _INC_CONFIG_LETTERS_CPP_
#define _INC_CONFIG_LETTERS_CPP_
int calcNumberOfChar(char caracter){
    int charVal=0;
    int valRet=0;
    int valorCaracter = (int)caracter;  // Convertir el car�cter a su valor num�rico
    if (valorCaracter==-61){
        charVal=valorCaracter;
        valRet=0;
    }else if(valorCaracter<0){
        charVal+=valorCaracter;
        valRet=charVal;
        charVal=0;
    }else{
      charVal=valorCaracter;
      valRet=charVal;
    }

       if(valRet>122){
      ds("Letter=--------------------------------------------------");
      ds("Letter=Error valRet");
      ds("Letter=valRet=");
      dsl(valRet);
    }
    /*
    if(valRet!=0){
      dsl(" ");
      ds("Letter=[");
      ds(caracter);
      ds("Letter= (");
      ds(valRet);
      ds("Letter=) ]");
      //charVal=0;
    }*/
    return valRet;
}
//____________________________________________________________________
//------------Function------------------------------------------------
void getCharMatrix(VectorClass &aIntCharMatrix,int character){
  //VectorClass aChar(VECTOR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  dsl("");
  ds("getCharMatrix | Letter=:");
  ds(character);
  dsl("  ");
  //delay(1000);
  
    switch (character){
      case 32:     convProgToArray(aIntCharMatrix,C_LET_ESP,(sizeof(C_LET_ESP)/2));dsl("Letter=_");break; //' ' Espacio
      case 48:     convProgToArray(aIntCharMatrix,C_LET_0,(sizeof(C_LET_0)/2));dsl("Letter=0");break; //'0'
      case 49:     convProgToArray(aIntCharMatrix,C_LET_1,(sizeof(C_LET_1)/2));dsl("Letter=1");break; //'1'
      case 50:     convProgToArray(aIntCharMatrix,C_LET_2,(sizeof(C_LET_2)/2));dsl("Letter=2");break; //'2'
      case 51:     convProgToArray(aIntCharMatrix,C_LET_3,(sizeof(C_LET_3)/2));dsl("Letter=3");break; //'3'
      case 52:     convProgToArray(aIntCharMatrix,C_LET_4,(sizeof(C_LET_4)/2));dsl("Letter=4");break; //'4'
      case 53:     convProgToArray(aIntCharMatrix,C_LET_5,(sizeof(C_LET_5)/2));dsl("Letter=5");break; //'5'
      case 54:     convProgToArray(aIntCharMatrix,C_LET_6,(sizeof(C_LET_6)/2));dsl("Letter=6");break; //'6'
      case 55:     convProgToArray(aIntCharMatrix,C_LET_7,(sizeof(C_LET_7)/2));dsl("Letter=7");break; //'7'
      case 56:     convProgToArray(aIntCharMatrix,C_LET_8,(sizeof(C_LET_8)/2));dsl("Letter=8");break; //'8'
      case 57:     convProgToArray(aIntCharMatrix,C_LET_9,(sizeof(C_LET_9)/2));dsl("Letter=9");break; //'9'
      case 65:     convProgToArray(aIntCharMatrix,C_LET_A,(sizeof(C_LET_A)/2));dsl("Letter=A");break; //'A'
      case 66:     convProgToArray(aIntCharMatrix,C_LET_B,(sizeof(C_LET_B)/2));dsl("Letter=B");break; //'B'
      case 67:     convProgToArray(aIntCharMatrix,C_LET_C,(sizeof(C_LET_C)/2));dsl("Letter=C");break; //'C'
      case 68:     convProgToArray(aIntCharMatrix,C_LET_D,(sizeof(C_LET_D)/2));dsl("Letter=D");break; //'D'
      case 69:     convProgToArray(aIntCharMatrix,C_LET_E,(sizeof(C_LET_E)/2));dsl("Letter=E");break; //'E'
      case 70:     convProgToArray(aIntCharMatrix,C_LET_F,(sizeof(C_LET_F)/2));dsl("Letter=F");break; //'F'
      case 71:     convProgToArray(aIntCharMatrix,C_LET_G,(sizeof(C_LET_G)/2));dsl("Letter=G");break; //'G'
      case 72:     convProgToArray(aIntCharMatrix,C_LET_H,(sizeof(C_LET_H)/2));dsl("Letter=H");break; //'H'
      case 73:     convProgToArray(aIntCharMatrix,C_LET_I,(sizeof(C_LET_I)/2));dsl("Letter=I");break; //'I'
      case 74:     convProgToArray(aIntCharMatrix,C_LET_J,(sizeof(C_LET_J)/2));dsl("Letter=J");break; //'J'
      case 75:     convProgToArray(aIntCharMatrix,C_LET_K,(sizeof(C_LET_K)/2));dsl("Letter=K");break; //'K'
      case 76:     convProgToArray(aIntCharMatrix,C_LET_L,(sizeof(C_LET_L)/2));dsl("Letter=L");break; 
      case 77:     convProgToArray(aIntCharMatrix,C_LET_M,(sizeof(C_LET_M)/2));dsl("Letter=M");break; //'M'
      case 78:     convProgToArray(aIntCharMatrix,C_LET_N,(sizeof(C_LET_N)/2));dsl("Letter=N");break; //'N'
      case 79:     convProgToArray(aIntCharMatrix,C_LET_O,(sizeof(C_LET_O)/2));dsl("Letter=O");break; //'O'
      case 80:     convProgToArray(aIntCharMatrix,C_LET_P,(sizeof(C_LET_P)/2));dsl("Letter=P");break; //'P'
      case 81:     convProgToArray(aIntCharMatrix,C_LET_Q,(sizeof(C_LET_Q)/2));dsl("Letter=Q");break; //'Q'
      case 82:     convProgToArray(aIntCharMatrix,C_LET_R,(sizeof(C_LET_R)/2));dsl("Letter=R");break; //'R'
      case 83:     convProgToArray(aIntCharMatrix,C_LET_S,(sizeof(C_LET_S)/2));dsl("Letter=S");break; //'S'
      case 84:     convProgToArray(aIntCharMatrix,C_LET_T,(sizeof(C_LET_T)/2));dsl("Letter=T");break; //'T'
      case 85:     convProgToArray(aIntCharMatrix,C_LET_U,(sizeof(C_LET_U)/2));dsl("Letter=U");break; //'U'
      case 86:     convProgToArray(aIntCharMatrix,C_LET_V,(sizeof(C_LET_V)/2));dsl("Letter=V");break; //'V'
      case 87:     convProgToArray(aIntCharMatrix,C_LET_W,(sizeof(C_LET_W)/2));dsl("Letter=W");break; //'W'
      case 88:     convProgToArray(aIntCharMatrix,C_LET_X,(sizeof(C_LET_X)/2));dsl("Letter=X");break; //'X'
      case 89:     convProgToArray(aIntCharMatrix,C_LET_Y,(sizeof(C_LET_Y)/2));dsl("Letter=Y");break; //'Y'
      case 90:     convProgToArray(aIntCharMatrix,C_LET_Z,(sizeof(C_LET_Z)/2));dsl("Letter=Z");break; //'Z'
      case 97:     convProgToArray(aIntCharMatrix,C_LET_a,(sizeof(C_LET_a)/2));dsl("Letter=a");break; //'a'
      case 98:     convProgToArray(aIntCharMatrix,C_LET_b,(sizeof(C_LET_b)/2));dsl("Letter=b");break; //'b'
      case 99:     convProgToArray(aIntCharMatrix,C_LET_c,(sizeof(C_LET_c)/2));dsl("Letter=c");break; //'c'
      case 100:    convProgToArray(aIntCharMatrix,C_LET_d,(sizeof(C_LET_d)/2));dsl("Letter=d");break; //'d'
      case 101:    convProgToArray(aIntCharMatrix,C_LET_e,(sizeof(C_LET_e)/2));dsl("Letter=e");break; //'e'
      case 102:    convProgToArray(aIntCharMatrix,C_LET_f,(sizeof(C_LET_f)/2));dsl("Letter=f");break; //'f'
      case 103:    convProgToArray(aIntCharMatrix,C_LET_g,(sizeof(C_LET_g)/2));dsl("Letter=g");break; //'g'
      case 104:    convProgToArray(aIntCharMatrix,C_LET_h,(sizeof(C_LET_h)/2));dsl("Letter=h");break; //'h'
      case 105:    convProgToArray(aIntCharMatrix,C_LET_i,(sizeof(C_LET_i)/2));dsl("Letter=i");break; //'i'
      case 106:    convProgToArray(aIntCharMatrix,C_LET_j,(sizeof(C_LET_j)/2));dsl("Letter=j");break; //'j'
      case 107:    convProgToArray(aIntCharMatrix,C_LET_k,(sizeof(C_LET_k)/2));dsl("Letter=k");break; //'k'
      case 108:    convProgToArray(aIntCharMatrix,C_LET_l,(sizeof(C_LET_l)/2));dsl("Letter=l");break; 
      case 109:    convProgToArray(aIntCharMatrix,C_LET_m,(sizeof(C_LET_m)/2));dsl("Letter=m");break; //'m'
      case 110:    convProgToArray(aIntCharMatrix,C_LET_n,(sizeof(C_LET_n)/2));dsl("Letter=n");break; //'n'
      case 111:    convProgToArray(aIntCharMatrix,C_LET_o,(sizeof(C_LET_o)/2));dsl("Letter=o");break; //'o'
      case 112:    convProgToArray(aIntCharMatrix,C_LET_p,(sizeof(C_LET_p)/2));dsl("Letter=p");break; //'p'
      case 113:    convProgToArray(aIntCharMatrix,C_LET_q,(sizeof(C_LET_q)/2));dsl("Letter=q");break; //'q'
      case 114:    convProgToArray(aIntCharMatrix,C_LET_r,(sizeof(C_LET_r)/2));dsl("Letter=r");break; //'r'
      case 115:    convProgToArray(aIntCharMatrix,C_LET_s,(sizeof(C_LET_s)/2));dsl("Letter=s");break; //'s'
      case 116:    convProgToArray(aIntCharMatrix,C_LET_t,(sizeof(C_LET_t)/2));dsl("Letter=t");break; //'t'
      case 117:    convProgToArray(aIntCharMatrix,C_LET_u,(sizeof(C_LET_u)/2));dsl("Letter=u");break; //'u'
      case 118:    convProgToArray(aIntCharMatrix,C_LET_v,(sizeof(C_LET_v)/2));dsl("Letter=v");break; //'v'
      case 119:    convProgToArray(aIntCharMatrix,C_LET_w,(sizeof(C_LET_w)/2));dsl("Letter=w");break; //'w'
      case 120:    convProgToArray(aIntCharMatrix,C_LET_x,(sizeof(C_LET_x)/2));dsl("Letter=w");break; //'w'
      case 121:    convProgToArray(aIntCharMatrix,C_LET_y,(sizeof(C_LET_y)/2));dsl("Letter=y");break; //'y'
      case 122:    convProgToArray(aIntCharMatrix,C_LET_z,(sizeof(C_LET_z)/2));dsl("Letter=z");break; //'z':      
      case (-140): convProgToArray(aIntCharMatrix,C_LET_enie,(sizeof(C_LET_enie)/2));dsl("Letter=en");break; 
      case (-172): convProgToArray(aIntCharMatrix,C_LET_ENIE,(sizeof(C_LET_ENIE)/2));dsl("Letter=EN");break;       
      case (-156): convProgToArray(aIntCharMatrix,C_LET_aas,(sizeof(C_LET_aas)/2));dsl("Letter=l");break; 
      case (-148): convProgToArray(aIntCharMatrix,C_LET_eas,(sizeof(C_LET_eas)/2));dsl("Letter=l");break; 
      case (-144): convProgToArray(aIntCharMatrix,C_LET_ias,(sizeof(C_LET_ias)/2));dsl("Letter=l");break; 
      case (-138): convProgToArray(aIntCharMatrix,C_LET_oas,(sizeof(C_LET_oas)/2));dsl("Letter=l");break; 
      case (-131): convProgToArray(aIntCharMatrix,C_LET_uas,(sizeof(C_LET_uas)/2));dsl("Letter=l");break; 
      case (-188): convProgToArray(aIntCharMatrix,C_LET_Aas,(sizeof(C_LET_Aas)/2));dsl("Letter=l");break; 
      case (-180): convProgToArray(aIntCharMatrix,C_LET_Eas,(sizeof(C_LET_Eas)/2));dsl("Letter=l");break; 
      case (-176): convProgToArray(aIntCharMatrix,C_LET_Ias,(sizeof(C_LET_Ias)/2));dsl("Letter=l");break; 
      case (-170): convProgToArray(aIntCharMatrix,C_LET_Oas,(sizeof(C_LET_Oas)/2));dsl("Letter=l");break; 
      case (-163): convProgToArray(aIntCharMatrix,C_LET_Uas,(sizeof(C_LET_Uas)/2));dsl("Letter=l");break; 
      case   (44): convProgToArray(aIntCharMatrix,C_LET_coma,(sizeof(C_LET_coma)/2));dsl("Letter=l");break; 
      case   (46): convProgToArray(aIntCharMatrix,C_LET_punto,(sizeof(C_LET_punto)/2));dsl("Letter=l");break; 
      case   (95): convProgToArray(aIntCharMatrix,C_LET_barrinf,(sizeof(C_LET_barrinf)/2));dsl("Letter=l");break; 
      case   (45): convProgToArray(aIntCharMatrix,C_LET_barrmed,(sizeof(C_LET_barrmed)/2));dsl("Letter=l");break; 
      case (-127): convProgToArray(aIntCharMatrix,C_LET_sigPreAp,(sizeof(C_LET_sigPreAp)/2));dsl("Letter=l");break; 
      case   (63): convProgToArray(aIntCharMatrix,C_LET_sigPreCi,(sizeof(C_LET_sigPreCi)/2));dsl("Letter=l");break; 
      case (-157): convProgToArray(aIntCharMatrix,C_LET_sigExcAp,(sizeof(C_LET_sigExcAp)/2));dsl("Letter=l");break; 
      case   (33): convProgToArray(aIntCharMatrix,C_LET_sigExcCi,(sizeof(C_LET_sigExcCi)/2));dsl("Letter=l");break; 
      default:
 		    dsl("========================================================");
        dsl("==========Error=no encontrado el valor==================");
        dsl(character);
        dsl("========================================================");
    }
    //return vecTemp;
  //if(aChar[0]>35){
        /*dsl("================================================================");
        dsl("====getCharMatrix====Valor de cont en achar[0] exede el maximo==");
        //dsl(aChar[0]);
        dsl("================================================================");*/
  //}
}
#endif /* _INC_CONFIG_LETTERS_CPP_ */
/*
a 97 - b 98 - c 99 - d 100 - e 101 - f 102 - g 103 - h 104 - i 105 - j 106 - k 107 -
l 108 - m 109 - n 110 - o 111 - p 112 - q 113 - r 114 - s 115 - t 116 - u 117 -
v 118 - w 119 - x 120 - y 121 - z 122 -
A 65 - B 66 - C 67 - D 68 - E 69 - F 70 - G 71 - H 72 - I 73 - J 74 - K 75 - L 76 -
M 77 - N 78 - O 79 - P 80 - Q 81 - R 82 - S 83 - T 84 - U 85 - V 86 - W 87 - X 88 -
Y 89 - Z 90 - esp 32
1 49 - 2 50 - 3 51 - 4 52 - 5 53 - 6 54 - 7 55 - 8 56 - 9 57 - 0 48 -
-156 - -148 - -144 - -138 --131 - -188 - -180 - -176 - -170 - -163 - -140 - -172
�         �         �         �        �         �         �         �         �        �         �         �
*/