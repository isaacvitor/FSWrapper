#ifndef FSWRAPPER_H
#define FSWRAPPER_H

class FSWrapper
{
  public:
      
      FSWrapper(bool verbose);
      FSWrapper();
      bool Open(void);
      void Format();
      bool isParameter(String name);
      void WriteParameter(String name, String content);
      String ReadParameter(String name);
      bool RemoveParameter(String name);

  private:
      String _parametersPath = "parameters/";
      bool _verbose = false;
      void println(String text);
      void print(String text);
};
#endif