
#ifndef _INC_PROGMEM_MANAGER_H_
#define _INC_PROGMEM_MANAGER_H_


  class ProgmemManager{
    private:
      
      int contFrame=0;
      bool isEndOfAnim=false;

       
    public:        
        ProgmemManager();
      
        void convProgToArray(VectorClass &aIntCharMatrix,const int *phrase, int size);
        void convProgToArrayByFrame(VectorClass &aFrame,const int *phrase, int size);
        void setIfisEnd(bool value);
        void reset();
        bool getIfisEnd();
  };
#endif /* _INC_PROGMEM_MANAGER_H_ */
