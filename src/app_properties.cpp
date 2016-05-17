#include "app_properties.h"
#include <QString>
#include "filesystem.h"
#include <QDir>

const QString AppProrepties::_appVersion = "0.7";

const QStringList AppProrepties::_supportedFormats = QStringList() << "*.jpg" << "*.bmp"
                                                               << "*.png" << "*jpeg"
                                                               << "*.gif";

const QString AppProrepties::_name = "Image viewer";

QString AppProrepties::_lastWorkDirectory = QDir::homePath() + "/Pictures";

const QString AppProrepties::_tempLocation = QDir::tempPath() + "/image_viewer_tmp";

void AppProrepties::changeLastWorkDirectory(const QString &directory)
{
    _lastWorkDirectory = FileSystem::absoluteFilePath(directory);
}
