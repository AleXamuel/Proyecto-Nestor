static int[] table(String pattern){
    int size=pattern.length();
    int APL=0;
    int[] table=new int[size];
    if(size==1)
        return table;
    for(int i=1;i<size;i++){
        while(APL>0 && pattern.charAt(APL)!= pattern.charAt(i))
            APL=table[APL-1];
        if(pattern.charAt(APL)==pattern.charAt(i))
            APL++;
        table[i]=APL;
    }
    return table;
}
static LinkedList<Integer> KMP(String text, String pattern){
  int[] table=table(pattern);
  LinkedList<Integer> res=new LinkedList<>();
  int textSize=text.length();
  int patternSize= pattern.length();
  int index=0;
  int strIndex=0;
  int patIndex=0;
  while((textSize-index)>patternSize){
      while(patIndex<patternSize && text.charAt(strIndex)==pattern.charAt(patIndex)){
          strIndex++;
          patIndex++;
      }
      if(patIndex>=patternSize)
          res.add(index);

      if(patIndex>0&&table[patIndex-1]>0){
          index=strIndex-table[patIndex-1];
          patIndex=table[patIndex-1];
      }
      else{
          if(strIndex==index)
              strIndex++;
          index=strIndex;
          if(patIndex>0)
              patIndex=table[patIndex-1];
      }

  }
  index=textSize-patternSize;
  int c=0;
  for (int i = 0; i < patternSize; i++) {
      if(text.charAt(index+i)==pattern.charAt(i))
          c++;
  }
  if(c==patternSize)
      res.add(index);
  return  res;
}
