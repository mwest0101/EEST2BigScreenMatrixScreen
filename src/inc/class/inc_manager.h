
#ifndef _INC_MANAGER_H_
  #define _INC_MANAGER_H_
  class Manager{
    private:
      
      int stateAction=0;
      int contParam=0;
      //VectorClassString vecStrOne
      VectorClassString vecStrOne= VectorClassString(0);
      VectorClassString vecStrParam= VectorClassString(0);
      VectorClassString vecStr= VectorClassString(0);
//      vecStr

    public:        
      Manager();      
      void getAction(String InString);
      //void proccesAction(VectorClassString &vecStrParam,VectorClassString &vecStrOne);
      //void setProccesAndParameters(VectorClassString &vecStrOne);

    
      
  };
#endif /* _INC_MANAGER_H_ */
