#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QString>
#include <QNetworkAccessManager>
#include <QProcess>
#include "Settings.h"
#include "Device.h"
#include "Console.h"
#include "include/libusb-1.0/libusb.h"

#ifdef _WIN32
#include <windows.h>
#include <QWinTaskbarButton>
#else
#include <unistd.h>
#endif

class Gui:public QWidget
{
  Q_OBJECT Settings * settings;
  Console *console;
  Device *device;
  QGridLayout *grid;
  QVBoxLayout *left;
  QVBoxLayout *right;
  QVBoxLayout *center;
  QHBoxLayout *down;
  QString path;
  #if defined (_WIN32)
    QWinTaskbarButton *winTaskbar;
  #endif
  QLabel *image;
  QPixmap *logo;
  QPushButton *cancel_btn;
  QPushButton *status_btn;
  QPushButton *rflash_btn;
  QPushButton *wflash_btn;
  QPushButton *rram_btn;
  QPushButton *wram_btn;
  QPushButton *eflash_btn;
  QPushButton *eram_btn;


public:
    Gui (QWidget * parent = nullptr);

  QProgressBar *progress;
  public slots:void startup_info (void);
  void setEnabledButtons (bool stan);
  void setRamButtons ();
  void write_flash (void);
  void read_flash (void);
  void write_ram (void);
  void show_info (void);
  void erase_flash (void);
  void erase_ram (void);
  void setProgress (int ile, int max);
  void exit();
};

