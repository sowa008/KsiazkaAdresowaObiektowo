#include "MetodyPomocnicze.h"
#include "UzytkownikManager.h"

string MetodyPomocnicze :: konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

