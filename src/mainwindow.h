#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class TabController;
class QStringList;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void createActions();
    void createMenu();
    void createToolBar();
    void createConnectToSlots();
    void setRecentFile(const QString &filename);
    void updateListRecentFiles();
    void entryList();
    QString getAbsolutePathToFile(const QString &file);
    void fileForLoad(const QString &file);
private slots:
    void newTab();
    void openFile();
    void saveFile();
    void saveAs();
    void nextFile();
    void previousFile();
    void closeFileRequest();
    qint32 closeTabRequest();
    void openRecentFile();
    void horizontalFlip();
    void clockwiseRotate();
    void counterClockwiseRotate();
    void zoomInImage();
    void zoomOutImage();
    void fitImageRequest();

    void aboutApp();
protected:
    void closeEvent(QCloseEvent *);
private:

    void loadFileRequest(const QString &file);

    TabController *_pTabController;
    QStringList recentFile;
    QStringList filesList;
    QStringList::const_iterator it;
    enum{maxRecentFile = 5};

    QMenu *_pFileMenu;
    QMenu *_pEditMenu;
    QMenu *_pViewMenu;
    QMenu *_pHelpMenu;
    QAction *_pNewTabAction;
    QAction *_pOpenAction;
    QAction *_pSaveAction;
    QAction *_pSaveAsAction;
    QAction *_pNextFileAction;
    QAction *_pPreviousFileAction;
    QAction *_pCloseFileAction;
    QAction *_pCloseTabAction;
    QAction *_pRecentAction[maxRecentFile];
    QAction *_pSeparatorAction;
    QAction *_pExitAction;

    QAction *_pHorizontalFlipAction;
    QAction *_pClockwiseRotateAction;
    QAction *_pCounterClockwiseRotateAction;
    QAction *_pFitAction;
    QAction *_pNormalSizeAction;
    QAction *_pZoomIn;
    QAction *_pZoomOut;

    QAction *_pAboutAction;
    QAction *_pQtAbout;

    QToolBar *_pToolBar;


};

#endif // MAINWINDOW_H