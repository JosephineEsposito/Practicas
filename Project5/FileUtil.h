#pragma once // -> to avoid including twice the same header


// F1 on FILE to open online official documentation
void* OpenFile(void* _sFile, const char* _sFilename, const char* _sMode);

bool CloseFile(void* _pFile);

unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile);
