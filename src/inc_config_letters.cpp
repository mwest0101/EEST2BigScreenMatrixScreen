#include "inc_include.h"

#ifndef _INC_CONFIG_LETTERS_CPP_
#define _INC_CONFIG_LETTERS_CPP_

int calcNumberOfChar(char caracter){
    int charVal=0;
    int valRet=0;
    int valorCaracter = (int)caracter;  // Convertir el carácter a su valor numérico

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
      debug("--------------------------------------------------");
      debug("Error valRet");
      debug("valRet=");
      debugl(valRet);
    }
    if(valRet!=0){
      debugl(" ");
      debug("[");
      debug(caracter);
      debug(" (");
      debug(valRet);
      debug(") ]");
      //charVal=0;
    }   
    return valRet;       
}
 VectorClass getCharMatrix(int character){
  //VectorClass aChar(VECTOR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  
  debugl("");
  debug("getCharMatrix: (");
  debug(character);
  debug(" : ");
  VectorClass vecTemp(1, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE); // Declarar y asignar un valor por defecto

    switch (character) {
      case 32:     vecTemp=convProgToArray(C_LET_ESP,(sizeof(C_LET_ESP)/2));debug("_");break; //' ' Espacio      
      case 48:     vecTemp=convProgToArray(C_LET_0,(sizeof(C_LET_0)/2));debug('0');break; //'0'
      case 49:     vecTemp=convProgToArray(C_LET_1,(sizeof(C_LET_1)/2));debug('1');break; //'1'
      case 50:     vecTemp=convProgToArray(C_LET_2,(sizeof(C_LET_2)/2));debug('2');break; //'2'
      case 51:     vecTemp=convProgToArray(C_LET_3,(sizeof(C_LET_3)/2));debug('3');break; //'3'
      case 52:     vecTemp=convProgToArray(C_LET_4,(sizeof(C_LET_4)/2));debug('4');break; //'4'
      case 53:     vecTemp=convProgToArray(C_LET_5,(sizeof(C_LET_5)/2));debug('5');break; //'5'
      case 54:     vecTemp=convProgToArray(C_LET_6,(sizeof(C_LET_6)/2));debug('6');break; //'6'
      case 55:     vecTemp=convProgToArray(C_LET_7,(sizeof(C_LET_7)/2));debug('7');break; //'7'
      case 56:     vecTemp=convProgToArray(C_LET_8,(sizeof(C_LET_8)/2));debug('8');break; //'8'
      case 57:     vecTemp=convProgToArray(C_LET_9,(sizeof(C_LET_9)/2));debug('9');break; //'9' 
      case 65:     vecTemp=convProgToArray(C_LET_A,(sizeof(C_LET_A)/2));debug('A');break; //'A'
      case 66:     vecTemp=convProgToArray(C_LET_B,(sizeof(C_LET_B)/2));debug('B');break; //'B'
      case 67:     vecTemp=convProgToArray(C_LET_C,(sizeof(C_LET_C)/2));debug('C');break; //'C'
      case 68:     vecTemp=convProgToArray(C_LET_D,(sizeof(C_LET_D)/2));debug('D');break; //'D'
      case 69:     vecTemp=convProgToArray(C_LET_E,(sizeof(C_LET_E)/2));debug('E');break; //'E'
      case 70:     vecTemp=convProgToArray(C_LET_F,(sizeof(C_LET_F)/2));debug('F');break; //'F'
      case 71:     vecTemp=convProgToArray(C_LET_G,(sizeof(C_LET_G)/2));debug('G');break; //'G'
      case 72:     vecTemp=convProgToArray(C_LET_H,(sizeof(C_LET_H)/2));debug('H');break; //'H'
      case 73:     vecTemp=convProgToArray(C_LET_I,(sizeof(C_LET_I)/2));debug('I');break; //'I'
      case 74:     vecTemp=convProgToArray(C_LET_J,(sizeof(C_LET_J)/2));debug('J');break; //'J'
      case 75:     vecTemp=convProgToArray(C_LET_K,(sizeof(C_LET_K)/2));debug('K');break; //'K'
      case 76:     vecTemp=convProgToArray(C_LET_L,(sizeof(C_LET_L)/2));debug('L');break; //'L'
      case 77:     vecTemp=convProgToArray(C_LET_M,(sizeof(C_LET_M)/2));debug('M');break; //'M'
      case 78:     vecTemp=convProgToArray(C_LET_N,(sizeof(C_LET_N)/2));debug('N');break; //'N'                                                                            
      case 79:     vecTemp=convProgToArray(C_LET_O,(sizeof(C_LET_O)/2));debug('O');break; //'O'
      case 80:     vecTemp=convProgToArray(C_LET_P,(sizeof(C_LET_P)/2));debug('P');break; //'P'
      case 81:     vecTemp=convProgToArray(C_LET_Q,(sizeof(C_LET_Q)/2));debug('Q');break; //'Q'
      case 82:     vecTemp=convProgToArray(C_LET_R,(sizeof(C_LET_R)/2));debug('R');break; //'R'
      case 83:     vecTemp=convProgToArray(C_LET_S,(sizeof(C_LET_S)/2));debug('S');break; //'S'
      case 84:     vecTemp=convProgToArray(C_LET_T,(sizeof(C_LET_T)/2));debug('T');break; //'T'
      case 85:     vecTemp=convProgToArray(C_LET_U,(sizeof(C_LET_U)/2));debug('U');break; //'U'
      case 86:     vecTemp=convProgToArray(C_LET_V,(sizeof(C_LET_V)/2));debug('V');break; //'V'
      case 87:     vecTemp=convProgToArray(C_LET_W,(sizeof(C_LET_W)/2));debug('W');break; //'W'
      case 88:     vecTemp=convProgToArray(C_LET_X,(sizeof(C_LET_X)/2));debug('X');break; //'X'
      case 89:     vecTemp=convProgToArray(C_LET_Y,(sizeof(C_LET_Y)/2));debug('Y');break; //'Y'
      case 90:     vecTemp=convProgToArray(C_LET_Z,(sizeof(C_LET_Z)/2));debug('Z');break; //'Z'
      case 97:     vecTemp=convProgToArray(C_LET_a,(sizeof(C_LET_a)/2));debug('a');break; //'a'
      case 98:     vecTemp=convProgToArray(C_LET_b,(sizeof(C_LET_b)/2));debug('b');break; //'b'
      case 99:     vecTemp=convProgToArray(C_LET_c,(sizeof(C_LET_c)/2));debug('c');break; //'c'
      case 100:    vecTemp=convProgToArray(C_LET_d,(sizeof(C_LET_d)/2));debug('d');break; //'d'
      case 101:    vecTemp=convProgToArray(C_LET_e,(sizeof(C_LET_e)/2));debug('e');break; //'e'
      case 102:    vecTemp=convProgToArray(C_LET_f,(sizeof(C_LET_f)/2));debug('f');break; //'f'
      case 103:    vecTemp=convProgToArray(C_LET_g,(sizeof(C_LET_g)/2));debug('g');break; //'g'
      case 104:    vecTemp=convProgToArray(C_LET_h,(sizeof(C_LET_h)/2));debug('h');break; //'h'
      case 105:    vecTemp=convProgToArray(C_LET_i,(sizeof(C_LET_i)/2));debug('i');break; //'i'
      case 106:    vecTemp=convProgToArray(C_LET_j,(sizeof(C_LET_j)/2));debug('j');break; //'j'
      case 107:    vecTemp=convProgToArray(C_LET_k,(sizeof(C_LET_k)/2));debug('k');break; //'k'
      case 108:    vecTemp=convProgToArray(C_LET_l,(sizeof(C_LET_l)/2));debug('l');break; //'l'
      case 109:    vecTemp=convProgToArray(C_LET_m,(sizeof(C_LET_m)/2));debug('m');break; //'m'
      case 110:    vecTemp=convProgToArray(C_LET_n,(sizeof(C_LET_n)/2));debug('n');break; //'n'                                                                         
      case 111:    vecTemp=convProgToArray(C_LET_o,(sizeof(C_LET_o)/2));debug('o');break; //'o'
      case 112:    vecTemp=convProgToArray(C_LET_p,(sizeof(C_LET_p)/2));debug('p');break; //'p'
      case 113:    vecTemp=convProgToArray(C_LET_q,(sizeof(C_LET_q)/2));debug('q');break; //'q'
      case 114:    vecTemp=convProgToArray(C_LET_r,(sizeof(C_LET_r)/2));debug('r');break; //'r'
      case 115:    vecTemp=convProgToArray(C_LET_s,(sizeof(C_LET_s)/2));debug('s');break; //'s'
      case 116:    vecTemp=convProgToArray(C_LET_t,(sizeof(C_LET_t)/2));debug('t');break; //'t'
      case 117:    vecTemp=convProgToArray(C_LET_u,(sizeof(C_LET_u)/2));debug('u');break; //'u'
      case 118:    vecTemp=convProgToArray(C_LET_v,(sizeof(C_LET_v)/2));debug('v');break; //'v'
      case 119:    vecTemp=convProgToArray(C_LET_w,(sizeof(C_LET_w)/2));debug('w');break; //'w'
      case 120:    vecTemp=convProgToArray(C_LET_x,(sizeof(C_LET_x)/2));debug('w');break; //'w'
      case 121:    vecTemp=convProgToArray(C_LET_y,(sizeof(C_LET_y)/2));debug('y');break; //'y'
      case 122:    vecTemp=convProgToArray(C_LET_z,(sizeof(C_LET_z)/2));debug('z');break; //'z'
      case (-156): vecTemp=convProgToArray(C_LET_a,(sizeof(C_LET_a)/2));debug("as");break; //'á'
      case (-148): vecTemp=convProgToArray(C_LET_e,(sizeof(C_LET_e)/2));debug("es");break; //'é'
      case (-144): vecTemp=convProgToArray(C_LET_i,(sizeof(C_LET_i)/2));debug("is");break; //'í'
      case (-138): vecTemp=convProgToArray(C_LET_o,(sizeof(C_LET_o)/2));debug("os");break; //'ó'
      case (-131): vecTemp=convProgToArray(C_LET_u,(sizeof(C_LET_u)/2));debug("us");break; //'ú'
      case (-140): vecTemp=convProgToArray(C_LET_enie,(sizeof(C_LET_enie)/2));debug("en");break; //'ñ'
      case (-188): vecTemp=convProgToArray(C_LET_A,(sizeof(C_LET_A)/2));debug("AS");break; //'Á'
      case (-180): vecTemp=convProgToArray(C_LET_E,(sizeof(C_LET_E)/2));debug("ES");break; //'É'
      case (-176): vecTemp=convProgToArray(C_LET_I,(sizeof(C_LET_I)/2));debug("IS");break; //'Í'
      case (-170): vecTemp=convProgToArray(C_LET_O,(sizeof(C_LET_O)/2));debug("OS");break; //'Ó'
      case (-163): vecTemp=convProgToArray(C_LET_U,(sizeof(C_LET_U)/2));debug("US");break; //'Ú'      
      case (-172): vecTemp=convProgToArray(C_LET_ENIE,(sizeof(C_LET_ENIE)/2));debug("EN");break; //'Ñ'
      default:
 		    debugl("========================================================");
        debugl("==========Error=no encontrado el valor==================");
        debugl(character);
        debugl("========================================================");
        
    }   
    return vecTemp;
    
  
  
  //if(aChar[0]>35){
        /*debugl("================================================================");
        debugl("====getCharMatrix====Valor de cont en achar[0] exede el maximo==");
        //debugl(aChar[0]);
        debugl("================================================================");*/
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

� -156 - � -148 - � -144 - � -138 - � -131 - � -188 - � -180 - � -176 - � -170 - � -163 - � -140 - � -172
á         é         í         ó        ú         Á         É         Í         Ó        Ú         ñ         Ñ
*/