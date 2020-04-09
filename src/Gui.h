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
#include <stdio.h>
#include <sstream>

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

  QString HexA;
  QString HexB;
  QString HexC;
  unsigned int A;
  unsigned int B;
  unsigned int C;
  unsigned char buffer[64];
  unsigned char *version [0x00];
  unsigned char idBuffer[64];
  unsigned char HexID = 0x80;
  unsigned char rHeader1[64];
  unsigned char rHeader2[64];
  unsigned char rHeader3[64];
  unsigned char gbaHeader[64];
  std::stringstream AStream;
  std::stringstream BStream;
  std::stringstream CStream;
  std::stringstream header;
  std::stringstream gbaheader;
  QString hex;


public:
    Gui (QWidget * parent = nullptr);

    QProgressBar *progress;
    uint genkey(uint did[]);
    void main_BV_SetBank(unsigned char blk, unsigned char sublk);
    void main_readCartHeader();
    void main_ROMBankSwitch(int bank);
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

