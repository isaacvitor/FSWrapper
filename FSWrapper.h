#ifndef FSWrapper_h
#define FSWrapper_h

class FSWrapper
{
public:
    
    void FSWrapper(bool verbose);
    bool Open(void);

    void Format();

    bool isParameter(String name);

    void WriteParameter(String name, String content);

    String ReadParameter(String name);

    bool RemoveParameter(String name);

private:
    String parametersPath = "parameters/";
    bool verbose = true;

    void println(String text)
    {
        if (verbose)
        {
            Serial.println("\nFSWrapper - " + text);
        }
    }

    void print(String text)
    {
        if (verbose)
        {
            Serial.print("\nFSWrapper - " + text);
        }
    }
}
#endif