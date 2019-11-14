#include "FS.h"
#include "FSWrapper.h"

FSWrapper::FSWrapper(bool verbose){
    _verbose = verbose;
    Open();
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
    return SPIFFS.exists(_parametersPath + name);
}

void FSWrapper::WriteParameter(String name, String content)
{
    File tempFile = SPIFFS.open(_parametersPath + name, "w+");
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
    if (SPIFFS.exists(_parametersPath + name))
    {
        File tempFile = SPIFFS.open(_parametersPath + name, "r");
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
    Serial.println(_parametersPath + name);
    if (SPIFFS.exists(_parametersPath + name))
    {
        return SPIFFS.remove(_parametersPath + name);
    }
}

void FSWrapper::println(String text)
{
    if (_verbose)
    {
        Serial.println("\nFSWrapper - " + text);
    }
}

void FSWrapper::print(String text)
{
    if (_verbose)
    {
        Serial.print("\nFSWrapper - " + text);
    }
}