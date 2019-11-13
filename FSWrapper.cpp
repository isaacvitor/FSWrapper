#include "FS.h"
#include "FSWrapper.h

void FSWrapper::FSWrapper(bool verbose){
    this->verbose = verbose;
    this->Open();
}
bool FSWrapper::Open(void)
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

void FSWrapper::Format()
{
    SPIFFS.format();
}

bool FSWrapper::isParameter(String name)
{
    return SPIFFS.exists(parametersPath + name);
}

void FSWrapper::WriteParameter(String name, String content)
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

String FSWrapper::ReadParameter(String name)
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

bool FSWrapper::RemoveParameter(String name)
{
    Serial.println(parametersPath + name);
    if (SPIFFS.exists(parametersPath + name))
    {
        return SPIFFS.remove(parametersPath + name);
    }
}
