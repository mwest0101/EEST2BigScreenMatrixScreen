
#ifndef _INC_ANIM_MANAGER_H_
  #define _INC_ANIM_MANAGER_H_
  class AnimManager{
    private:
      
      int matrixCols=0;
      int contFrame=0;
      bool isEndOfAnim=true;
  
    public:        
      AnimManager();      
      void convProgToArrayByFrame(VectorClass &aFrame, const int *phrase, int size);
      void setIfisEnd(bool value);
      void reset();
      bool getIfAnimIsEnd();
      int getAnim(VectorClass &aFrame,String strOption);
    
      
  };
#endif /* _INC_ANIM_MANAGER_H_ */
