#ifndef FILESYSTEM
#define FILESYSTEM

#include <QHash>
#include <memory>
#include <QObject>

class QString;
class QWidget;
class TabController;
class Entry;

class FileSystem : public QObject
{
    Q_OBJECT

    FileSystem(QObject *parent = nullptr);

public:
    ~FileSystem();
    FileSystem(const FileSystem &) = delete;
    FileSystem &operator = (const FileSystem &) = delete;

public:
    static FileSystem *instance();
    static QString absoluteFilePath(const QString &dir);
    static QString fileName(const QString &file);

    QString openFile();
    QString nextFile();
    QString previousFile();
    bool saveFile();
    bool saveAs();

private slots:
    void destroyEntry(QWidget *widg);

private:
    static FileSystem *_pInstance;
    std::unique_ptr<TabController> _pTabs;

    void setWorkDirectory(const QString &directory);
    void createEntry(const QString &dir);
    bool entryIsExist(const QString &dir) const;
    void checkSelectedFileIsSupported(const QString &selectedFile) const;

    QString getCurrentAbsoluteFileName();
    bool saveToDisk(const QString &locationForSaving);

    QHash<QString, QWidget*> _directories;
    QHash<QWidget*, Entry> _entries;
};

#endif
