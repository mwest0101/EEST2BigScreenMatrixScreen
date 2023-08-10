#ifndef _INC_DRIVE_MATRIX_H_
#define _INC_DRIVE_MATRIX_H_
 


class DriveMatrix {
  private:
    int pin;

  public:
    DriveMatrix(int pinNumber);
    void Print();    
};

#endif /* _INC_DRIVE_MATRIX_H_ */
