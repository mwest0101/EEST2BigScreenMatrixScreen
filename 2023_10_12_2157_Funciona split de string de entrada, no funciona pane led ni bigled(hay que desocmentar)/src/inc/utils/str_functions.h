
#ifndef _INC_UTILS_STR_FUNCTIONS_H_
#define _INC_UTILS_STR_FUNCTIONS_H_

    void splitStringToArray(VectorClassString& dataArray, String inputString, String delimiter);
    void splitStringToArrayNoEmpty(VectorClassString& dataArray, String inputString, String delimiter);
    void stringTokeyAndValue(MatrixClassString& matStr, String inputString, String delimiter1, String delimiter2);
    void charReplace(char *str, char findChar, char replaceChar);
    void strReplace(String &str, const String &find, const String &replace);

#endif /* _INC_UTILS_STR_FUNCTIONS_H_ */