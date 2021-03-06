#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <memory>

//#include "config.h"

class QAction;
class TabController;
class QStringList;
class QToolBar;
class FileSystem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent, const QString &file);
    ~MainWindow();

    MainWindow(const MainWindow &) = delete;
    MainWindow &operator =(const MainWindow &) = delete;
    MainWindow(MainWindow &&) = delete;

private:
    void createMainWindow();
    void createActions();
    void createMenu();
    QToolBar *createToolBar();
    void createConnectToSlots();
    void showStatusBarMessage(const QString &message);
    void updateListRecentFiles();
private slots:
    void newTab();
    void openFile();
    void saveFile();
    void saveAs();
    void print();
    void nextFile();
    void previousFile();
    void closeFileRequest();
    void closeTabRequest();
    void openRecentFile();
    void horizontalFlip();
    void verticalFlip();
    void clockwiseRotate();
    void counterClockwiseRotate();
    void zoomInImage();
    void zoomOutImage();
    void fitImageRequest();

    void aboutApp();

    void checkTabState();
protected:
    void closeEvent(QCloseEvent *) override;
    void resizeEvent(QResizeEvent *) override;

private:

    void loadFileRequest(const QString &file);
    void setButtonsEnabled(bool openButt, bool imageIsLoad,
                           bool fileMayBeSaved = false,
                           bool fileInTabIsChanged = false);

    TabController *_pTabController;
    FileSystem *_pFileSystem;

    QMenu *_pFileMenu;
    QMenu *_pEditMenu;
    QMenu *_pViewMenu;
    QMenu *_pHelpMenu;
    QAction *_pNewTabAction;
    QAction *_pOpenAction;
    QAction *_pSaveAction;
    QAction *_pSaveAsAction;
    QAction *_pPrintAction;
    QAction *_pNextFileAction;
    QAction *_pPreviousFileAction;
    QAction *_pCloseFileAction;
    QAction *_pCloseTabAction;
    constexpr static qint32 maxRecentFiles{5};
    QVector<QAction*> _pRecentAction{maxRecentFiles};
    QAction *_pSeparatorAction;
    QAction *_pExitAction;

    QAction *_pVerticalFlipAction;
    QAction *_pHorizontalFlipAction;
    QAction *_pClockwiseRotateAction;
    QAction *_pCounterClockwiseRotateAction;
    QAction *_pFitAction;
    QAction *_pZoomInAction;
    QAction *_pZoomOutAction;

    QAction *_pAboutAction;
    QAction *_pQtAbout;

    QToolBar *_pToolBar;
};

#endif // MAINWINDOW_H
