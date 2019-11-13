#include "FS.h"

class FSWrapper
{
public:
    static bool verbose = true;

    static bool Open(void)
    {
        if (!SPIFFS.begin())
        {
            println("Open File System Error");
            return false;
        }
        else
        {
            println("File System Opened");
            return true;
        }
    }

    static void Format()
    {
        SPIFFS.format();
    }

    static bool isParameter(String name)
    {
        return SPIFFS.exists(parametersPath + name);
    }

    static void WriteParameter(String name, String content)
    {
        File tempFile = SPIFFS.open(parametersPath + name, "w+");
        if (!tempFile)
        {
            println("WriteParameter - Open File Error");
        }
        else
        {
            tempFile.println(content);
            println("Parameter Saved");
        }
        tempFile.close();
    }

    static String ReadParameter(String name)
    {
        if (SPIFFS.exists(parametersPath + name))
        {
            File tempFile = SPIFFS.open(parametersPath + name, "r");
            if (!tempFile)
            {
                println("ReadParameter - Open File Error");
            }
            String parameter = tempFile.readStringUntil('\r');
            tempFile.close();
            return parameter;
        }
        else
        {
            return "";
        }
    }

    static bool RemoveParameter(String name)
    {
        Serial.println(parametersPath + name);
        if (SPIFFS.exists(parametersPath + name))
        {
            return SPIFFS.remove(parametersPath + name);
        }
    }

private:
    String parametersPath = "parameters/";
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