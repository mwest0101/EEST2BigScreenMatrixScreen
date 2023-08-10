#ifndef _INC_SHOW_MATRIX_H_
#define _INC_SHOW_MATRIX_H_
 


class ShowMatrix {
  private:
    int pin;

  public:
    ShowMatrix(int pinNumber);
    void PrintData(int pinNumber);
    
     
};


#endif /* _INC_SHOW_MATRIX_H_ */