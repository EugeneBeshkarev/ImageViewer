#include "app_properties.h"

AppProrepties::AppProrepties() : appVersion("0.7")
{}

QString AppProrepties::version()
{
    return appVersion;
}